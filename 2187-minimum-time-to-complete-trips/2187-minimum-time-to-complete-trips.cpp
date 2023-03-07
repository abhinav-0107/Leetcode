class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        long long int maxtime=(long long)(time.back())*totalTrips;
        long long int low=0,high=maxtime;
        long long mid;
        while(low<=high){
            mid=(low+high)/2;
            long long int x=0;
            for(int i=0;i<time.size();i++){
                x+=mid/time[i];;
            }
            if(x<totalTrips){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};