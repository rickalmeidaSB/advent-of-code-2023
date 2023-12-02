#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <chrono>
#include "day1.h"

#define FUZZ_SOLUTION_OUTPUT

int main()
{
    std::cout
        << "#~~~~~~~~~~~~~~~~~~~~~~~~~#\r\n"
        << "|   Advent of Code 2023   |\r\n"
        << "#~~~~~~~~~~~~~~~~~~~~~~~~~#\r\n\r\n";

    try
    {
        std::vector<Solution *> solutions;
        solutions.push_back(new Day1());

        auto totalTime = std::chrono::high_resolution_clock::now();
        for (auto solution : solutions)
        {
            std::string name = solution->GetName().length() > 5 ? "Day " + solution->GetName().substr(5) : solution->GetName();
            std::cout
                << " Running solution: " << name
                << "\r\n#~~~~~~~~~~~~~~~~~~~~~~~~~#\r\n";

            auto start = std::chrono::high_resolution_clock::now();
#ifdef FUZZ_SOLUTION_OUTPUT // FUZZ_SOLUTION_OUTPUT - Hide STDOUT for solutions if this is true.
            std::cout.setstate(std::ios_base::failbit);
#endif
            solution->Run();
#ifdef FUZZ_SOLUTION_OUTPUT // FUZZ_SOLUTION_OUTPUT - Cleanup: enable STDOUT printing again.
            std::cout.clear();
            std::cout << "Solution output has been hidden.";
#endif
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "\r\n -> Solution run time: " << duration.count() << "μs\r\n\r\n";

            delete solution;
        }
        auto totalStop = std::chrono::high_resolution_clock::now();
        double totalDuration = std::chrono::duration_cast<std::chrono::microseconds>(totalStop - totalTime).count();
        std::cout << "Total time: " << totalDuration << "μs = " << std::setprecision(4) << (totalDuration / 1000) << "ms\r\n";
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << std::endl;

    return 0;
}