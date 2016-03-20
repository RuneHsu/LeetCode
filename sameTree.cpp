// Source: https://leetcode.com/problems/same-tree/
// Date: 2016-03-20
/**************************************************************************
*Given two binary trees, write a function to check if they are equal or not.
*
*Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
**************************************************************************/

class solution{
public:
  bool isSameTree(TreeNode* p, TreeNode* q){
  if (p == q) return true;
  
  if (p == NULL || q == NULL) return false;
  
  return ((p->val == q->val) && (isSameTree(p->left,q->left) && (isSameTree(p->right,q->right)));
  }
}
