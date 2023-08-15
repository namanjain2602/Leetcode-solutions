/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1=new ListNode(0);
          ListNode* head2=new ListNode(0);
          ListNode* temp1=head1;
          ListNode* temp2=head2;
while(head)
{
    if(head->val<x)
    {
      head1->next=head; 
      head1=head; 
    }
    else{
        head2->next=head;
        head2=head;
    }
    head=head->next;
}
head2->next=NULL;
head1->next=temp2->next;
return temp1->next;
    }
};