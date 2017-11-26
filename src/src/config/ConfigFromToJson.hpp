//
// Created by rubienr on 23/11/17.
//

#pragma once

#include <inttypes.h>
#include <ArduinoJson.h>

/**
 * Structure representing a flat json value entry (no nested json object).
 * \tparam ValueType_t value type as seen in source
 * \tparam JsonValueType_t value type as seen in json file, e.g. source = bool, config = int
 */
template<typename ValueType, typename JsonValueType = ValueType>
struct FromToJsonField
{
public:

    typedef ValueType     value_type;
    typedef JsonValueType value_json_type;

    /**
     * Constructs a field representing a flat json value entry.
     * \param name parameter name as seen in json
     * \param valueLength length of the value string as seen in json (excl. "" if string)
     */
    FromToJsonField(const String& name, const uint8_t valueLength = 1) :
        name(name),
        length(strlen(name.c_str()) + valueLength),
        value()
    {
    }

    /**
     * the json value name
     */
    const String  name;
    /**
     * The string length to reserve in buffer; see also:
     * http://arduinojson.org/assistant/
     * http://platformio.org/lib/show/64/ArduinoJson/examples
     */
    const uint8_t length;
    /**
     * the json value
     */
    ValueType     value;
};

/**
 * Classes to derive from if new types are to be used with composition.
 * @{
 */
typedef FromToJsonField<int8_t>   Int8FromToJsonField;
typedef FromToJsonField<uint8_t>  Uint8FromToJsonField;
typedef FromToJsonField<uint16_t> Uint16FromToJsonField;
typedef FromToJsonField<String>   StringFromToJsonField;
typedef FromToJsonField<bool>     BoolFromToJsonField;
/**
 * @}
 */

/**
 * Base class of field composition. This class keeps no field at all but serves some stubs.
 * \tparam FieldTypes
 */
template<typename... FieldTypes>
class FromToJsonCompositum
{
private:

protected:

public:
    static const uint8_t ItemId;

    JsonObject& jsonObject;

    FromToJsonCompositum(JsonObject& jsonObject) :
        jsonObject(jsonObject)
    {
    }

    bool flushToJson()
    {
        return true;
    }

    void flushFromJson()
    {
    }

    void fromJson()
    {
    }

    bool toJson()
    {
        true;
    }

    void getField()
    {
    }

    constexpr uint8_t stringLength() const
    {
        return 26;
    }
};

template<typename... FieldTypes>
const uint8_t FromToJsonCompositum<FieldTypes...>::ItemId = 0;

/**
 * Composition of fields by inheritance. First type argument is reflected by the most specialized class,
 * whereas last type argument by the base class.
 * \tparam FieldType unpacked field in the current unpack/inheritance recursion
 * \tparam FieldTypes remaining fields to unpack recursively
 */
template<typename FieldType, typename ... FieldTypes>
class FromToJsonCompositum<FieldType, FieldTypes...> :
    public FromToJsonCompositum<FieldTypes...>
{
private:

protected:
public:

    FieldType item;

    typedef typename FieldType::value_json_type value_json_type;
    typedef typename FieldType::value_type      value_type;

    static const uint8_t ItemId;

    using FromToJsonCompositum<FieldTypes...>::flushFromJson;
    using FromToJsonCompositum<FieldTypes...>::flushToJson;
    using FromToJsonCompositum<FieldTypes...>::fromJson;
    using FromToJsonCompositum<FieldTypes...>::toJson;
    using FromToJsonCompositum<FieldTypes...>::getField;
    using FromToJsonCompositum<FieldTypes...>::jsonObject;

    FromToJsonCompositum(JsonObject& jsonObject) :
        FromToJsonCompositum<FieldTypes...>::FromToJsonCompositum(jsonObject)
    {
    }

    /**
     * Example:
     * Compositum<T, Ts...> instance
     * instance.fromJson<\tparam ExpectedFieldType>()
     * \tparam ExpectedFieldType a type as specified in template pack
     * \return the value as read from json
     */
    template<typename ExpectedFieldType>
    const typename std::enable_if<
        std::is_same<ExpectedFieldType, FieldType>::value,
        value_type>::type& fromJson()
    {
        item.value = jsonObject.template get<value_json_type>(item.name);
        return item.value;
    }

    /**
     * Example:
     * Compositum<T, Ts...> instance
     * instance.toJson<\tparam ExpectedFieldType>()
     * \tparam ExpectedFieldType a type as specified in template pack
     * \return false on error, true otherwise
     */
    template<typename ExpectedFieldType>
    typename std::enable_if<
        std::is_same<ExpectedFieldType, FieldType>::value,
        bool>::type toJson()
    {
        return jsonObject.template set<value_json_type>(item.name, item.value);
    }

    /**
     * Example:
     * Compositum<T, Ts...> instance
     * instance.getField<\tparam ExpectedFieldType>()
     * \tparam ExpectedFieldType a type as specified in template pack
     * \return the respective field
     */
    template<typename ExpectedFieldType>
    typename std::enable_if<
        std::is_same<ExpectedFieldType, FieldType>::value,
        FieldType>::type& getField()
    {
        return item;
    }

    /**
     * Accumulates the string lengths of each field which is needed for the json buffer.
     * \return the total field length to reserve in the buffer
     */
    constexpr uint8_t stringLength() const
    {
        return item.length + FromToJsonCompositum<FieldTypes...>::stringLength();
    }

    /**
     * Flush this data and the data of all parent classes/fields to json buffer.
     * Interrupts on first error.
     * \return true if all data is flushed, false otherwise
     */
    bool flushToJson()
    {
        if (!this->toJson<FieldType>())
        {
            return false;
        }
        return FromToJsonCompositum<FieldTypes...>::flushToJson();
    }

    /**
     * Flush json buffer to this data and the data of all parent classes/fields.
     * Interrupts on first error.
     * \return true if all data is flushed, false otherwise
     */
    void flushFromJson()
    {
        this->fromJson<FieldType>();
        FromToJsonCompositum<FieldTypes...>::flushFromJson();
    }
};

/**
 * The item id corresponds to the depth of the composition inheritance which starts
 * with 0 at the base class.
 * \tparam FieldType unpacked field in the current unpack/inheritance recursion
 * \tparam FieldTypes remaining fields to unpack recursively
 */
template<typename FieldType, typename ...FieldTypes>
const uint8_t FromToJsonCompositum<FieldType, FieldTypes...>::ItemId =
                  1 + FromToJsonCompositum<FieldTypes...>::ItemId;

/**
 *
 * \tparam FieldTypes The fields to read/write from/to json.
 */
template<typename... FieldTypes>
class FromToJson
{
public:

    typedef FromToJsonCompositum<FieldTypes...> DataCompositum;

private:

    DynamicJsonBuffer jsonBuffer;
    JsonObject& jsonRoot;
protected:

public:

    /**
     * Compositum keeping all instantiated template types.
     */
    DataCompositum data;

    static uint8_t itemsCount()
    {
        return DataCompositum::ItemId;
    }

    FromToJson() :
        jsonBuffer(DataCompositum::ItemId + data.stringLength()),
        jsonRoot(jsonBuffer.createObject()),
        data(jsonRoot)
    {
    }

    /**
     * flush content of @xrefitem data to json buffer @xrefitem jsonRoot
     */
    void toJson()
    {
        data.flushToJson();
    }

    /**
     * flush content of json buffer @xrefitem jsonRoot to @xrefitem data
     */
    void fromJson()
    {
        data.flushFromJson();
    }
};
