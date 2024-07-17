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
    ListNode* deleteMiddle(ListNode* h) {
        if (h == nullptr || h->next == nullptr) {
            return nullptr;
        }

        ListNode* s = h;
        ListNode* f = h->next->next;

        while (f != nullptr && f->next != nullptr) {
            s = s->next;
            f = f->next->next;
        }

        s->next = s->next->next;

        return h;
    }
};
