class Solution {
public:
    bool validateStackSequences(vector<int>& push, vector<int>& pop){
        int n=push.size();
        int m=pop.size();
        stack<int>st;
        int j=0,i=0;
        while(i<n || j<n){
            if(!st.empty() && st.top()==pop[j]){
                st.pop();
                j++;
            }
            else if(i<n && j<n && push[i]!=pop[j]){
                st.push(push[i]);
                i++;
            }
            else if(i<n && j<n && push[i]==pop[j]){
                i++;
                j++;
            }
            else return false;
        }
        return st.empty();
    }
};