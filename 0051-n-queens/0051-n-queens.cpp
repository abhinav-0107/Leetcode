class Solution {
public:
    vector<vector<string>>ans;
    
    bool isSafe(int row,int col,vector<string>& board,int n){
        int r=row,c=col;
//      For left
        while(c>=0){
            if(board[r][c]=='Q')return false;
            c--;
        }
//      For upper diagonal
        c=col;
        r=row;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q')return false;
            r--;
            c--;
        }
//      For lower diagonal
        r=row;
        c=col;
        while(r<n && c>=0){
            if(board[r][c]=='Q')return false;
            c--;
            r++;
        }
        return true;
    }
    
    void f(int col,vector<string>& board,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                f(col+1,board,n);
                board[row][col]='.'; // BackTracking step!
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        f(0,board,n);
        return ans;
    }
};