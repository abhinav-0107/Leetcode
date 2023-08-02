class Solution {
public:
    vector<vector<int>>ans;
    void comb(int i,vector<int>& t,int k,int n){
        if(t.size()==k){
            ans.push_back(t);
            return;
        }   
        if(i==n+1){
            // if(t.size()==k)ans.push_back(t);
            return;
        }
//      Pick the element.
        t.push_back(i);
        comb(i+1,t,k,n);
        t.pop_back();
//      Not Pick the element.   
        comb(i+1,t,k,n);
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>t;
        comb(1,t,k,n);
        return ans;    
    }
};