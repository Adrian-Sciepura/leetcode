class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int length = nums.size();
        int firstNum = numeric_limits<int>::max();
        int secondNum = numeric_limits<int>::max();
        
        if(length < 3)
            return false;
        
        for(const int& num : nums)
        {
            if(num <= firstNum)
                firstNum = num;
            else if(num <= secondNum)
                secondNum = num;
            else
                return true;
        }


        return false;
    }
};