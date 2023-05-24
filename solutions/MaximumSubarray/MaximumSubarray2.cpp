// https://leetcode.com/problems/maximum-subarray/

#include <vector>
#include <limits.h>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return recursiveMaxSubArray(nums, 0, nums.size() - 1);
    }

    int recursiveMaxSubArray(vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return INT_MIN;
        }

        if (left == right)
        {
            return nums[left];
        }

        int middle = ((left + right) / 2);

        return max(maxCrossMiddleSubArray(nums, left, right, middle),        
            recursiveMaxSubArray(nums, middle + 1, right), 
            recursiveMaxSubArray(nums, left, middle - 1));
    }         

    int maxCrossMiddleSubArray(vector<int>& nums, int left, int right, int middle)
    {
        int maxRightMiddle = INT_MIN;
        int maxLeftMiddle = INT_MIN;
        int sum = 0;

        for (int i = middle; i <= right; ++i)
        {
            sum += nums[i];
            maxRightMiddle = max(maxRightMiddle, sum);
        }

        sum = 0;
        for (int i = middle; i >= left; --i)
        {
            sum += nums[i];
            maxLeftMiddle = max(maxLeftMiddle, sum);
        }

        return max(maxLeftMiddle, maxRightMiddle, maxLeftMiddle + maxRightMiddle - nums[middle]);
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int max(int a, int b, int c)
    {
        return max(max(a, b), c);
    }
