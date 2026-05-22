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

ListNode* f(ListNode* head){
    if(!head)return nullptr;
    
    ListNode* curr = head;
    ListNode* start = head;
    ListNode* _next = head->next;

    while(_next != nullptr){
        curr->next = _next->next;
        _next->next = start;
        start = _next;
        _next = curr->next;
    }
    return start;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return f(head);
    }
};
