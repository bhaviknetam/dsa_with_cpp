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
    void preorder(TreeNode* root, string& s){
        if(!root){
            s += "N,";
            return;
        }
        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    TreeNode* createTree(int& i, string& s){
        if(i >= s.size()) return nullptr;
        if(s[i] == 'N'){
            i += 2;
            return nullptr;
        }
        string t;
        int j = i;
        while (s[j] != ',') j++;
        int val = stoi(s.substr(i, j - i));
        TreeNode* root = new TreeNode(val);
        i = j + 1;
        root->left = createTree(i, s);
        root->right = createTree(i, s);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return createTree(i, data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));