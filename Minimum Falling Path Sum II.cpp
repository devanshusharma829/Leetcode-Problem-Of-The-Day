class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        vector<int> dp(m);
        vector<int> prevDp(m);

        for(int i=0;i<m;i++) dp[i] = matrix[0][i];
        for(int i=1;i<n;i++){
            prevDp = dp;
            for(int j=0;j<m;j++){
                int minValue = INT_MAX;
                if(i-1>=0) minValue=min(minValue,prevDp[j]);
                if(i-1>=0 && j-1>=0) minValue=min(minValue,prevDp[j-1]);
                if(i-1>=0 && j+1<m)minValue=min(minValue,prevDp[j+1]);
                
                dp[j]= minValue + matrix[i][j];
            }
        }

        int ans = INT_MAX;
        for(int j=0;j<m;j++) ans = min(ans,dp[j]);
        
        return ans;
    }
};