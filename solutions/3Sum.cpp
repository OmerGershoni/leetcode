// https://leetcode.com/problems/3sum/

#include <vector>
#include <set>
#include <algorithm> 

#define MAX_NUM_VAL 100000

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        std::vector<std::vector<int> > result;
        std::set<vector<int> > uniqueTriplets;
        int lastNum = (MAX_NUM_VAL + 1);

        std::sort(nums.begin(), nums.end());

        if ((nums.size() < 3) || (nums[0] > 0))
        {
            return result;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == lastNum)
            {
                continue;
            }

            int left = (i + 1);
            int right = (nums.size() - 1);
            int targetSum = (nums[i] * - 1);

            while (left < right)
            {
                if ((nums[left] + nums[right]) > targetSum)
                {
                    --right;
                }
                else if ((nums[left] + nums[right]) < targetSum)
                {
                    ++left;
                }
                else
                {
                    std::vector<int> triplet;

                    triplet.push_back(nums[i]); 
                    triplet.push_back(nums[left]);   
                    triplet.push_back(nums[right]);  

                    std::sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(triplet); 

                    --right;
                    ++left;
                }
            }

            lastNum = nums[i];
        }

        for (auto iter = uniqueTriplets.begin(); iter != uniqueTriplets.end(); ++iter)
        {
            result.push_back(*iter);
        }

        return result;
    }
};
