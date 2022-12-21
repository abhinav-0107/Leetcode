class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j]!='.'){
                    int val=b[i][j];   
                    for(int k=0;k<9;k++){
                        if(b[i][k]==val && k!=j){
                            return false;
                        }
                        if(b[k][j]==val && k!=i){
                            return false;
                        }
                        if(b[3*(i/3)+k/3][3*(j/3)+k%3]==val && i!=3*(i/3)+k/3 && j!=3*(j/3)+k%3){
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//     bool isval(vector<vector<char>>& b,char val,int row,int col){
//         for(int j=0;j<9;j++){
//             if(b[row][j]==val && j!=col){
//                 return false;
//             }
//         }
//         for(int i=0;i<9 ;i++){
//             if(b[i][col]==val && i!=row){
//                 return false;
//             }
//         }
//         int r,c;  
//         if(row<3 && col<3)c=0,r=0; 
//         else if(row>=3 && row<6 && col<3)c=0,r=3;
//         else if(row>=6 && col<3)c=0,r=6;
//         else if(col>=3 && col<6 && row<3)c=3,r=0;
//         else if(row>=3 && row<6 && col>=3 && col<6)c=3,r=3;
//         else if(row>=6 && col>=3 && col<6)c=3,r=6;
//         else if(col>=6 && row<3)c=6,r=0;
//         else if(col>=6 && row<6 && row>=3)c=6,r=3;
//         else if(col>=6 && row>=6)c=6,r=6;
//         for(int i=r;i<r+3;i++){
//             for(int j=c;j<c+3;j++){
//                 if(b[i][j]!='.'){
//                     if(val==b[i][j] && i!=row && j!=col){
//                         return false;
//                     }
//                 }
//             }
//         }
//         return true;
//     }
    
//     bool isValidSudoku(vector<vector<char>>& b) {
//         for(int i=0;i<9;i++){
//             for(int j=0;j<9;j++){
//                 if(b[i][j]!='.'){
//                     if(!isval(b,b[i][j],i,j)){
//                         return false;
//                     }
//                 }
//             }
//         }
//         return true;
//     }
};