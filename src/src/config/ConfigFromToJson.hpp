//
// Created by rubienr on 23/11/17.
//

#pragma once

#include <inttypes.h>

class Print;

/**
 *
 * \tparam ValueType the value type as seen in source
 * \tparam JsonValueType the value type as seen in json file, e.g. source = bool, config = int
 */
template<typename ValueType, typename JsonValueType = ValueType>
struct FromToJsonField
{

    FromToJsonField(String valueName) :
        valueName(valueName)
    {
    }

    ValueType    value;
    const String valueName;
};

typedef FromToJsonField<int8_t>        Int8FromToJsonField;
typedef FromToJsonField<uint8_t>       Uint8FromToJsonField;
typedef FromToJsonField<String, char*> StringFromToJsonField;
typedef FromToJsonField<bool>          BoolFromToJsonField;
typedef FromToJsonField<bool, int8_t>  TristateBoolFromToJsonField;

template<typename ... FieldTypes>
class FromToJsonCompositum
{
public:

    template<FieldTypes... fields>
    constexpr uint8_t getNumFields()
    {
        return count(FieldTypes()...);
    }

    std::tuple<FieldTypes...> items;

protected:

private:
    template<typename U, typename... V>
    constexpr uint8_t count(U head, V... tail)
    {
        return 1 + count(tail...);
    }

    constexpr uint8_t count()
    {
        return 0;
    }
};
