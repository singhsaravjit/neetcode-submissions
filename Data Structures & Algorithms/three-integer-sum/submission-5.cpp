class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int target= -nums[i];
            int j=i+1, k=nums.size()-1;
            while(j<k)
            {
                int sum= nums[j]+nums[k];
                if(sum < target)
                   j++;
                   else if(sum > target)
                   k--;
                   else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    k--;
                    while(j<k)
                    {
                        if(nums[j]==nums[j+1])
                        j++;
                        else{
                            j++;
                        break;
                        }
                    }
                   }
            }
             while(i<nums.size()-2){
                if(nums[i]==nums[i+1])
                i++;
                else
                break;
            }
           
        }
        return ans;
    }
};
