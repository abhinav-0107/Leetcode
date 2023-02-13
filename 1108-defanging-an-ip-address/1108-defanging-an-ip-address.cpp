class Solution {
public:
    string defangIPaddr(string address) {
        string defan = "";
        for(auto i : address){
            if(i == '.'){
                defan += "[.]";
            }
            else{
                defan += i;
            }
        }
        return defan;
    }
};