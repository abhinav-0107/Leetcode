class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> s;
        vector<vector<int>>ans;
        set<int>a;
        vector<int>ans1;
        vector<int>ans2;
        
        for(int i=0;i<matches.size();i++){
            s.insert(matches[i][1]);
        }
        
        for(int i=0;i<matches.size();i++){
            if(s.end()==s.find(matches[i][0])){
                a.insert(matches[i][0]);        
            }
        }
        set<int>:: iterator it;
        
        for( it=a.begin();it!=a.end();it++){
            ans1.push_back(*it);
        }
        ans.push_back(ans1);
        
        
        map<int,int>mp;
        for(int i=0;i<matches.size();i++){
            mp[matches[i][1]]++;
        }
        for(auto it: mp){
            if(it.second==1){
                ans2.push_back(it.first);
            }
        }
        
        ans.push_back(ans2);
        
        return ans;
        
    }
};