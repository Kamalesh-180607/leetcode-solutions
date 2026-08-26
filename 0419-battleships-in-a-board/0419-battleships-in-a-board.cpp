class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    int m,n;
    void dfs(vector<vector<char>> &grid,int i,int j)
    {
        grid[i][j]='.';
        for(auto d:dir)
        {
            int ni=i+d[0];
            int nj=j+d[1];

            if(ni<0 || ni>=m || nj<0 || nj>=n || grid[ni][nj]=='.')
            continue;

            dfs(grid,ni,nj);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();

        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!='.')
                {
                    count++;
                    dfs(board,i,j);
                }
            }
        }
        return count;
    }
};