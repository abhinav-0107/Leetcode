class Solution {
public:
    string largestGoodInteger(string num) {
        set<string>s;
        for(int i=2;i<num.size();i++){
            if(num[i]==num[i-1] && num[i-1]==num[i-2])s.insert(num.substr(i-2,3));
        }
        if(s.size()==0)return "";
        auto i=s.end();
        i--;
        return *i; 
    }
};