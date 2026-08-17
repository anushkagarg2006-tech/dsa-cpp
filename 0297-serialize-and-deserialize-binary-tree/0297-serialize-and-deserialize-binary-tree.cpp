/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Serialize: tree -> string
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }
    
    void serializeHelper(TreeNode* root, string& result) {
        if (!root) {
            result += "null,";   // null marker
            return;
        }
        result += to_string(root->val) + ",";
        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }

    // Deserialize: string -> tree
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserializeHelper(data, pos);
    }
    
    TreeNode* deserializeHelper(string& data, int& pos) {
        // agla token nikalo (comma tak)
        int comma = data.find(',', pos);
        string token = data.substr(pos, comma - pos);
        pos = comma + 1;
        
        if (token == "null") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserializeHelper(data, pos);
        root->right = deserializeHelper(data, pos);
        return root;
    }
};