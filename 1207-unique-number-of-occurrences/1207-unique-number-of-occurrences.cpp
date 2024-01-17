class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        set<int>s;
        for(int i=0;i<arr.size();i++)mp[arr[i]]++;
        for(auto i:mp)s.insert(i.second);
        return s.size()==mp.size();
    }
};