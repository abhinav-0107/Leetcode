class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        priority_queue<pair<int,int>>p;
        vector<int>ans;
        for(int i=0;i<m;i++){
            int low=0,high=n-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(mat[i][mid]==1) low=mid+1;
                else high=mid-1;
            }
            p.push({low,i});
            if(p.size()>k)p.pop();
        }
        while(!p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};







// class Solution {
// public:
//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//         int m=mat.size();
//         int n=mat[0].size();
//         int count=0;
//         vector<pair<int,int>>v;
//         vector<int>ans;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(mat[i][j]==1)count++;
//                 else break;
//             }
//             v.push_back({count,i});
//             count=0;
//         }
//         sort(v.begin(),v.end(),[](pair<int,int> &p1,pair<int,int>&p2){
//             if(p1.first==p2.first) return p1.second<p2.second;
//             return p1.first<p2.first;
//         });
//         int i=0;
//         while(k--){
//             ans.push_back(v[i].second);
//             i++;
//         }
//         return ans;
//     }
// };