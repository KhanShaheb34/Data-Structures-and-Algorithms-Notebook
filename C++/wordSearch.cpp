class Solution {
public:
    bool solve(vector<vector<char>>& board, int i, int j, int ind, string& word, int n, int m){
        if(ind == word.size()) return true;
        if(i<0 || j<0 || i>=n || j>=m || word[ind]!=board[i][j])
            return false;
        char temp=board[i][j];
        board[i][j]='#';
        bool ans =  solve(board, i+1, j, ind+1, word, n, m) || 
                    solve(board, i, j+1, ind+1, word, n, m) ||
                    solve(board, i-1, j, ind+1, word, n, m) ||
                    solve(board, i, j-1, ind+1, word, n, m);
                board[i][j]=temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    if(solve(board, i, j, 0, word, n, m))
                        return true;
                }
            }
        }
        return false;
    }
};
