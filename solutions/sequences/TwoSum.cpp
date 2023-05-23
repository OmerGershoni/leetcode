// https://leetcode.com/problems/two-sum/

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i)
        {
            int comp = target - nums[i];

            if (map.find(comp) == map.end())
            {
                map[nums[i]] = i;
            }
            else
            {
                result.push_back(map[comp]);
                result.push_back(i);
                return result;
            }
        }

        return result;
    }
};
