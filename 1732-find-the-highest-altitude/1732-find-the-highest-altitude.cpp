class Solution {
public:
    int largestAltitude(vector<int>& g) {
        int m=0,sum=0;
        for(int i=0;i<g.size();i++){
            sum+=g[i];
            m=max(sum,m);
        }
        return m;
    }
};