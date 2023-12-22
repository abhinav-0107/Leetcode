class Solution {
public:
    int maxScore(string s) {
        int ans=0,l=0,r=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')r++;
        }        
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0')l++;
            else r--;
            ans=max(ans,l+r);
        }
        return ans;
    }
};