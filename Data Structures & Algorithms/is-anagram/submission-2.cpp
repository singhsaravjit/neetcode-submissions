class Solution {
public:
    bool isAnagram(string s, string t) {
      int c1[26]={};
      int c2[26]={};
      for(int i=0;i<s.size();i++)
      {
        c1[s[i]-'a']++;
      }  
      for(int i=0;i<t.size();i++)
      {
        c2[t[i]-'a']++;
      } 
      for(int i=0;i<26;i++)
      {
        if(c1[i]!= c2[i])
        return false;
      } 
      return true;
    }
};
