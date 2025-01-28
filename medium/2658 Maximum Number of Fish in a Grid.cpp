class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        stack<pair<int, int>> check;
        int maxSum = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] > 0)
                {
                    int currentSum = 0;
                    int currentX = j;
                    int currentY = i;
                    check.emplace(currentY, currentX);

                    while(!check.empty())
                    {
                        auto entry = check.top();
                        currentY = entry.first;
                        currentX = entry.second;
                        check.pop();

                        currentSum += grid[currentY][currentX];
                        grid[currentY][currentX] = 0;

                        if(currentY - 1 >= 0 && grid[currentY - 1][currentX] > 0)
                            check.emplace(currentY - 1, currentX);
                        if(currentY + 1 < m && grid[currentY + 1][currentX] > 0)
                            check.emplace(currentY + 1, currentX);
                        
                        if(currentX - 1 >= 0 && grid[currentY][currentX - 1] > 0)
                            check.emplace(currentY, currentX - 1);
                        if(currentX + 1 < n && grid[currentY][currentX + 1] > 0)
                            check.emplace(currentY, currentX + 1);
                    }

                    if(currentSum > maxSum)
                        maxSum = currentSum;
                }
            }
        }
        
        return maxSum;
    }
};