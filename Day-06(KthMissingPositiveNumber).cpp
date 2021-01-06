/*
Time complexity :
Space complexity : O(N) for the unordered set used
My approach : insert all the array elements into the unordered set, while the kth missing number is not found check for each number starting from 1 whether its present in the set 
              or not.
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int n = arr.size();
        unordered_set<int> us;
        for(int i=0;i<n;i++)
            us.insert(arr[i]);
            
        int temp =0,i=1;
        while(temp<k) // while the kth missing number is not found.
        {
            if(us.find(i)==us.end()) // if i is not found increment the value of temp
                temp++;
            i++;
        }
        
        return i-1;
    }
};
