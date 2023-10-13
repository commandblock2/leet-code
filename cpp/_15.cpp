#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>
#include <vector>


std::vector<std::vector<int>> threeSumTerrible(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int const length = nums.size();

    std::set<std::vector<int>> result;

    for (int i_index = 0; i_index < length && nums[i_index] <= 0; i_index++) {
            

        for (int j_index = i_index + 1; j_index < length && nums[j_index] * 2 + nums[i_index] <= 0; j_index++) {
            int k = 0 - nums[j_index] - nums[i_index];
            if (std::binary_search(std::next(nums.begin(), j_index + 1), nums.end(), k))
                result.insert(std::vector{{nums[i_index], nums[j_index], k}});
        }
    }


    std::vector<std::vector<int>> return_;
    return_.reserve(result.size());


    for (auto const & i : result) {
        if (i.size() == 3)
            return_.push_back(i);
    }

    return return_;
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int const length = nums.size();


    std::set<std::vector<int>> result;

    for (int i = 0; i < length; i++) {
        auto j = std::next(nums.begin(), i + 1), k = std::next(nums.end(), -1);

        while (j < k) {
            auto expr = *j + *k + nums[i];
            if (expr > 0) {
                k--;
            } else if (expr < 0) {
                j++;
            } else {
                result.insert(std::vector{{nums[i], *j, *k}});
                k--;
                j++;
            }
        }
    }

    std::vector<std::vector<int>> return_;

    for (auto const & i : result) {
        return_.push_back(i);
    }

    return return_;
}

int main() {
    std::vector<int> a{{-1,0,1,2,-1,-4}};
    threeSum(a);
}