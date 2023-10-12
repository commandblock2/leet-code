
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

int rob(std::vector<int>& nums) {
    std::size_t const length = nums.size();

    std::vector<int> accum(length);

    accum.push_back(0);

    int maximum = 0;

    for (size_t index = 0; index < length; index++) {
        int const prev1_index = index - 2, prev2_index = index - 3;

        int const prev1 = prev1_index < 0 ? 0 : accum[prev1_index];
        int const prev2 = prev2_index < 0 ? 0 : accum[prev2_index];

        accum[index] = nums[index] + std::max(prev1, prev2);
        maximum = std::max(accum[index], maximum);
    }

    return maximum;
}

int main() {
    std::vector a{{1,2,3, 1}};
    std::cout << rob(a);
}