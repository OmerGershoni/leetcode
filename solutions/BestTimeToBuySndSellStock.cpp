// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int minPrice = prices[0];
        int profit = 0;

        for (auto iter = (prices.begin() + 1); iter != prices.end(); ++iter)
        {
            if (*iter < minPrice)
            {
                minPrice = *iter;
            }   
            else if ((*iter - minPrice) > profit)
            {
                profit = (*iter - minPrice);
            }
        }

        return profit;
    }
};
