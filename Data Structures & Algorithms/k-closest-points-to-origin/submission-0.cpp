class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        

        priority_queue<pair<int,pair<int,int>>>maxheap;

        for(auto& point : points){

            int dis= point[0]*point[0] + point[1]*point[1];

            maxheap.push({dis,{point[0],point[1]}});

            if(maxheap.size() > k)
            maxheap.pop();
        }

        vector<vector<int>> ans;
        while(!maxheap.empty()){
            ans.push_back({maxheap.top().second.first,
            maxheap.top().second.second});
            maxheap.pop();
        }
        return ans;
    }
};
