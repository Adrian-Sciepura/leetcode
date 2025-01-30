class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int length = nums.size();
        int leftSum = 0;
        int rightSum = 0;

        for(int i = 0; i < length; i++)
        {
            rightSum += nums[i];
        }

        
        for(int i = 0; i < length; i++)
        {
            rightSum -= nums[i];
            if(leftSum == rightSum)
                return i;

            leftSum += nums[i];
        }

        return -1;
    }
};