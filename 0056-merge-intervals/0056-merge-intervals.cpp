class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        vector<int> temp;
        temp.push_back(intervals[0][0]);
        int second = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (second >= intervals[i][0]) {
                second = max(second, intervals[i][1]);
            } else {
                temp.push_back(second);
                result.push_back(temp);
                temp.clear();
                temp.push_back(intervals[i][0]);
                second = intervals[i][1];
            }
        }
        temp.push_back(second);
        result.push_back(temp);
        return result;
    }
};
