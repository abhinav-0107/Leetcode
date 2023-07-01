class Solution {
public:    
    int ans=INT_MAX;
    void f(int i,vector<int>& cook,int k,int n,vector<int>& a){
        if(i==n){
            ans=min(ans,*max_element(a.begin(),a.end()));
            return;
        }
        for(int child=1;child<=k;child++){
            a[child-1]+=cook[i];
            f(i+1,cook,k,n,a);
            a[child-1]-=cook[i];
        }
    }
    
    int distributeCookies(vector<int>& cook, int k) {
        int n=cook.size();
        vector<int>a(k,0);
        f(0,cook,k,n,a);
        return ans;
    }
};