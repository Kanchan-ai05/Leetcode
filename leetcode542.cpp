
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        // Step 1: Push all zero cells into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Four directions: up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Step 2: BFS
        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                // Check boundaries and visited status
                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    dist[nx][ny] == -1) {

                    dist[nx][ny] = dist[x][y] + 1;

                    q.push({nx, ny});
                }
            }
        }

        return dist;
    }
};
