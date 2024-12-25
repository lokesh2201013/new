/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* r) {
        if(r==NULL)return {};
        queue<pair<TreeNode*,int>>q;
        map<int,vector<int>>m;
        q.push({r,0});
        while(!q.empty()){
           m[q.front().second].push_back(q.front().first->val);

           if(q.front().first->left!=NULL) q.push({q.front().first->left,q.front().second+1});
           
           if(q.front().first->right!=NULL) q.push({q.front().first->right,q.front().second+1});

           q.pop();
        }
        vector<int>re;
        for(auto it:m){
            re.push_back(*max_element(it.second.begin(),it.second.end()));
        }
        return re;
    }
};