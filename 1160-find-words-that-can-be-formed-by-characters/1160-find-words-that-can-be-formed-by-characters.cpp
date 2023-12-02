class Solution {
public:
    int countCharacters(vector<string>& w, string c) {
        multiset<char>s,t;
        int ans=0;
        for(int i=0;i<c.size();i++)s.insert(c[i]);
        for(int i=0;i<w.size();i++){
            t=s;
            bool f=true;
            for(int j=0;j<w[i].size();j++){
                auto it=t.find(w[i][j]);
                if(it==t.end()){
                    f=false;
                    break;
                }
                t.erase(it);
            }
            if(f) ans+=w[i].size();
        }
        return ans;
    }
};