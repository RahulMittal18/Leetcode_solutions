class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& g) {
        queue<array<int, 3>> ts;
        priority_queue<array<int, 3>> pq;
        int dir[5] = {1, 0, -1, 0, 1}, n = g.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j])
                    ts.push({1, i, j});
        while (!ts.empty()) {
            auto [sf, i, j] = ts.front(); ts.pop();
            // if (g[i][j] < sf)
            //     continue;
            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d], y = j + dir[d + 1];
                if (min(x, y) >= 0 && max(x, y) < n && (g[x][y] == 0 ||  g[x][y] > sf + 1)) {
                    g[x][y] = sf + 1;
                    ts.push({sf + 1, x, y});
                }
            }
        }
        pq.push({g[0][0], 0, 0});
        while (!pq.empty()) {
            auto [sf, i, j] = pq.top(); pq.pop();
            if (i == n - 1 && j == n - 1)
                return sf - 1;
            if (g[i][j] == -1)
                continue;
            g[i][j] = -1;
            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d], y = j + dir[d + 1];
                if (min(x, y) >= 0 && max(x, y) < n && g[x][y] != -1) {
                    pq.push({min(sf, g[x][y]), x, y});
                }
            }
        }
        return 0;
    }
};