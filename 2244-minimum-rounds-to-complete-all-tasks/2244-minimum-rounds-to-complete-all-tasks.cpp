class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        map<int,int>mp;
        
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        
        int count=0;
        
        for(auto it:mp){
            
            if(it.second<2){
                return -1;
            }
            
            else if(it.second%3==0){
                count+=it.second/3;
            }
            
            else{
                double y=it.second*1.0;
                count+=ceil(y/3);
            }
        }
        
        return count;
    }
};
