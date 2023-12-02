#ifndef DAY1_H
#define DAY1_H

#include "Solution.h"
#include <string>
#include <map>

class Day1 : public Solution
{
public:
    std::string GetName();
    void Run();

private:
    static const std::string input;
    static const std::map<int, std::string> numbers;
    int getNumber(std::string line, int start, bool reverse = false);
};

#endif // DAY1_H