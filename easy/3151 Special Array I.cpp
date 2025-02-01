class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int length = nums.size();

        for(int i = 1; i < length; i++)
            if(nums[i - 1] % 2 == nums[i] % 2)
                return false;

        return true;   
    }
};