// https://leetcode.com/problems/contains-duplicate/

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       std::unordered_set<int> uniqueNumbers;

       for (auto iter = nums.begin(); iter != nums.end(); ++iter)
       {
           if (uniqueNumbers.find(*iter) != uniqueNumbers.end())
           {
               return true;
           }
           
           uniqueNumbers.insert(*iter);
       }

       return false; 
    }
};
