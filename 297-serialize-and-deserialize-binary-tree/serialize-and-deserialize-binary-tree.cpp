class Codec {
public:
    string serialize(TreeNode* r) {
        if (!r) return "";
        queue<TreeNode*> q;
        q.push(r);
        string res;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                res += "-1001,";
            }
        }
        res.pop_back();
        return res;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<int> values = parseData(data);
        TreeNode* r = new TreeNode(values[0]);
        queue<TreeNode*> q;
        q.push(r);
        int i = 1;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (values[i] != -1001) {
                node->left = new TreeNode(values[i]);
                q.push(node->left);
            }
            i++;
            if (i < values.size() && values[i] != -1001) {
                node->right = new TreeNode(values[i]);
                q.push(node->right);
            }
            i++;
        }
        return r;
    }

private:
    vector<int> parseData(const string& data) {
        vector<int> res;
        stringstream ss(data);
        string item;
        while (getline(ss, item, ',')) {
            res.push_back(stoi(item));
        }
        return res;
    }
};
