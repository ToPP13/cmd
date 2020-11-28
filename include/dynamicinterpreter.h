//
// Created by kirill on 25.11.2020.
//

#pragma once

#include "ibasicinterpreter.h"
#include "commandstorage.h"


class DynamicInterpreter: public IBasicInterpreter
{
public:
    void process(std::string current_cmd) override;

private:
    CommandStorage _scb;
};
