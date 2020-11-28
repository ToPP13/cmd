//
// Created by kirill on 25.11.2020.
//

#pragma once

#include <string>

class IBasicInterpreter
{
public:

    IBasicInterpreter() = default;
    virtual void process(std::string current_cmd) = 0;
};
