class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int plantCount = 0;
        int currPlot = 0;

        if(n == 0)
            return true;

        if( flowerbed[currPlot] == 0 && 
            (size == 1 || flowerbed[currPlot + 1] == 0))
        {
            plantCount++;
            currPlot += 1;
        }

        for(currPlot += 2; currPlot < size - 1 && plantCount < n; currPlot++)
        {
            if(flowerbed[currPlot - 2] + flowerbed[currPlot - 1] + flowerbed[currPlot] == 0)
            {
                plantCount++; 
                currPlot++;
            }
        }

        if( plantCount < n && 
            size >= 3 && 
            flowerbed[size - 1] == 0 &&
            flowerbed[size - 2] == 0)
        {
            plantCount++;
        }

        return plantCount == n;
    }
};