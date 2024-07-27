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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* s; 


        if (t1->val <= t2->val) {
            s = t1;
            t1 = t1->next;
        } else {
            s = t2;
            t2 = t2->next;
        }

        ListNode* current = s;


        while (t1 != nullptr && t2 != nullptr) {
            if (t1->val <= t2->val) {
                current->next = t1;
                t1 = t1->next;
            } else {
                current->next = t2;
                t2 = t2->next;
            }
            current = current->next;
        }

      
        if (t1 != nullptr) {
            current->next = t1;
        } else {
            current->next = t2;
        }

        return s;
    }
};
