class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int>mp;
        for(auto i:paths){
            mp[i[0]]++;
            mp[i[1]]++;
        }
        vector<string>v;
        for(auto i:mp){
            if(i.second==1) v.push_back(i.first);
        }
        for(auto i:paths){
            if(v[0]==i[1])return v[0];
        }
        return v[1];
    }
};