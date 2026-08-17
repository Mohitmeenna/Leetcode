class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int ans = 0, start = 0;
        unordered_map<int, int> mp;
        for (int end = 0; end < s.size(); end++) {
            mp[s[end]]++;

            while (end - start + 1 > mp.size()) {
                mp[s[start]]--;
                if (mp[s[start]] == 0) {
                    mp.erase(s[start]);
                }
                start++;
            }

            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};