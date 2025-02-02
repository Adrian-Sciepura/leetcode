class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result(2);
        
        set<int> nums1_set;
        set<int> nums2_set;

        for(const int& num : nums1)
            nums1_set.insert(num);

        for(const int& num : nums2)
            nums2_set.insert(num);

        set_difference( nums1_set.begin(), nums1_set.end(),
                        nums2_set.begin(), nums2_set.end(),
                        back_inserter(result[0]));

        set_difference( nums2_set.begin(), nums2_set.end(),
                        nums1_set.begin(), nums1_set.end(),
                        back_inserter(result[1]));

        return result;
    }
};