class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return false;
        return log2(n) == floor(log2(n)) ;
    }

    // T -> O(n)
    // S -< O(n)    
};