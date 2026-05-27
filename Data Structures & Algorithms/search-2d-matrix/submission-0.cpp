class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        

        int rows = matrix.size();      
        int cols = matrix[0].size();
        int check=0, finalrow,l=0,r=rows-1;
         while(l<=r){
            int mid= l+(r-l)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][cols-1]){
                check=1;
                finalrow=mid;
                break;
            }
            else if(target<matrix[mid][0]){
                r=mid-1;
            }
            else
            l=mid+1;
         }
         
        if(check==0)
        return false;

        

        l=0,r=cols-1;
        while(l<=r){
            int mid= l+(r-l)/2;
        
            if(target==matrix[finalrow][mid]){
                return true;
            }
            else if(target<matrix[finalrow][mid]){
                r=mid-1;
            }
            else
            l=mid+1;
         }

     return false;

    }
};
