class Solution {
public:
    int addDigits(int n1) {
        int n2=0;
        while(n1>9){
            while(n1>0){
                n2+=(n1%10);
                n1/=10;
            }
            n1=n2;
            n2=0;
        }
        return n1;
    }
};