// Source: https://leetcode.com/problems/binary-tree-paths/
// Date: 2016-05-02
/**************************************************
* Given a binary tree, return all root-to-leaf paths.
*
* For example, given the following binary tree:
*
*   1
* /   \
* 2     3
* \
*  5
* All root-to-leaf paths are:
*
* ["1->2->5", "1->3"]
*****************************************************/

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
    void binaryTreePaths(vector<string>& r, TreeNode* root, string t){
        if (!root->left && !root->right){
            r.push_back(t);
            return;
        }
        if (root->left) binaryTreePaths(r, root->left, t + "->" + to_string(root->left->val));
        if(root->right) binaryTreePaths(r, root->right, t + "->" + to_string(root->right->val));
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> r;
        if (!root) return r;
        binaryTreePaths(r,root,to_string(root->val));
        return r;
    }
};
