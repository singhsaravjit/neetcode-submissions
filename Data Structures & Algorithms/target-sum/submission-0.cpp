class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int> dp;
        dp[0]=1;

        for(int num : nums){

            unordered_map<int,int> nextdp;

            for(auto& entry :dp){
                int total=entry.first;
                int count=entry.second;
                nextdp[total+num]+=count;
                nextdp[total-num]+=count;
            }
            dp=nextdp;
        }
        return dp[target];
    }
};
