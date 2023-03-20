class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int m = f.size();
        vector <int> ind;
        
        for(int i = 0 ; i<m ; i++){ 
            if(f[i] == 1) ind.push_back(i);
        }
        
        if(ind.size() == 0) n -= ceil((float)(m)/2);
        else {
            
            for(int i = 0 ; i < ind.size()-1 ; i++){
                int num = (ind[i+1] - ind[i]) - 1; //Number of zeros b/w to consecutive 1
                n -= (ceil((float)num/2)-1);
            }

            int a = ind.front();
            int b = m - ind.back()-1;
            n -= floor((float)a/2); //1s that can be placed in the front of the flowerbed array
            n -= floor((float)b/2); //1s that can be placed in the end of the flowerbed array
    
        }
            
        return n<=0;
    }
};