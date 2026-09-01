class Solution {
public:
    int di[4] = {0, 0, -1, 1};
    int dj[4] = {-1, 1, 0, 0};

    struct node {
        int r;
        int c;
        int energyLeft;
        int collectedMask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();
        int maxEnergy = energy;

        int litterBit[20][20] = {};
        int litterCnt = 0;
        int startRow = 0;
        int startCol = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(classroom[i][j] == 'S') {
                    startRow = i;
                    startCol = j;
                }
                else if(classroom[i][j] == 'L') {
                    litterBit[i][j] = litterCnt;
                    litterCnt++;
                }
            }
        }

        int allCollected = (1 << litterCnt) - 1;

        if(litterCnt == 0) {
            return 0;
        }

        vector<vector<vector<vector<bool>>>> vis(n,vector<vector<vector<bool>>>(m,vector<vector<bool>>(maxEnergy + 1,vector<bool>(1 << litterCnt, false))));


        queue<node> q;
        q.push({startRow, startCol, maxEnergy, 0});
        vis[startRow][startCol][maxEnergy][0] = true;

        int moves = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                node curr = q.front();
                q.pop();

                if(curr.collectedMask == allCollected) {
                    return moves;
                }

                if(curr.energyLeft == 0) {
                    continue;
                }

                for(int k = 0; k < 4; k++) {
                    int nextRow = curr.r + di[k];
                    int nextCol = curr.c + dj[k];

                    if(nextRow < 0 || nextRow >= n ||
                       nextCol < 0 || nextCol >= m) {
                        continue;
                    }

                    char cell = classroom[nextRow][nextCol];

                    if(cell == 'X') {
                        continue;
                    }

                    int nextEnergy = curr.energyLeft - 1;
                    int nextMask = curr.collectedMask;

                    if(cell == 'R') {
                        nextEnergy = maxEnergy;
                    }
                    else if(cell == 'L') {
                        nextMask |= (1 << litterBit[nextRow][nextCol]);
                    }

                    if(!vis[nextRow][nextCol][nextEnergy][nextMask]) {
                        vis[nextRow][nextCol][nextEnergy][nextMask] = true;

                        q.push({
                            nextRow,
                            nextCol,
                            nextEnergy,
                            nextMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};