#include <vector>
#include "iostream"
#include <string>
#include <sstream>
#include "../include/lib.h"


using std::string;
using std::vector;


int main(int argc, char *argv[]) {
    const string eof = "EOF";
    uint batch_size;
    if (argc == 1)
        return -1;
    batch_size = atoi(argv[1]);

    std::vector<std::string> test1 = {"cmd1", "cmd2", "cmd3", "cmd4", "cmd5"};
    std::vector<std::string> test2 = {"cmd1", "cmd2", "{", "cmd3", "cmd4", "}",
                                      "{",  "cmd5", "cmd6", "{", "cmd7", "cmd8", "}", "cmd9", "}",
                                      "{",  "cmd10", "cmd11"};


    Interpreter i(batch_size);

    string line;
    std::stringstream streamIn;

    while (true)
    {
        getline(std::cin,line);
        string current_cmd = string(line);
        if (current_cmd == eof)
            break;
        i.process(current_cmd);
    }

    return 0;
}