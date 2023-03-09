/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      if(!head || !head->next) return NULL;
        ListNode *slow=head , *fast=head;
        bool cycle_exist=false;
       while(fast!=NULL&&fast->next!=NULL)
       {
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast)
           {
               cycle_exist=true;
               break;
           }
       }
        if(cycle_exist)
        {
        fast=head;
        while(fast!=slow)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        }
        else
            return NULL;
    }
};