class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mps,mpt;
        for(int i=0;i<s.size();i++){
            mps[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mpt[t[i]]++;
        }
        if(s.size()>=t.size()){
            for(int i=0;i<s.size();i++){
                if(mpt.find(s[i])!=mpt.end()){
                    if(mpt[s[i]]!=mps[s[i]]){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        else{
            for(int i=0;i<t.size();i++){
                if(mpt.find(t[i])!=mpt.end()){
                    if(mpt[t[i]]!=mps[t[i]]){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }            
        }
        return true;
        
    }
};