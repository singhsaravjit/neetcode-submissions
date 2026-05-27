class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,m=INT_MIN;
        for(int x : piles){
         m=max(m,x);
        }
        int ans=m,r=m;
        while(l<=r){
            int mid= (l+r)/2;
            long long s=0;
            for(int x: piles)
               s+=ceil(static_cast<double>(x)/mid);
            if(s<=h){
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
        
    }
};
