class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int length = nums.size();
        int maxSum = 0;
        int sum = 0;
        
        for(int i = 0; i < k; i++)
        {
            maxSum += nums[i];
        }

        sum = maxSum;
        for(int i = k; i < length; i++)
        {
            sum += nums[i];
            sum -= nums[i - k];

            if(sum > maxSum)
                maxSum = sum;
        }

        return static_cast<double>(maxSum) / k;
    }
};