class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n= grid.size();

        set<pair<int,int>>visit;

        priority_queue<vector<int>,vector<vector<int>>, greater<>> minheap;

        vector<vector<int>> directions= { {0,1}, {0,-1}, {1,0}, {-1,0}};

        minheap.push(
            {grid[0][0],0,0}
        );

        visit.insert({0,0});

        while(!minheap.empty()){
            auto cur=minheap.top();
            minheap.pop();

            int t= cur[0],r=cur[1],c=cur[2];

            if(r == n-1 && c==n-1)
            return t;

            for(const auto& dir : directions){
                int ner=r+dir[0], nec=c+dir[1];

                if(ner <0 || nec <0 || ner == n ||
                nec==n || visit.count({ner,nec})){
                    continue;
                }

                visit.insert({ner,nec});
                minheap.push({max(t,grid[ner][nec]), ner,nec});
            }
        }
        return n*n;
    }
};
