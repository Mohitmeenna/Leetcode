class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int it : nums) {
            if (it != val) {
                nums[i] = it;
                i++;
            }
        }
        return i;
    }
};