//
// Created by kirill on 25.11.2020.
//

#include "../include/dynamicinterpreter.h"

void DynamicInterpreter::process(std::string current_cmd)
{
    _scb.add_command(current_cmd);
}