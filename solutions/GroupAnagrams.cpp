// https://leetcode.com/problems/group-anagrams

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, std::vector<std::string> > groups;

        for (auto iter = strs.begin(); iter != strs.end(); ++iter)
        {
            std::string sortedStr = *iter;
            std::sort(sortedStr.begin(), sortedStr.end());

            if (groups.find(sortedStr) == groups.end())
            {
                std::vector<string> group;
                group.push_back(*iter);
                groups[sortedStr] = group;
            }
            else
            {
                groups[sortedStr].push_back(*iter);
            }
        }

        for (auto iter = groups.begin(); iter != groups.end(); ++iter)
        {
            result.push_back(iter->second);
        }

        return result;
    }
};
