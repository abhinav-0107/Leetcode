class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int addrocks) {
        int n=rocks.size();
        vector<int> diff(n,0);
        for(int i=0;i<n;i++){
            diff[i]=capacity[i]-rocks[i];
        }
        sort(diff.begin(),diff.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(diff[i]!=0){
                if(diff[i]<=addrocks){
                    addrocks-=diff[i];
                    diff[i]=0;
                }
            }
            if(diff[i]==0){
                count++;
            }
        }
        return count;
    }
};