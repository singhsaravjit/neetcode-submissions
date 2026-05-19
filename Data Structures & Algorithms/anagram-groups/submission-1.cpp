class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string x : strs){
            string y="";
            int count[26]={};
            for (int i=0;i<x.size();i++){
                   count[x[i]-'a']++;
            }
            for(int i=0;i<26;i++){
                y+= ','+ to_string(count[i]);
            }
            mp[y].push_back(x);
        }
        vector<vector<string>> r;
        for(const auto& pair : mp){
            r.push_back(pair.second);
        }
        return r;
    }
};
