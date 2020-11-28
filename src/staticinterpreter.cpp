//
// Created by kirill on 25.11.2020.
//

#include "../include/staticinterpreter.h"

StaticInterpreter::~StaticInterpreter()
{
    if (!_scb.empty())
    {
        _scb.log_commands();
    }
}

void StaticInterpreter::process(std::string current_cmd)
{
    _scb.add_command(current_cmd);
    if (_scb.size() == _batch_size)
    {
        _scb.log_commands();
        _scb.clear();
    }
}