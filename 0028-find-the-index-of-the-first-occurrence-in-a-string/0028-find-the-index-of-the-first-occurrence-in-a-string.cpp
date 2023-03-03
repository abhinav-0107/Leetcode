class Solution {
public:
    int strStr(string h, string n) {
        if(n.size()>h.size())return -1;
        vector<int>ind;
        for(int i=0;i<h.size();i++){
            if(h[i]==n[0])ind.push_back(i);
        }
        for(int i=0;i<ind.size();i++){
            bool f=true;
            for(int j=0;j<n.size();j++){
                if(h[ind[i]+j]!=n[j]){
                    f=false;
                    break;
                }
            }
            if(f)return ind[i];
        }
        return -1;
    }
};