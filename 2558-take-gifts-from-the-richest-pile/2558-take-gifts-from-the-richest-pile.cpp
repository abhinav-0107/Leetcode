class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
        int n=g.size();
        long long ans=0;
        priority_queue<int>pq;
        
        for(auto i:g) pq.push(i);
        
        while(k-- && !pq.empty()){
            int t=pq.top();
            pq.pop();
            pq.push(floor(sqrt(t)));
        }
        
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};