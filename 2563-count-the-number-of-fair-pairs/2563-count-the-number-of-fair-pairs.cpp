class Solution {
public:
    long long countFairPairs(vector<int>& arr, int l, int r) {
        int n=arr.size();
        long long right = n - 1;
        long long count = 0;
        
        sort(arr.begin(), arr.end());

        while (right > 0) {
            
            int start = lower_bound(arr.begin(), arr.end(), l - arr[right])-arr.begin();
            
            auto it2 = upper_bound(arr.begin(), arr.end(),r - arr[right]);
            --it2;
            long long end = it2 - arr.begin();
            
            end = min(end, right - 1);
            
            if (end - start >= 0) count += (end - start + 1);
            
            right--;
            
        }
        
        return count;
    }
};
