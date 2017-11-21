//
// Created by rubienr on 08/11/17.
//

#pragma once

class Print;

class Esp {
private:
    Print &out;
protected:

public:
    Esp(Print& serial);
    void init(bool earaseConfigutation = false);
    void printInfo();
};

