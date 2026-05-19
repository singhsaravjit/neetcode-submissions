class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums){
            s.insert(x);
        }
        int maxi=0,l;
        for(int x : s)
        {
            if(s.count(x-1))
            continue;
                l=1;
                while(s.count(x+1)){
                l++;
                x=x+1;
                }
         
            maxi=max(maxi,l);
        }
        return maxi;
    }
};
