class Solution {
public:    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int j=0;j<=amount;j++){ 
            if(j%coins[0]==0) prev[j]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notpick=prev[j];
                int pick=0;
                if(j>=coins[i]) pick=curr[j-coins[i]];
                curr[j]=pick+notpick;
            }
            prev=curr;
        }
        return prev[amount];   
    }
};