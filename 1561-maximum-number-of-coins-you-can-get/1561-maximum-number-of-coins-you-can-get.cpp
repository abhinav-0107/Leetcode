class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int sum=0,n=piles.size()/3;
        for(int i=3*n-2;n--;i-=2) sum+=piles[i];
        return sum;
    }
};