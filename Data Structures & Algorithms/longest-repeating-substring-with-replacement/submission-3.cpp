class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int l=0,res=0,maxfreq=1;
        for(int r=0;r<s.size();r++){
         mp[s[r]]++;
         maxfreq=max(maxfreq,mp[s[r]]);
         while((r-l+1)-maxfreq>k){
            mp[s[l]]--;
            l++;
         }
         
         res=max(r-l+1,res);

        }
        return res;
    }
};
