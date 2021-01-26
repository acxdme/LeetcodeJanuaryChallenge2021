/*
Time complexity :
Space complexity :
My approach :
*/

// dp solution fails because of time constraint , below is the dp approach

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int r =  h.size();
        int c = h[0].size();
        
        int dp[r][c];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<r;i++)
            dp[i][0] = max(abs(h[i][0]-h[i-1][0]),dp[i-1][0]);
        for(int j=1;j<c;j++)
            dp[0][j] = max(abs(h[0][j]-h[0][j-1]),dp[0][j-1]);
        
        for(int i=1;i<r;i++)
        {
            for(int j =1;j<c;j++)
            {
                int m1 = min(dp[i-1][j],dp[j-1][i]);
                int m2 = min(abs(h[i-1][j] - h[i][j]),abs(h[i][j-1]-h[i][j]));
                dp[i][j] = max(m1,m2);
            }
        }
        
        return dp[r-1][c-1];
    }
};
