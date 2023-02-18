class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int temp = n,ans = 0;
        
        while(temp--){
            int max_ele = 0;
            for(int i = 0 ; i < m ; i++){
                auto max_ele_it = max_element(grid[i].begin(),grid[i].end());
                max_ele = max(max_ele,*max_ele_it);
                grid[i].erase(max_ele_it);
            }
            ans += max_ele;
        }     
        
        return ans;
    }
};