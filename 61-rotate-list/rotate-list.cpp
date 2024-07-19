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
    ListNode* find(ListNode* head, int n) {
        ListNode* curr = head;
        while (n > 1) {
            curr = curr->next;
            n--;
        }
        return curr;
    }

    ListNode* rotateRight(ListNode* h, int k) {
        if (!h || !h->next || k == 0) return h;

        ListNode* t = h;
        int l = 1;
        while (t->next != nullptr) {
            l++;
            t = t->next;
        }
        k %= l;
        if (k == 0) return h;
        t->next = h;

        ListNode* ne = find(h, l - k);
        h = ne->next;
        ne->next = nullptr;

        return h;
    }
};
