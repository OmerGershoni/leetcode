// https://leetcode.com/problems/merge-intervals

#include <vector>
#include <algorithm>

bool IntervalCompare(const std::vector<int> &int1, const std::vector<int> &int2)
{
    return (int1[0] < int2[0]);
}

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        std::vector<std::vector<int> > result;

        std::sort(intervals.begin(), intervals.end(), IntervalCompare);

        int i;
        for (i = 0; i < (intervals.size() - 1); ++i)
        {
            if (intervals[i][1] < intervals[i + 1][0])
            {
                result.push_back(intervals[i]);
            }
            else
            {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
            }
        }
        result.push_back(intervals[i]);
        return result;
    } 

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
};
