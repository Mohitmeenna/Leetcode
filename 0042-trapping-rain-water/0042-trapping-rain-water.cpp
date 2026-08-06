class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left = 0;
        int right = n - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                }
                water +=
                    (leftMax - height[left] < 0) ? 0 : (leftMax - height[left]);
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                }
                water += (rightMax - height[right]) < 0
                             ? 0
                             : (rightMax - height[right]);

                right--;
            }
        }

        return water;
    }
};