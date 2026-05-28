class TimeMap {
    private:
    unordered_map<string, vector<pair<int,string>>> st;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        st[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {

        auto value= st[key];
        int l=0,r=value.size()-1;
        string res="";
        while(l<=r){
            int mid= l+(r-l)/2;
            if(value[mid].first <= timestamp){
                res=value[mid].second;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return res;
    }
};
