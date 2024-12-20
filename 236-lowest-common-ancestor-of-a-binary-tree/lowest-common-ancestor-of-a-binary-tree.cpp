/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
         if(r==NULL||r==q||r==p)return r;
         TreeNode* l=lowestCommonAncestor(r->left,p,q);
         TreeNode* ri=lowestCommonAncestor(r->right,p,q);

         if(l==NULL)return ri;
         if(ri==NULL) return l;
         else return r;
    }
};