class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int n=nums.size();
        set<int>s;
        
        // sieve of eratosthenes (Algo to find prime numbers less than n, here n=1000)
        vector<bool> p(1001,true);
        p[0]=p[1]=false;
        for(int i=2;i*i<1001;i++){
            for(int j=2;i*j<1001;j++) p[i*j]=false;
        }
        
        // Finding number of primes
        for(int i=0;i<n;i++){
            for(int j=2;j<=1000;j++){
                if(p[j] && nums[i]%j==0) s.insert(j);
            }
        }
        
        return s.size();
    }
};