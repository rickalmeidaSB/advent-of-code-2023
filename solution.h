#ifndef SOLUTION_H
#define SOLUTION_H
#include <string>

class Solution
{
public:
    virtual void Run() = 0;
    virtual std::string GetName() = 0;
};

#endif // SOLUTION_H