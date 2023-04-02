class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        sort(p.begin(),p.end());
        vector<long long>temp;
        vector<int>ans;
        for(int i=0;i<s.size();i++) temp.push_back(ceil(1.0*success/s[i]));
        for(int i=0;i<temp.size();i++){
            auto it=lower_bound(p.begin(),p.end(),temp[i]);
            long long count=p.end()-it;
            ans.push_back(count);
        }
        return ans;
    }
};