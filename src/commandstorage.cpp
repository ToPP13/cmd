//
// Created by kirill on 25.11.2020.
//

#include "../include/commandstorage.h"

using std::string;

std::string string_from_int(long num)
{
    std::ostringstream s;
    s << num;
    std::string num_as_string(s.str());
    return num_as_string;
}


void CommandStorage::add_command(const string & command)
{
    if (empty())
        set_log_file();
    _commands.emplace_back(command);
}

bool CommandStorage::set_log_file()
{
    uint now = time(nullptr);
    _filename = "bulk" + string_from_int(now) + ".log";
    std::ofstream f;
    f.open(_filename,std::ios::out);
    if(!f)
        return false;

    f.close();
    return true;
}

bool CommandStorage::log_commands() {
    std::ofstream f;
    f.open(_filename, std::ios::out);
    if (!f) {
        return false;
    }
    f << "bulk: ";
    for (auto iter = _commands.begin(); iter != _commands.end(); iter++) {
        if (iter != _commands.begin())
            f << ", " << *iter;
        else
            f << *iter;
    }
    f.close();
    return true;
}

