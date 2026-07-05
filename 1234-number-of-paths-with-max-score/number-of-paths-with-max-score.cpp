class Solution {

    int n;
    int MOD = 1e9 + 7;
    pair<int, int> solve(int i, int j, vector<string>& board, vector<vector<pair<int, int>>>&dp) {
        if(i < 0 || j < 0){
            return {0, 0};
        }
        if(i == 0 && j == 0){
            return {0, 1};
        }    
        if(board[i][j] == 'X'){
            return {0, 0}; 
        }
        if (dp[i][j] != make_pair(-1, -1)){
            return dp[i][j];
        }
        int upScore = 0,   upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;
        char ch = board[i][j];
        int val = 0;
        if(ch != 'S'){
            val += board[i][j] - '0';
        }
        auto [uscore, p1] = solve(i - 1, j, board, dp);
        upScore = uscore;
        upPaths = p1;
        if (upPaths > 0){
            upScore += val;
        }    
        auto [lscore, p2] = solve(i, j - 1, board, dp);
        leftScore = lscore;
        leftPaths = p2;
        if (leftPaths > 0){
            leftScore += val;
        }
        auto [dscore, p3] = solve(i - 1, j - 1, board, dp);
        diagScore = dscore;
        diagPaths = p3;
        if (diagPaths > 0){
            diagScore += val;
        }   
        int bestScore, bestPaths;
        if (upScore == leftScore && leftScore == diagScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths + diagPaths;
        } else if (upScore == leftScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths;
            if (diagScore > bestScore ) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        } else if (leftScore == diagScore) {
            bestScore = leftScore;
            bestPaths = leftPaths + diagPaths;
            if (upScore > bestScore ) {
                bestScore = upScore; bestPaths = upPaths;
            }
        } else {
            bestScore = upScore; bestPaths = upPaths;
            if (leftScore > bestScore ) {
                bestScore = leftScore; bestPaths = leftPaths;
            }
            if (diagScore > bestScore ) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        }
        return dp[i][j] = {bestScore, bestPaths % MOD};
        
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1,-1}));
        auto result = solve(n - 1, n - 1, board, dp);
        return {result.first, result.second};
    }
};