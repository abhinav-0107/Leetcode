class Solution {
public:
    vector<string> ans;
    void f(int i,string str,string& s,int n){
        if(i>=n){
            if(str.size()-s.size()==4) {
                str.pop_back();
                ans.push_back(str);
            }
            return;
        }
        f(i+1,str+s[i]+'.',s,n);
        if(s[i]!='0'){
            if(i+1<n) f(i+2,str+s[i]+s[i+1]+'.',s,n);
            if(i+2<n){
                string x="";
                x+=s[i];
                x+=s[i+1];
                x+=s[i+2];
                if(stoi(x)<=255) f(i+3,str+x+'.',s,n);
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12) return {};
        string temp="";
        f(0,temp,s,s.size());
        return ans;    
    }
};