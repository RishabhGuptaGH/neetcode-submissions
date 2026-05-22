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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        ListNode* prev;
        int c = 0;
        while(l1 || l2){
            ListNode* n = new ListNode();
            prev = curr;
            if(!l1){
                int v = (l2->val + c)%10;
                c = (l2->val + c)/10;
                curr->val = v;
                curr->next = n;
                curr = n;
                l2 = l2->next;
            }
            else if(!l2){
                int v = (l1->val + c)%10;
                c = (l1->val + c)/10;
                curr->val = v;
                curr->next = n;
                curr = n;
                l1 = l1->next;
            }
            else{
                int v = (l1->val + l2->val + c)%10;
                c = (l1->val + l2->val + c)/10;
                curr->val = v;
                curr->next = n;
                curr = n;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if(c==0)prev->next = nullptr;
        else curr->val = c;
        return head;
    }
};
