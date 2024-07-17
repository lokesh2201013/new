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
    bool hasCycle(ListNode *h) {
        if (h == nullptr || h->next == nullptr) {
            return false;
        }
        
        ListNode* s = h;
        ListNode* f = h;
        
        while (f != nullptr && f->next != nullptr) {
            f = f->next->next;
            s = s->next;
            if (f == s) {
                return true;
            }
        }
        return false;
    }
};
