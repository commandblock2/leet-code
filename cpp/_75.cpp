#include <algorithm>
#include <array>
#include <numeric>
#include <vector>

void sortColors(std::vector<int>& nums) {
    auto [zeros, ones, twos] = std::accumulate(nums.begin(), nums.end(), std::array<int, 3>{{0, 0, 0}}, 
    [](std::array<int, 3> array, int const &n) {
        array[n]++;
        return array;
    });

    std::fill_n(nums.begin(), zeros, 0);
    std::fill_n(nums.begin() + zeros, ones, 1);
    std::fill_n(nums.begin() + zeros + ones, twos, 2);
}