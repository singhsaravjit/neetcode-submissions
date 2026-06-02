class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for (int num : nums){
            int id=abs(num)-1;
            if(nums[id]<0){
                return abs(num);
            }
            nums[id] *= -1;
        }
        return -1;
    }
};
