/*
Time complexity :  O(nLogn)
Space complexity : O(k)
My approach : Use of a min heap to store the k minimum elements in it , then return the top as answer for the kth largest element in the array.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
      priority_queue<int,vector<int>,greater<int>> pq;
      int n = nums.size();
       for(int i=0;i<n;i++)
       {
           pq.push(nums[i]);
           
           if(pq.size() > k)
               pq.pop();
       }
        int res = pq.top();
        
        return res;
    }
};

