class Solution {
public:
    int di[4] = {0, 0, -1, 1};
    int dj[4] = {1, -1, 0 ,0};
    int n,m;
    bool solve(int i, int j, int idx,vector<vector<char>>& board, string& word){
        if(idx == word.size()){
            return true;
        }
        for(int k =0; k<4; k++){
            int newI = i + di[k];
            int newJ = j + dj[k];
            if(newI < n && newJ < m && newI >= 0 && newJ >= 0 && board[newI][newJ] == word[idx]){
                char letter = board[newI][newJ];
                board[newI][newJ] = '#';
                if(solve(newI, newJ, idx+1, board, word)){
                    return true;
                }
                board[newI][newJ] = letter;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    char ch = board[i][j];
                    board[i][j] = '#';
                    if(solve(i, j, 1, board, word)){
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};