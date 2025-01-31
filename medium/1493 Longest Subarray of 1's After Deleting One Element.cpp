class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int length = nums.size();
        int oneCount = 0;
        int maxFirstSubarrayLength = 0;
        int maxSecondSubarrayLength = 0;

        int currentFirstSubarrayLength = 0;
        int currentSecondSubarrayLength = 0;

        for(const int& num : nums)
        {
            if(num == 1)
            {
                currentFirstSubarrayLength++;
                oneCount++;
            }
            else if(num == 0)
            {
                if(currentFirstSubarrayLength + currentSecondSubarrayLength >
                    maxFirstSubarrayLength + maxSecondSubarrayLength)
                {
                    maxFirstSubarrayLength = currentFirstSubarrayLength;
                    maxSecondSubarrayLength = currentSecondSubarrayLength;
                }
                
                currentSecondSubarrayLength = currentFirstSubarrayLength;
                currentFirstSubarrayLength = 0;
            }
        }

        if(currentFirstSubarrayLength + currentSecondSubarrayLength >
            maxFirstSubarrayLength + maxSecondSubarrayLength)
        {
            maxFirstSubarrayLength = currentFirstSubarrayLength;
            maxSecondSubarrayLength = currentSecondSubarrayLength;
        }

        return  maxFirstSubarrayLength + 
                maxSecondSubarrayLength + 
                (oneCount == length ? -1 : 0);
    }
};