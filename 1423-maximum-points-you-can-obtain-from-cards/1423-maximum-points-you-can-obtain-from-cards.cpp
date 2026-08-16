class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
         int n = cardPoints.size();
        int ws = n - k;
        int sum = 0, ans = INT_MAX;
        int start = 0;
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        
        if(ws == 0){
            return totalSum;
        }
        for(int i = 0; i<n; i++){
            sum += cardPoints[i];

            if(i - start + 1 == ws){
                ans = min(ans, sum);
                sum = sum - cardPoints[start];
                start++;
            }
        }
        cout<<ans;
        return totalSum - ans;
    }
};