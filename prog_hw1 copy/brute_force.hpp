#ifndef BRUTE_FORCE_HPP
#define BRUTE_FORCE_HPP

#include <tuple>
#include <vector>

std::tuple<bool, std::vector<unsigned>> isSubsetSum(
        std::vector<int> itemVals, int target);

std::tuple<bool, std::vector<unsigned>, std::vector<unsigned>>
        isSetPartionable(std::vector<int> vals);

#endif  // BRUTE_FORCE_HPP
