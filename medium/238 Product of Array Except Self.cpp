class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> result(length, 0);

        int left = 1;
        for(int i = 0; i < length; i++)
        {
            result[i] = left;
            left *= nums[i];
        }

        int right = 1;
        for(int i = length - 1; i >= 0 ; i--)
        {
            result[i] *= right;
            right *= nums[i];
        }

        return result;
    }
};