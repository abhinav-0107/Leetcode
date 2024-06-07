class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int wordLength = 0;
        int j = n-1;

        while(s[n-1] == ' ' && j >= 0 && !isalpha(s[--j])){
        }

        for(int i = j ; i >= 0 ; i--){
            if(isalpha(s[i])) wordLength++;
            else break;
        }

        return wordLength;
    }
};