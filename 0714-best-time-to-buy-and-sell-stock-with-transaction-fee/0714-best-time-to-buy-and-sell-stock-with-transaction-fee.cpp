class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n=p.size();
        vector<int> prev(2,0), curr(2,0);
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<=1;b++){
                int profit;
                if(b){
                    int buy= -p[i]+prev[0];
                    int notbuy= prev[1];
                    profit=max(buy,notbuy);
                }
                else{
                    int sell= p[i]-fee+prev[1];
                    int notsell= prev[0];
                    profit=max(sell,notsell);
                }
                curr[b]=profit;
            }
            prev=curr;
        }
        return prev[1];
    }
};
