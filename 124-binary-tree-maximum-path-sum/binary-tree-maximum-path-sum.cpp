class Solution {
public:
    int giv(TreeNode* r, int &sum) {
        if (r == nullptr) return 0;

       
        int ls = max(0, giv(r->left, sum));
        int rs = max(0, giv(r->right, sum));

      
        sum = max(sum, r->val + ls + rs);

 
        return r->val + max(ls, rs);
    }

    int maxPathSum(TreeNode* r) {
        int sum = INT_MIN; 
        giv(r, sum);
        return sum;
    }
};
