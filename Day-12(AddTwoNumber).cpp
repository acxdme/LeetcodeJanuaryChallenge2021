/*
Time complexity : O(N)  
Space complexity : O(N)
My approach :  travese through both lists simulaneouly calculate the value of sum and carry and construct the nodes.
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head = NULL ,*temp ;
        int sum =0, carry =0;
        while(l1 or l2)
        { 
             int  t1 = (l1 == NULL) ? 0 : l1->val;
             int t2 = (l2 == NULL) ? 0 : l2->val;
             sum = t1 + t2 + carry;
             carry = sum/10;
             sum = sum %10;
            if( head == NULL)  
            {
                temp = new ListNode(sum);
                head = temp;
            }
            else
            {
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
            
            if(l1!=NULL) l1= l1->next;
            if(l2!=NULL) l2 = l2->next;     
        }
        
        if(carry != 0) temp->next = new ListNode(carry);
        
        return head;
        
    }
};


