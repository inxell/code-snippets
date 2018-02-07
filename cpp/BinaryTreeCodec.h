//
// Created by Ke Jin on 2/6/18.
//

#ifndef PLAYGROUND_BINARYTREECODEC_H
#define PLAYGROUND_BINARYTREECODEC_H

#include <string>
#include <istream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode{
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int x):val(x){};
};

void helper(TreeNode* node, string& s){
    if(node == nullptr){
        s.push_back('#');
        s.push_back(' ');
        return;
    }
    s.append(to_string(node->val));
    s.push_back(' ');
    helper(node->left, s);
    helper(node->right, s);
}

TreeNode* helper(istringstream& ss){
    string val;
    ss >> val;
    if(val == "#") return nullptr;
    TreeNode* node = new TreeNode(stoi(val));
    node->left = helper(ss);
    node->right = helper(ss);
    return node;
}
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string code;
        helper(root, code);
        code.pop_back();
        return code;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return helper(ss);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
#endif //PLAYGROUND_BINARYTREECODEC_H
