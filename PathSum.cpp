// Source: https://leetcode.com/problems/path-sum/
// Date: 2016-04-21
/********************************************************************************** 
* 
* Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
* such that adding up all the values along the path equals the given sum.
* 
* For example:
* Given the below binary tree and sum = 22,
* 
*               5
*              / \
*             4   8
*            /   / \
*           11  13  4
*          /  \      \
*         7    2      1
* 
* return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*               
**********************************************************************************/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        
        if (!root->left && !root->right){
            return sum == root->val;
        }
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

/* ref: https://leetcode.com/discuss/8215/accepted-by-using-postorder-traversal
* In the postorder traversal, the node will be removed from the stack only when the 
* right sub-tree has been visited.so the path will be stored in the stack. we can keep 
* check the SUM, the length from root to leaf node. at leaf node, if SUM == sum, OK, 
* return true. After postorder traversal, return false.                             */

class Solution {
    public:
    bool hasPathSum(TreeNode* root, int sum) {
        stack<TreeNode *> s;
        TreeNode *pre = NULL, *cur = root;
        int SUM = 0;
        while (cur || !s.empty()){
            while(cur){                   // from a node to travesal to the most left leaf
                s.push(cur);
                SUM += cur->val;
                cur = cur->left;
            }
            cur = s.top();
            if (cur->left == NULL && cur->right == NULL && SUM == sum){     // found
                return true;
            }
            if (cur->right && pre != cur->right){       // if the node has right subtree
                cur = cur->right;
            } else {                            // if the node doesn't have a right subtree, it moves backward
                pre = cur;
                s.pop();
                SUM -= cur->val;
                cur = NULL;
            }
        }
        return false;
    }
};
