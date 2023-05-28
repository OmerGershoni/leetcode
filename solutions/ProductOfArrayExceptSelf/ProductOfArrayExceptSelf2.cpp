// https://leetcode.com/problems/product-of-array-except-self/

#include <vector>

class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> answer;
        int product = 1;

        answer.push_back(1);
        for (int i = 1; i < nums.size(); ++i)
        {
            product *= nums[i - 1];
            answer.push_back(product);
        }

        product = 1;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            product *= nums[i + 1];
            answer[i] *= product;
        }

        return answer;
    }
};
