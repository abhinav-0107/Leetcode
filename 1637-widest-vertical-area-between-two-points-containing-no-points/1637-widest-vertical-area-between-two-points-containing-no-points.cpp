class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans=0;
        sort(points.begin(),points.end());
        for(int i=0;i<points.size()-1;i++) ans=max(ans,points[i+1][0]-points[i][0]);
        return ans;
    }
};