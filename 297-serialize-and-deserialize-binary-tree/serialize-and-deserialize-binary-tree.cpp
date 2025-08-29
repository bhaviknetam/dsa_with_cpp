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
        s += to_string(root->val);
        s.push_back(',');
        preorder(root->left, s);
        preorder(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        s.pop_back();
        // cout << s << ';';
        return s;
    }

    TreeNode* createTree(int& i, string& s){
        if(s[i] == 'N' || i >= s.size()){
            i++;
            return nullptr;
        }
        string t;
        while(s[i] != ','){
            t.push_back(s[i]);
            i++;
        }
        if(t.empty()) return nullptr;
        int val = stoi(t);
        TreeNode* root = new TreeNode(val);
        i++;
        // cout <<i<<'/';
        root->left = createTree(i, s);
        i++;
        // cout << i << '.';
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