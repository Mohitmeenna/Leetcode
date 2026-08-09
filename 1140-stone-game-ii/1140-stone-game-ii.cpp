class Solution {
private:
    int dfs(vector<int>& piles, int i, int M, bool alice,
            vector<vector<vector<int>>>& dp) {
        if (i == piles.size()) {
            return 0;
        }

        if (dp[alice][i][M] != -1) {
            return dp[alice][i][M];
        }

        int res = alice ? 0 : INT_MAX;
        int total = 0;
        for (int X = 1; X <= 2 * M && i + X <= piles.size(); ++X) {
            total += piles[i + X - 1];
            if (alice) {
                res =
                    max(res, total + dfs(piles, i + X, max(M, X), !alice, dp));
            } else {
                res = min(res, dfs(piles, i + X, max(M, X), !alice, dp));
            }
        }

        dp[alice][i][M] = res;
        return res;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(
            2, vector<vector<int>>(n, vector<int>(n * 2 + 1, -1)));
        return dfs(piles, 0, 1, true, dp);
    }
};
