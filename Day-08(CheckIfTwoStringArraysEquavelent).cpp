/*
time complexity : O(N)
Space complexity : O(N)
My approach : make temp1 string from word1 and temp2 from word2 then compare.
*/
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int n = word1.size();
        int m = word2.size();
        
        string temp1,temp2;
        for(int i=0;i<n;i++)
        {
            temp1 += word1[i];
        }
        for(int i=0;i<m;i++)
        {
            temp2 +=word2[i];
        }
        
        return temp1 == temp2;
        
        
    }
};
