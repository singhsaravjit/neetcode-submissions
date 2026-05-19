class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for (int x: nums)
        {
            mp[x]++;
        }
        vector<int> ans;
       
     multimap<int, int, greater<int>> MM;

    for (auto& it : mp) {
        MM.insert({ it.second, it.first });
    }

    for (auto& it : MM) {
        k--;

       ans.push_back(it.second);
        if(k==0)
        break;
    }

        return ans;
    }
};
