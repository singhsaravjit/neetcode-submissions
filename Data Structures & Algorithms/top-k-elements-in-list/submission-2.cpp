class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for (int x: nums)
        {
            mp[x]++;
        }
        vector<int> ans;
       vector<vector<int>> fr(nums.size()+1);
       for(auto x: mp)
       {
        fr[x.second].push_back(x.first);
       }
       for(int i=fr.size()-1;i>0;i--){
        for(int n :fr[i]){
            ans.push_back(n);
            if(ans.size()==k){
                return ans;
            }
        }
       }
     

        return ans;
    }
};
