class Twitter {

    int count;
    unordered_map<int, vector<vector<int>>> tweetmap;
    unordered_map<int,set<int>> followmap;

public:
    Twitter() {

    count=0;    
    }
    
    void postTweet(int userId, int tweetId) {
        
        tweetmap[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        auto compare= [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
         priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxheap(compare);

       followmap[userId].insert(userId);
         for(int followeeId : followmap[userId]){

            if(tweetmap.count(followeeId)){
                const vector<vector<int>>& tweets = tweetmap[followeeId];
                int index = tweets.size() - 1;
                maxheap.push({tweets[index][0],tweets[index][1],followeeId,index});
            }
         }

         while(!maxheap.empty() && res.size()<10){
            vector<int> cur= maxheap.top();
            maxheap.pop();

            res.push_back(cur[1]);
            int index= cur[3];
            if(index>0){
                const vector<int>& tweet= tweetmap[cur[2]][index-1];
                maxheap.push({tweet[0],tweet[1], cur[2],index-1});
            }
         }
         return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
    }
};
