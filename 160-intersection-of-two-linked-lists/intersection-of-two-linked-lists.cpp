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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> m;
        ListNode* t = headA;
        
        while (t != nullptr) {
            m[t] = 1;
            t = t->next;
        }
        
        t = headB;
        while (t != nullptr) {
            if (m.find(t) != m.end()) return t;
            t = t->next;
        }
        
        return nullptr;
    }
};
