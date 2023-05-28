// https://leetcode.com/problems/product-of-array-except-self/

#include <vector>

class Solution {

public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> answer;

        initProductVectors(nums);

        for (int i = 0; i < nums.size(); ++i)
        {
            int product = (LeftProducts[i] * RightProducts[i]);
            answer.push_back(product);
        }

        return answer;
    }

    void initProductVectors(vector<int>& nums)
    {
        int product = 1;
        
        for (auto iter = nums.begin(); iter != nums.end(); ++iter)
        {
            LeftProducts.push_back(1);
            RightProducts.push_back(1);
        }

        for (int i = 1; i < nums.size(); ++i)
        {
            product *= nums[i - 1];
            LeftProducts[i] = product;

        }

        product = 1;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            product *= nums[i + 1];
            RightProducts[i] = product;
        }
    }

private:
        vector<int> LeftProducts;
        vector<int> RightProducts;
};
