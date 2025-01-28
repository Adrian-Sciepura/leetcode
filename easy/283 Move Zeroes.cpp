class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        int index = 0;

        for(int i = 0; i < length; i++)
        {
            if(nums[i] != 0)
            {
                nums[index] = nums[i];
                index++;
            }
        }

        while(index < length)
        {
            nums[index] = 0;
            index++;
        }
    }
};