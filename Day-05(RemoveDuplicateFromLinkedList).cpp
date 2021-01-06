/*
Time complexity :
Space complexity :
My approach :
*/


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) { // O(N) space and O(N) time approach
        if(head == NULL) return head;
        unordered_map<int,int> mp; 
        ListNode* temp = head;
        while(temp != NULL)  
        {
            mp[temp->val]++;
            temp = temp->next;
        }
        
        temp = head;
        ListNode*  res = NULL;
        ListNode* result = NULL;
        while(temp != NULL)
        {
            if(mp[temp->val] == 1)
            {
                if(res == NULL)
                { 
                    result = new ListNode(temp->val);
                    res = result;
                }
                else
                {
                    res->next = new ListNode(temp->val);
                    res = res->next;
                }    

            }
            
            temp = temp->next;
        }
        
        
        return result;
    }
};
