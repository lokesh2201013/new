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

    ListNode* getkth(ListNode* curr, int k) {
        while (curr != nullptr && k > 1) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
    void rev(ListNode*& head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    ListNode* reverseKGroup(ListNode* h, int k) {
        ListNode* t = h;
        ListNode* prev = nullptr;

        while (t != nullptr) {
            ListNode* kth = getkth(t, k);
            if (kth == nullptr) {
                if (prev) {
                    prev->next = t;
                }
                break;
            }
            ListNode* nn = kth->next;
            kth->next = nullptr;

            ListNode* temp = t;
            rev(temp);

            if (t == h) {
                h = kth;
            } else {
                prev->next = kth;
            }

            prev = t;
            t->next = nn;
            t = nn;
        }

        return h;
    }
};
