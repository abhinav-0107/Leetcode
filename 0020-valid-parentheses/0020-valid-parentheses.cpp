class Solution {
public:
    bool isValid(string s) {
         stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if((!st.empty() && st.top()=='(' && s[i]==')') || (!st.empty() && st.top()=='[' && s[i]==']' ) || (!st.empty() && st.top()=='{' && s[i]=='}')){
                st.pop();
            }
            else{
                return false;
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};