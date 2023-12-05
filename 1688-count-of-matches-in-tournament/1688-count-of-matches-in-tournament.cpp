class Solution {
public:
    int numberOfMatches(int n) {
        if(n==1) return 0;
        int p1=0,p2=0;
        if(n%2==0) p1= n/2 + numberOfMatches(n/2);
        else p2= (n-1)/2 + numberOfMatches((n-1)/2+1);
        return p1+p2;
    }
};