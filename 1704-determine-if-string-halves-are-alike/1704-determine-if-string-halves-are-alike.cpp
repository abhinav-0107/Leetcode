class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size(),count=0;
        vector<char>v{'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(find(v.begin(),v.end(),s[i])!=v.end()) count++;
            }
            else{
                if(find(v.begin(),v.end(),s[i])!=v.end()) count--;
            }
        }
        return count==0;
    }
};