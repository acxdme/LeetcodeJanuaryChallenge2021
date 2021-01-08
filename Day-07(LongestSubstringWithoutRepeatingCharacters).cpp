/*
Time complexity : O(N)
Space complexity : O(N)
My approach : use of unordered map which stores char with its index.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> ump; // (char,index)
        int i=0 , j=0;
        int res=0;
        
        while(j<n)
        {
            if(ump.find(s[j]) != ump.end() ) 
            {
                i = max(i,1+ ump[s[j]]); // update i to a valid position only when it lies between  left and  right (region on interest)
            }
       
             ump[s[j]] = j;  // update the char with the latest index value 
             res = max(res, j-i+1); 
             j++;
        }
       
        
        return res;
    }
};
