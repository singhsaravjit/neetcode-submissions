class Solution {
public:
    int maxArea(vector<int>& heights) {
        int m=INT_MIN;
        int left=0,right=heights.size()-1;
        while(left<right){
            int x= (right-left)*min(heights[left],heights[right]);
            m=max(x,m);
            if(heights[left]<heights[right])
            left++;
            else
            right--;
        }
        return m;
    }
};
