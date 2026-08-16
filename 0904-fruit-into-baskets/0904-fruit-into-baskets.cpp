class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0, ans = 0;
        unordered_map<int, int> mp;

        for (int end = 0; end < fruits.size(); end++) {
            mp[fruits[end]]++;

            while (mp.size() > 2) {
                mp[fruits[start]]--;

                if (mp[fruits[start]] == 0) {
                    mp.erase(fruits[start]);
                }

                start++;
            }

            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};