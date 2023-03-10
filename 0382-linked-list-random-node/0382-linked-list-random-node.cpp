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
    ListNode *newHead;

    Solution(ListNode* head) {
        newHead = head;
    }
    
    int getRandom() {
        ListNode *currNode = newHead;
        int randomValue = currNode -> val;
        int indexCount = 1;
        while (currNode != nullptr) {
            if (rand() % indexCount == 0)
                randomValue = currNode -> val;
            currNode = currNode -> next;
            indexCount++;
        }
        return randomValue;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */