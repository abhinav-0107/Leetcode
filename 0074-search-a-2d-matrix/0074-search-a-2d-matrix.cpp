class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mt, int target) {
                int m=mt.size();
        int n=mt[0].size();
        int l=0,h=m-1;
        while(l<=h){
            int m=(l+h)/2;
            if(target>=mt[m][0] && mt[m][n-1]>=target){
                int low=0;
                int high=n-1;
                while(low<=high){
                    int mid=(low+high)/2;
                    if(mt[m][mid]==target){
                        return true;
                    }
                    else if(target<mt[m][mid]){
                        high=mid-1;
                    }
                    else if(target>mt[m][mid]){
                        low=mid+1;
                    }
                }
                return false;
            }
            else if(target<mt[m][0]){
                h=m-1;
            }
            else if(target>mt[m][n-1]){
                l=m+1;
            }
        }
        return false;
    }
};