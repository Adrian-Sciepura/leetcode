class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;

        vector<int> rows(m);
        vector<int> cols(n);

        for(int i = 0; i < m; i++)
        {            
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    rows[i] += 1;
                    cols[j] += 1;
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && rows[i] + cols[j] > 2)
                    result += 1;
            }
        }

        return result;
    }
};