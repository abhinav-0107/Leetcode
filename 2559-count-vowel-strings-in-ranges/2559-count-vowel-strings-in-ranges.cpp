class Solution {
public:
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        int n=w.size();
        int m=q.size();
        vector<int>ans(m,0);
        vector<int>v(n,0);
        
        for(int i=0;i<n;i++){
            int s=w[i].size();
            bool first=(w[i][0]=='a' || w[i][0]=='e' || w[i][0]=='i' || w[i][0]=='o' || w[i][0]=='u');
            bool last=(w[i][s-1]=='a' || w[i][s-1]=='e' || w[i][s-1]=='i' || w[i][s-1]=='o' || w[i][s-1]=='u');
                
            if(first && last){
                if(i>0)v[i]=v[i-1]+1;
                else v[i]=1;
            }
            else if(i>0) v[i]=v[i-1];
        }
        
        for(int i=0;i<m;i++){
            if(q[i][0]>0)ans[i]=v[q[i][1]]-v[q[i][0]-1];
            else ans[i]=v[q[i][1]];
        }
        
        return ans;
    }
};