class Solution {
public:

    string encode(vector<string>& strs) {
        string x;
        for( string a : strs){
            x += to_string(a.size()) + "#" + a;
        }
        return x;
        
    }

    vector<string> decode(string s) {
        vector<string> xx;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int l= stoi(s.substr(i,j-i));
            i=j+1;
            j=i+l;
            xx.push_back(s.substr(i,l));
            i=j;
        }

        return xx;

    }
};
