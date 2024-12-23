class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (root == nullptr) return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<int> nodes;
        inorder(root, nodes);  
        vector<vector<int>> result;

        for (int target : q) {
            int floor = -1, ceil = -1;
            int left = 0, right = nodes.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nodes[mid] == target) {
                    floor = nodes[mid];
                    ceil = nodes[mid];
                    break;
                }
                if (nodes[mid] < target) {
                    floor = nodes[mid];
                    left = mid + 1;
                } else {
                    ceil = nodes[mid];
                    right = mid - 1;
                }
            }
            
            result.push_back({floor, ceil});
        }
        
        return result;
    }
};
