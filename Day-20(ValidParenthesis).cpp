/*
Time complexity : O(N)
Space complexity: O(N)
My approach : Use of stack to store the occurence of open brackets , for each closing bracket check if the open part is top of stack or not
*/

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if( n < 2)  return false;
        stack<char> stk;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' or s[i] == '[' or s[i] == '{')  //  "()[]{}"
            {
                stk.push(s[i]);
            }
            else
            {
                if(stk.size() == 0 )  return false;
               if(s[i]  == ')' and stk.top() != '(') return false;
               else if(s[i] == ']' and stk.top() != '[') return false;
               else if(s[i] == '}' and stk.top() != '{') return false;
               else stk.pop();
            }
            
        }
        
        return stk.empty();
    }
};
