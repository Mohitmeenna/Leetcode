class Solution {
private:
    void dfs(int n, int m, int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int newRow = delRow[i] + row;
            int newCol = delCol[i] + col;
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !vis[newRow][newCol] && grid[newRow][newCol] == '1') {
                dfs(n, m, newRow, newCol, grid, vis);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(n, m, i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};