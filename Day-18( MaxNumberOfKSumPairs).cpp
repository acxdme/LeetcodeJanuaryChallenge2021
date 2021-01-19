/*
 Time complexity : O(N log N)
 Space complexity : O(1)
 My approach : This is a simple variation of two sum problem. Just sort the array and use two pointers.
 */
 
 class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {    //1 3 3 3 4
        sort(nums.begin(),nums.end());
        int count =0;
 
        int low =0 ,high = nums.size()-1;
        while(low < high)
        {
            if(nums[low] + nums[high] == k){
                 count++;
                low++;
                high--;
            }
            else if(nums[low] + nums[high] > k)
            {
                high--;
            }
            else
                low++;
        }
        
        
        return count;
        
    }
};
