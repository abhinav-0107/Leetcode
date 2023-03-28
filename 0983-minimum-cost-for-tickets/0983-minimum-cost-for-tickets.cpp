class Solution {
public:    
    int mincostTickets(vector<int>& d, vector<int>& c) {
        int n=d.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int ind1=lower_bound(d.begin(),d.end(),d[i]+1)-d.begin();
            int op1=c[0]+dp[ind1];
            int ind2=lower_bound(d.begin(),d.end(),d[i]+7)-d.begin();
            int op2=c[1]+dp[ind2];
            int ind3=lower_bound(d.begin(),d.end(),d[i]+30)-d.begin();
            int op3=c[2]+dp[ind3];
            dp[i]=min(op1,min(op2,op3));
        }
        return dp[0];
    }
};