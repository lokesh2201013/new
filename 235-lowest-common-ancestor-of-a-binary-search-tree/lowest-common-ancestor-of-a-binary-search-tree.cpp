class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        int m = p->val > q->val ? p->val : q->val;
        int mi = q->val < p->val ? q->val : p->val;

        while (r) {
            if (r->val > m) {
                r = r->left;
            } else if (r->val < mi) {
                r = r->right;
            } else {
                break; 
            }
        }

        return r;
    }
};
