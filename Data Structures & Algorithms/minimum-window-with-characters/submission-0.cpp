class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), m=t.size();
        if(m>n || t.empty())
        return "";

        unordered_map<char,int>mpt;

        for(char c: t)
        mpt[c]++;

        unordered_map<char,int>win;

        int mxl=INT_MAX, bestl=0,l=0,have=0,req=mpt.size();

        for(int r=0;r<s.size();r++){
         char x=s[r];
         if(mpt.count(x)){
            win[x]++;
            if(win[x]==mpt[x])
            have++;

         }

         while(have== req){
            if(r-l+1< mxl)
            {
                mxl=r-l+1;
                bestl=l;
            }
           char c=s[l];
           if(mpt.count(c)){
            win[c]--;
            if(win[c]<mpt[c])
            have--;
           }
l++;
         }

   


        }
        return mxl==INT_MAX ? "" : s.substr(bestl,mxl);
    }
};
