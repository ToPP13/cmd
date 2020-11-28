#include <vector>
#include "iostream"
#include <string>
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


    char _buf[256] = "";
    Interpreter i(batch_size);
    while (true)
    {
        std::scanf("%255[^\n]", _buf);
        string current_cmd = string(_buf);
        if (current_cmd == eof)
            break;
        i.process(current_cmd);
    }

    return 0;
}