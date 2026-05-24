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
    bool hasCycle(ListNode* head) {
        if(!head)return false;

        bool ans = false;
        ListNode* fast = head; ListNode* slow = head;

        while(fast){
            fast = fast->next;
            if(!fast)break;
            if(slow == fast){
                ans = true;
                break;
            }
            slow = slow->next;
            fast = fast->next;
            if(slow == fast){
                ans = true;
                break;
            }
        }
        return ans;
    }
};
