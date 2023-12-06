class Solution {
public:
    
    int totalMoney(int n) {
        int totalMoney = 0;
        for(int i = 1;i <= floor(n/7); i++){
            totalMoney += (7*i+21);
        }
        
        int startingValue = ceil(n/7) + 1;

        for(int i = 0;i< n % 7; i++){
            totalMoney += (startingValue + i);
        }
        
        return totalMoney;
    }
};