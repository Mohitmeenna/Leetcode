class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        auto upper = upper_bound(nums.begin(), nums.end(), target);
        vector<int> ans;
        if (lower == nums.end() || *lower != target)
            return {-1, -1};

        int first = lower - nums.begin();
        int second = upper - nums.begin() - 1;

        return {first, second};
    }
};