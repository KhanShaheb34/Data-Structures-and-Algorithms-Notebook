class Solution {
public:
    void solve(int col, int n, vector<vector<string>>&ans, vector<string>&board, vector<int>&left, vector<int>&upperD, vector<int>&lowerD){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
               if(left[row]==0 && upperD[n-1+col-row]==0 && lowerD[row+col]==0){
                   left[row]=1;
                   upperD[n-1+col-row]=1;
                   lowerD[row+col]=1;
                   board[row][col]='Q';
                   solve(col+1, n, ans, board, left, upperD, lowerD);
                   left[row]=0;
                   upperD[n-1+col-row]=0;
                   lowerD[row+col]=0;
                   board[row][col]='.';
               }
        }       
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0; i<n; i++){
            board[i]=s;
        }
        vector<int>left(n,0),upperD(2*n-1,0),lowerD(2*n-1,0);
        solve(0,n,ans,board,left,upperD,lowerD);
        return ans;
    }
};
