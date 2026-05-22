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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return nullptr;

        int count = 0;
        ListNode* t = head;
        while(t){
            t = t->next;
            count++;
        }

        int idx = count - n;
        if(idx == 0)return head->next;
        
        t = head;
        while(idx != 1){
            t = t->next;
            idx--;
        }
        t->next = t->next->next;
        return head;
    }
};
