class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        int curr,last1=1,last2=0;
        for(int i=n-1;i>=0;i--){
            int one=0,two=0;
            if(s[i]!='0'){
                one=last1;
                string str;
                str+=s[i];
                str+=s[i+1];
                if(stoi(str)<=26) two=last2;
            }
            curr=one+two;
            last2=last1;
            last1=curr;
        }
        return curr;
    }
};