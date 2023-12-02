#ifndef DAY1_H
#define DAY1_H

#include "Solution.h"
#include <string>

class Day1 : public Solution
{
public:
    std::string GetName();
    void Run();

private:
    static const std::string input;
    static const std::string BASE10_CHARS;
    int getNumber(std::string line, int start, bool reverse = false);
};

#endif // DAY1_H