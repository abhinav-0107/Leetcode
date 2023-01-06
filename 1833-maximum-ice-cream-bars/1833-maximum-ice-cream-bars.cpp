class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int count = 0;
        
        sort(costs.begin(),costs.end());
        
        for(int i = 0 ; i < n ; i++){
            if(costs[i] <= coins){
                count++;
                coins -= costs[i];
            }    
        }
        
        return count;
    }
};