class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max = 0;
        int sum = 0;

        for(const int& altitude : gain)
        {
            sum += altitude;
            if(sum > max)
                max = sum;
        }

        return max;
    }
};