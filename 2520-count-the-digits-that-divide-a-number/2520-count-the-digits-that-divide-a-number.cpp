class Solution {
public:
    int countDigits(int num) {
        int val=num;
        int count=0;
        while(num){
            if(val%(num%10)==0)count++;
            num/=10;
        }
        return count;
    }
};