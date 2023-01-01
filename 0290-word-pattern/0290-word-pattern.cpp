class Solution {
public:
    bool wordPattern(string p, string s) {
        map<char,string>mp;
        vector<string>v;
        string str="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                v.push_back(str);
                str.clear();
            }
            else str+=s[i];
        }
        v.push_back(str);
        if(v.size()!=p.size()) return false; 
        for(int i=0;i<p.size();i++){
            if(mp.find(p[i])!=mp.end()){
                if(mp[p[i]]!=v[i])return false;
            }
            else mp.insert({p[i],v[i]});
        }
        map<string,int>temp;
        for(auto i:mp) temp[i.second]++;
        for(auto i:temp){
            if(i.second!=1)return false;
        }
        return true;
    }
};