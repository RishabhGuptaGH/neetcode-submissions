/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListListNode *next;
 *     ListListNode() : val(0), next(nullptr) {}
 *     ListListNode(int x) : val(x), next(nullptr) {}
 *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* reverse(ListNode* head){
    if(head == nullptr || head->next == nullptr)return head;
    ListNode* curr  = head;
    ListNode* start = head;
    ListNode* nex   = curr->next;

    while(curr->next != nullptr){
        nex = curr->next;
        curr->next = nex->next;
        nex->next = start;
        start = nex;     
    }

    return start;
}

void print(ListNode* head){
    ListNode* t = head;
    while(t != nullptr){
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
    return;
}

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* half;
        ListNode* fast = head;

        while(fast != nullptr){
            fast = fast->next;
            if(fast == nullptr){
                half = slow->next;
                slow->next = nullptr;
                break;
            }
            fast = fast->next;
            if(fast == nullptr){
                half = slow->next;
                slow->next = nullptr;
                break;
            }
            slow = slow->next;
        }

        half = reverse(half);
        print(half);

        ListNode* start = head;
        ListNode* nex1;
        ListNode* nex2;

        while(half != nullptr){
            nex1 = head->next;
            nex2 = half->next;
            head->next = half;
            half->next = nex1;
            head = nex1;
            half = nex2;
        }
    }
};
