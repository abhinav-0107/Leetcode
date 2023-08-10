class Solution {
public:
    int maxProfit(vector<int>& p){
        int n=p.size();
        vector<int> prev(2,0),curr(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit;
                if(buy){
                    int buy=-p[i]+prev[0];
                    int notbuy=prev[1];
                    profit=max(buy,notbuy);
                }
                else{
                    int sell= p[i]+prev[1];
                    int notsell=prev[0];
                    profit=max(sell,notsell);
                }
                curr[buy]=profit;
            }
            prev=curr;
        }
        return prev[1];
    }
};