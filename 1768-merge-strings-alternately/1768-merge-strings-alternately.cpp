class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string str="";
        int i;
        for(i=0;i<min(w1.size(),w2.size());i++){
            str+=w1[i];
            str+=w2[i];
        }
        if(w2.size()>w1.size()){
            for(int j=i;j<w2.size();j++) str+=w2[j];
        }
        else{
            for(int j=i;j<w1.size();j++) str+=w1[j];
        }
        return str;
    }
};