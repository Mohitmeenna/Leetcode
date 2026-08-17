class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        unordered_map<int, int> mp;
        int mostFreq = 0;
        int ans = 0;
        for (int end = 0; end < s.size(); end++) {
            mp[s[end]]++;
            mostFreq = max(mostFreq, mp[s[end]]);

            while (mostFreq + k < (end - start + 1)) {
                mp[s[start]]--;
                start++;
            }

            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};