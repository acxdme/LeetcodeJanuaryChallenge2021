/*
Time complexity : O(n+m)
Space complexity : O(1)
My approach : Use a merger pointer to slice throught the sorted linked list.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL ) return l1;
        ListNode* merger ;
        
        if(l1->val <= l2 ->val)
        {
            merger = l1;
            l1 = l1->next;
        }
        
        else 
        {
            merger = l2;
            l2 = l2->next;
        }
        ListNode* res = merger;
        while(l1!=NULL and l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                merger->next = l1;
                l1= l1->next;
                merger = merger->next;
            }
            else
            {
                merger->next = l2;
                l2= l2->next;
                merger = merger->next;
            }
        }
        if(l1 == NULL ) merger->next = l2;
        if(l2 == NULL ) merger->next = l1;
        
        return res;
    }
};
