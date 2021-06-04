
unordered_map<string,vector<pair<int,string>>>  mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int t) {
        mp[key].push_back({t,value});
    }
    
    string get(string key, int t) {
        int i=0,j=mp[key].size()-1;
        string s="";
        while(i<=j){
            int m=(i+j)>>1;
            if(mp[key][m].first<=t){
                s=mp[key][m].second;
                i=m+1;
            }
            else j=m-1;
        }
        return s;
    }