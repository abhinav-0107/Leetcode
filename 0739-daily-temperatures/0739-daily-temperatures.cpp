class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        int n=temp.size();
        vector<int>v(n,0);
        st.push(0);
        for(int i=1;i<temp.size();i++){
                while(!st.empty() && temp[i]>temp[st.top()]){
                    v[st.top()]=i-st.top();
                    st.pop();
                }
                st.push(i);
        }
        return v;
    }
};