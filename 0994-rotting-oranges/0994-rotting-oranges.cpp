class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int freshCount = 0;

        // Step 1: find all initially rotten oranges and count fresh ones
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }

        // Step 2: no fresh oranges means 0 minutes needed
        if (freshCount == 0) return 0;

        int minutes = 0;
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        // Step 3: multi-source BFS, level by level
        while (!q.empty()) {
            int size = q.size();
            bool rottedThisRound = false;

            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = row + dr[d];
                    int nc = col + dc[d];

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        freshCount--;
                        rottedThisRound = true;
                        q.push({nr, nc});
                    }
                }
            }

            if (rottedThisRound) minutes++;
        }

        // Step 4: check if any fresh orange never rotted
        return freshCount == 0 ? minutes : -1;
    }
};