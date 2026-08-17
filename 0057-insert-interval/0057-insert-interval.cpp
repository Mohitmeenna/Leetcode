class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int first = intervals[0][0];
        int second = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (second < intervals[i][0]) {
                ans.push_back({first, second});
                first = intervals[i][0];
                second = intervals[i][1];
            } else {
                second = max(second, intervals[i][1]);
            }
        }
        ans.push_back({first, second});

        return ans;
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        intervals.push_back({newInterval[0], newInterval[1]});
        vector<vector<int>> ans;

        return merge(intervals);
    }
};