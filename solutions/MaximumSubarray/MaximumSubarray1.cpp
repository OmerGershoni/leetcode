// https://leetcode.com/problems/maximum-subarray/

#include <vector>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largestSum = nums[0];
        int currentSum = nums[0];

        for (auto iter = (nums.begin() + 1); iter != nums.end(); ++iter)
        {
            currentSum = max(*iter, currentSum + *iter);
            largestSum = max(largestSum, currentSum);
        }

        return largestSum;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
};
