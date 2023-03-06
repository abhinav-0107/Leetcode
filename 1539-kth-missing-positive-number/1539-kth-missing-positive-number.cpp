class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int count=0;
        
        if(n==arr[n-1]){
            return n+k;
        }
        
        map<int,int>mp;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        int i=1;
        
        while(count!=k){
            if(mp[i]==0){
                count++;
            }
            i++;
        }
        
        return i-1;
    }
};