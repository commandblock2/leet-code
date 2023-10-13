#include <algorithm>
#include <iostream>
#include <vector>


bool canJump(std::vector<int>& nums) {
    int limit = nums.front();

    for (int i = 0; i < std::min(limit + 1, (int)nums.size()); i++) {
        limit = std::max(nums[i] + i, limit);
        // std::cout << limit << std::endl;
    }

    return limit >= nums.size() - 1;
}

int main() {
    std::vector a{{1,2,3}};
    std::cout << canJump(a);
}