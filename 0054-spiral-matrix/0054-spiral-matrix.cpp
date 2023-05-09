class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int maxr=mat.size()-1,maxc=mat[0].size()-1,minr=0,minc=0;
        int t=(mat.size())*(mat[0].size());
        int count=0;
        vector<int>v;
        while(count<t){
//          Upper wall
            for(int j=minc;j<=maxc && count<t;j++){
                int i=minr;
                v.push_back(mat[i][j]);
                count++;
            }
            minr++;
//          Right wall
            for(int i=minr;i<=maxr && count<t;i++){
                int j=maxc;
                v.push_back(mat[i][j]);
                count++;
            }
            maxc--;
//          lower wall
            for(int j=maxc;j>=minc && count<t;j--){
                int i=maxr;
                v.push_back(mat[i][j]);
                count++;
            }
            maxr--;
//          left wall
            for(int i=maxr;i>=minr && count<t;i--){
                int j=minc;
                v.push_back(mat[i][j]);
                count++;
            }
            minc++;
        }
        return v;
    }
};