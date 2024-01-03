class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank[0].size();
        int m=bank.size();
        int total=0;
        vector<int>arr(m,0);
        vector<int>arr1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr[i]+=bank[i][j]-'0';
            }
        }
        for(int i=0;i<m;i++){
            if(arr[i]!=0){
                arr1.push_back(arr[i]);
            }
            
        }
       
        
        
        if(arr1.size()!=0){
        
            for(int i=0;i<arr1.size()-1;i++){
            total+=arr1[i]*arr1[i+1];
            } 
        
        }
        return total;
    }
};