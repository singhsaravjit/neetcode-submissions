class Solution {
public:
    unordered_map<int,vector<int>>premap;
    unordered_set<int>visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++)
        premap[i]={};

        for(const auto& prereq: prerequisites){
            premap[prereq[0]].push_back(prereq[1]);
        }

        for(int c=0;c<numCourses;c++){
            if(!dfs(c))
            return false;
        }
        return true;

    }

    bool dfs(int crs){

        if(visiting.count(crs)){
            return false;//cycle detected
        }

        if(premap[crs].empty())
        return true;


        visiting.insert(crs);

        for(int pre: premap[crs]){
            if(!dfs(pre))
            return false;
        }
        visiting.erase(crs);
        premap[crs].clear();
        return true;
    }
};
