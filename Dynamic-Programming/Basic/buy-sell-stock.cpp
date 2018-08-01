// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = INT_MAX , maxprofit = 0; // ek baar hi buy karna hai aur ek hi baar sell bhi

        for(int i = 0 ; i< prices.size() ; i++){
            if(minimum > prices[i]) minimum = prices[i];
            else if( prices[i] - minimum > maxprofit ) maxprofit = prices[i] - minimum;
        }

        return maxprofit;
    }
};
