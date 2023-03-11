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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(ListNode*head,int n){
        //if we have the length of list 0 then we will simply return the nullptr
        if(n<=0){
            return NULL;
        }
		//if we are remaining with only one length then we will make node of it and return it
        if(n==1){
            return new TreeNode(head->val);
        }
        int mid=n/2;
        ListNode*temp=head;
		//traversing to the mid of the list from head
        while(mid--){
            temp=temp->next;
        }
		//then we will get our ans
        TreeNode*ans=new TreeNode(temp->val,solve(head,n/2),solve(temp->next,n-n/2-1));
		//returning the ans
        return ans;
        
    }
    int countNode(ListNode* head)
    {
        ListNode* temp=head;
        int n=0;
         while(temp){
            n++;
            temp=temp->next;
        }
        return n;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return nullptr;
        }
        int n=countNode(head);
		//then we are calling the function
        return solve(head,n);
    }
};