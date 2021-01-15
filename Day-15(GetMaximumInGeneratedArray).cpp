/*
Time complexity : O(N)
Space complexity : O(N)
My approach : use dynammic programming concept.
*/

class Solution 
{
public:
    int getMaximumGenerated(int n) 
    {
        int dp[101];
        dp[0] = 0;
        dp[1] = 1;
        int res =0;
        if(n>0)  res =1;
        for(int k=2;k<=n;k++)
        {
            if(k%2 == 0) dp[k] = dp[k/2];
            else dp[k] = dp[k/2] + dp[k/2 + 1];
            res = max(res,dp[k]);
        }  
        return res;
    }
};
