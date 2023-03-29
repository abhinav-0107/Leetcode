class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int n=sat.size();
        sort(sat.begin(),sat.end());
        vector<int> prev(n+2,0),curr(n+2,0);
        for(int i=n-1;i>=0;i--){
            for(int count=n;count>=1;count--){
                int pick=count*sat[i]+prev[count+1];
                int notpick=prev[count];
                curr[count]=max(pick,notpick);
            }
            prev=curr;
        }
        return prev[1];
    }
};