/*
Time complexity : O(N)
Space complexity : O(N)
My approach : create a hash-map to store the prefix sum with the corresponging index , let r = TotalSum - x , now for each index check whether prefixSum[i] - r is present or not,
            if its present then calculate the length of the longest subarrray , this subarray is basically the subarray having sum as TotalSum- x, return n minus length of subarray.
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size();
        unordered_map<int,int> ump;// <sum,index>
        ump[0] = -1;
        int sum =0 , r=0, presum =0;
        for(int i=0;i<n;i++)
            sum += nums[i];
        r = sum-x;
        int res =0;
        for(int i=0;i<n;i++)
        {
            presum += nums[i];
            
            if(ump.find(presum - r) != ump.end())
                res = max (res,i-ump[presum-r]);
            ump[presum] = i;
            
        }
        if(res == 0 and sum != x) return -1;
        return  n-res;
    }
};
