class Solution {
public:    
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        multimap<int,int>mp;
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]) mp.insert({i,j});
            }
        }
        for(auto it:mp){
            int count1=0,count2=0;
            for(int i=0;i<m;i++){
                if(mat[i][it.second])count1++;
            }
            for(int j=0;j<n;j++){
                if(mat[it.first][j])count2++;
            }
            if(count1==1 && count2==1)ans++;
        }
        return ans;
    }
};