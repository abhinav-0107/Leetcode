class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        int count=0;
        for(int i=0;i<g.size();i++){
            auto it=lower_bound(s.begin(),s.end(),g[i]);
            if(it!=s.end()){
                count++;
                s.erase(it);
            }
        }
        return count;
    }
};