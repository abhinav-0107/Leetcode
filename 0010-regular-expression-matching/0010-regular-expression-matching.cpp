class Solution {
public:
    int f(int i,int j,string& p,string& s){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0){
            if(p[i]!='*')return false;
            for(int k=1;k<=i;k+=2){
                if(p[k]!='*') return false;
            }
            return true;
        }
//         Match
        if(p[i]==s[j] || p[i]=='.') return f(i-1,j-1,p,s);
        if(p[i]=='*' && p[i-1]=='.') return f(i-2,j,p,s) || f(i,j-1,p,s);
//         NotMatch 
        if(p[i]=='*' && p[i-1]==s[j]) return f(i-2,j,p,s) || f(i,j-1,p,s);
        if(p[i]=='*') return f(i-2,j,p,s);
        return false;
    }

    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        return f(n-1,m-1,p,s);
    }
};