#include <algorithm>
#include <iterator>
#include <vector>
#include <queue>



int findKthLargest(std::vector<int> &nums, int k) {
    std::priority_queue<int> queue;
    std::for_each(nums.begin(), nums.begin() + k, [&](int const i) {
        queue.push(-i);
    });
    std::for_each(nums.begin() + k, nums.end(), [&](int const i) {
        queue.push(-i);
        queue.pop();
    });

    return -queue.top();
}
