class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& grid,
               int count, vector<vector<vector<int>>>& dp) {

        if(i < 0 || j < 0)
            return false;

        // Invalid balance
        if(grid[i][j] == ')')
            count++;
        else
            count--;

             if(count < 0)
            return false;

            if(i == 0 && j == 0)
            return dp[i][j][count] = (count == 0);

        if(dp[i][j][count] != -1)
            return dp[i][j][count];

        // Process current cell
        
       

        // Start cell
        

        // Move left
        if(solve(i, j - 1, grid, count, dp))
            return dp[i][j][count] = true;

        // Move up
        if(solve(i - 1, j, grid, count, dp))
            return dp[i][j][count] = true;

        return dp[i][j][count] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Maximum possible count is m+n
        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(m + n + 1, -1))
        );
        int count=0;
    
        return solve(m - 1, n - 1, grid,count, dp);
    }
};