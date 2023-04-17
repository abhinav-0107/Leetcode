class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int x) {
        int n=c.size();
        vector<bool> ans(n);
        int max=*max_element(c.begin(),c.end());
        for(int i=0;i<c.size();i++){
            if(c[i]+x>=max)ans[i]=true;
            else ans[i]=false;
        }
        return ans;
    }
};