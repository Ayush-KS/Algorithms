class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if(!n)
            return 0;
        
        if(k >n /2) {
            int ans = 0;
            for (int i=1; i<n; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
        
        vector<vector<int>> dp(2, vector<int>(n, 0));
        
        for(int i = 1; i <= k; i++) {
            int maxDiff = INT_MIN;
            for(int j = 1; j < n; j++) {
                maxDiff = max(maxDiff, dp[0][j - 1] - prices[j - 1]);
                dp[1][j] = max(dp[1][j - 1], prices[j] + maxDiff);
            }
            dp[0] = dp[1];
            dp[1] = vector<int>(n, 0);
        }
        
        return dp[0][n - 1];
    }
};