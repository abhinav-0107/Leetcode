class Solution {
public:
    bool detectCapitalUse(string w) {
        int low=0,up=0;
        for(int i=0;i<w.size();i++){
            if(islower(w[i]))low++;
            else up++;
        }
        if(low==w.size() || up==w.size())return true;
        if(low==w.size()-1 && isupper(w[0]))return true;
        return false;
    }
};