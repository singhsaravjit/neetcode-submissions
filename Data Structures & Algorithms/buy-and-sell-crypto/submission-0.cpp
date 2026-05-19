class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx= 0;
        int mn = prices[0];
        for(int x : prices)
        {
            mx=max(mx,x-mn);
            mn=min(mn,x);
        }
        return mx;
    }
};
