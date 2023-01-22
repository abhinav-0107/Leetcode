class Solution {
public:
    vector<vector<string>>ans;
    bool ispalindrome(string s){
        string str=s;
        reverse(str.begin(),str.end());
        return str==s;
    }
    
    void part(string& s,vector<string> &temp,int i){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(ispalindrome(s.substr(i,j-i+1))){
                temp.push_back(s.substr(i,j-i+1));
                part(s,temp,j+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        part(s,temp,0);
        return ans;
    }
};