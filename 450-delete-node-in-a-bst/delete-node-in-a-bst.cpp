class Solution {
public:
    TreeNode* deleteNode(TreeNode* r, int k) {
        if (!r) return nullptr; 

    
        if (r->val > k) {
            r->left = deleteNode(r->left, k);
        } else if (r->val < k) {
            r->right = deleteNode(r->right, k);
        } else { 
            if (!r->left) {
                TreeNode* temp = r->right;
                delete r;
                return temp;
            } else if (!r->right) {
                TreeNode* temp = r->left;
                delete r;
                return temp;
            } else { 
                TreeNode* successor = r->right;
                while (successor->left) {
                    successor = successor->left;
                }
                r->val = successor->val;
                r->right = deleteNode(r->right, successor->val);
            }
        }
        return r;
    }
};
