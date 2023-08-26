class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int> last(n+1,0),curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int pick=INT_MIN;
                if(prev==-1 || pairs[prev][1]<pairs[i][0])pick=1+last[i+1];
                int notpick=last[prev+1];
                curr[prev+1]=max(pick,notpick);
            }
            last=curr;
        }
        return last[0];
    }
};