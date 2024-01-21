#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>
using namespace std;
#include <vector>

class ICommand{
    public:
        virtual void execute() = 0;
};

#endif
