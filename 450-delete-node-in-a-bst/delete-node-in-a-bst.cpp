class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int> inorder;

        inorderTraversal(root, inorder);
  
        auto it = find(inorder.begin(), inorder.end(), key);
        if (it != inorder.end()) {
            inorder.erase(it);
        }
        
        
        return buildTree(inorder, 0, inorder.size() - 1);
    }

private:
    
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if (root == nullptr) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }


    TreeNode* buildTree(const vector<int>& inorder, int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        
        root->left = buildTree(inorder, left, mid - 1);
        root->right = buildTree(inorder, mid + 1, right);
        
        return root;
    }
};
