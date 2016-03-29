// Source: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Date: 2016-03-29
// ref: https://github.com/haoel/leetcode/blob/master/algorithms/cpp/binaryTreeInorderTraversal/binaryTreeInorderTraversal.cpp

/********************************************************************************** 
* 
* Given a binary tree, return the inorder traversal of its nodes' values.
* 
* For example:
* Given binary tree {1,#,2,3},
* 
*    1
*     \
*      2
*     /
*    3
* 
* return [1,3,2].
* 
* Note: Recursive solution is trivial, could you do it iteratively?
* 
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
* 
* OJ's Binary Tree Serialization:
* 
* The serialization of a binary tree follows a level order traversal, where '#' signifies 
* a path terminator where no node exists below.
* 
* Here's an example:
* 
*    1
*   / \
*  2   3
*     /
*    4
*     \
*      5
* 
* The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}". 
* 
*               
**********************************************************************************/

class Solution {
    public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<TreeNode*> stack;
        vector<int> res;
        while(stack.size()>0 || root!=NULL){
          if(root!=NULL){            // find the leftest node
             stack.push_back(root);
             root = root->left;
          } else {
              if (stack.size()>0) {       // back track the right tree
               root = stack.back();
               stack.pop_back();
               res.push_back(root->val);
               root = root->right;
              }
          }
        }
        return res;
      }
  };
