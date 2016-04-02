// Source: https://leetcode.com/problems/balanced-binary-tree/
// Date: 2016-04-02
/********************************************************************************** 
* 
* Given a binary tree, determine if it is height-balanced.
* 
* For this problem, a height-balanced binary tree is defined as a binary tree in which 
* the depth of the two subtrees of every node never differ by more than 1.
* 
*               
**********************************************************************************/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height;
        return BalancedCnt(root, height);
    }
    bool BalancedCnt(TreeNode* root, int& height){
          if(!root){
              height = 0;
              return true;
          } 
          int left=0, right=0;
          bool isleft = BalancedCnt(root->left, left);
          bool isright = BalancedCnt(root->right, right);
          height = (left>right ? left:right) + 1;
          return abs(left-right) <= 1 && isleft && isright;
    }
};


class Solution {
public:
    int depth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    }

    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        return depth(root) != -1;
    }
};
