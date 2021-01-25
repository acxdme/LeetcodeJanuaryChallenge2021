/*
Time complexity : O(N)
Space complexity : O(1)
My approach : check distance between each one occuring is sufficient than k or not.
*/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int place = 0;
        int n = nums.size();
        bool fst = false;
        for(int i=0;i<n;i++)
            if(nums[i] == 1 and fst == false)
            {
                fst =true;
                place = i;
            }
           else if( nums[i] == 1 and fst == true)
           {
                if( i-place < k+1) return false;
                place = i;
           }
        
        return true;
        
    }
};

