class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return -1;
        int N = grid.size();
        queue<pair<int, int>> q;
        q.push({0, 0});
        int count = 0;
        grid[0][0] = 1;
        pair<int, int> curr;
        int i, j;
        int dirs_i[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int dirs_j[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            i = curr.first;
            j = curr.second;

            count = grid[i][j];

            if (i == N - 1 && j == N - 1)
                return grid[i][j];
            for (int k = 0; k < 8; k++) {
                int n_i = i + dirs_i[k];
                int n_j = j + dirs_j[k];
                if (n_i < 0 || n_i >= N) continue;
                if (n_j < 0 || n_j >= N) continue;
                if (grid[n_i][n_j] == 0) {
                    grid[n_i][n_j] = count + 1;
                    q.push({n_i, n_j});
                }
            }
            
        }
        return -1;
    }
};