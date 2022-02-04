#include <stdio.h>
#include <stdlib.h>
#include "brute_force.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "You did not pass a test case number as command-line argument to this executable.\n");
        return 1;
    }
    int caseNum = atoi(argv[1]);
    std::cout << std::boolalpha;
    std::vector<int> vals1, vals2;
    int target1 = 0, target2 = 0;
    switch (caseNum)
    {
        case 1:
            vals1 = std::vector<int>{5, 4, 12, 3, 10};
            target1 = 3;
            vals2 = vals1;
            target2 = 18;
            break;
        case 2:
            vals1 = std::vector<int>{8, 3, -2, 4, 9, 12, 15, 20,
                                     -1, -7, -50, -10, -100, 5, 30};
            target1 = 106;
            vals2 = vals1;
            target2 = 1000;
            break;
        case 3:
            vals1 = std::vector<int>{100000, 200000, 300000, 400000,
                                     500000, 600000, 700000, 800000};
            target1 = 106;
            vals2 = vals1;
            target2 = 3500000;
            break;
        case 4:
            vals1 = std::vector<int>{5, 4, 12, 3, 10};
            target1 = 0;
            vals2 = std::vector<int>{18, -6, -12};
            target2 = 0;
            break;
        default:
            fprintf(stderr, "Invalid case number.\n");
            return 2;
    }
    auto answer1 = isSubsetSum(vals1, target1);
    bool found1 = std::get<0>(answer1);
    std::cout << found1 << '\n';
    if (found1)
    {
        for (auto index : std::get<1>(answer1)) std::cout << index << ' ';
        std::cout << std::endl;
    }
    std::cout << "===\n";
    auto answer2 = isSubsetSum(vals2, target2);
    bool found2 = std::get<0>(answer2);
    std::cout << found2 << '\n';
    if (found2)
    {
        for (auto index : std::get<1>(answer2)) std::cout << index << ' ';
        std::cout << std::endl;
    }
    return 0;
}
