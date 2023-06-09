class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
         vector<char>&a = letters;
        char t = target, ans;
        int L = 0, R=a.size()-1;
        while(L<=R) {
            int M = L+ (R-L)/2;
            if(a[M] > t && (M-1<0 || a[M-1]<=t) ){
                return a[M];
            }
            if(t>=a[M]) 
                L = M+1;
            else 
                R = M-1;
        }
        return a[0];
    }
    
};