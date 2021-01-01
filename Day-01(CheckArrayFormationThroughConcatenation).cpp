/*
Time complexity : O(N^3)
Space complexity : O(N^2)
My approach :  hash Check and LCS.
*/
class Solution
{
public:
    
    bool LCS(vector<int>& piece,vector<int>& a)
    {
        int n = piece.size();
        int m = a.size();
        int dp[n+1][m+1] ;
        memset(dp,0,sizeof(dp));
         int mx = INT_MIN;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(piece[i-1] == a[j-1])
                  dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
                mx = max(dp[i][j],mx);
            }
            
            
        }
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
         cout<<mx<< " "<<n <<endl;
        return  mx == n;
    
    }
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        // Algorithm 
        // Longestcommonsubstring(pieces[i],arr) == pieces[i].size() for true condition.
        // 
        
        
        int n = pieces.size();
        int m = arr.size();
        
        unordered_set<int> us1;
        unordered_set<int> us2;
        
        for(int i : arr)
            us1.insert(i);
        
        
        
        
        for(auto it : pieces)
        {
            for(int i : it)
                us2.insert(i);    
            // if(LCS(it,arr) == false )  return false; 
        }
        
        if(us1.size() != us2.size() or (us1 != us2)) return false;
        
        for(int i =0;i<n;i++)
        {
            if(LCS(pieces[i],arr) == false )  return false;
        }
        
        
        
        
        return true;
        
        
    }
};
