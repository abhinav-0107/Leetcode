class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        map<int,int>mp;
        for(int i = 0 ;i < n ; i++){
            mp[arr[i]]++;
            if(float(mp[arr[i]])/n > 0.25) return arr[i];
        }
        
        return -1;
    }
};