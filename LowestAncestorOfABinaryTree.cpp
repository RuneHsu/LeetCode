// Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Date: 2016-03-29
// ref: https://github.com/haoel/leetcode/blob/master/algorithms/cpp/lowestCommonAncestorOfABinaryTree/LowestCommonAncestorOfABinaryTree.cpp
/********************************************************************************** 
 * 
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the 
 * tree.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is 
 * defined between two nodes v and w as the lowest node in T that has both v and w as 
 * descendants (where we allow a node to be a descendant of itself).”
 * 
 *         _______3______
 *        /              \
 *     ___5__          ___1__
 *    /      \        /      \
 *    6      _2       0       8
 *          /  \
 *          7   4
 * 
 * For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example 
 * is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according 
 * to the LCA definition.
 *               
 *               
 *               
 **********************************************************************************/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //return if found or not found, return NULL if not found
        if(root == NULL || root == q || root == p) return root;
        
       
        // find the LCA in the left tree
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        // find the LCA in the right tree
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        // if the situation on the below is happened, usually means p/q is the child of q/p.
        // because once one of them are found, all its children will be skipped.
        // if left == NULL means both 'p' and 'q' are not found in the left tree
        if(left==NULL) return right;
        // if left == NULL means both 'p' and 'q' are not found in the left tree
        if(right==NULL) return left;
        
        return root;
    }
};

class Solution{
    public: 
    bool findPath(TreeNode* root, TreeNode* p, vector<TreeNode*> &path){
        
          if(root == NULL) return false;
          
          if(root == p){
              path.push_back(p);
              return true;
          }
          
          path.push_back(root);
          
          if(findPath(root->left, p, path))  return true;
          if(findPath(root->right, p, path)) return true;
          
          path.pop_back();
          
          return false;
      }  
      
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        
      vector<TreeNode*> path1, path2;
      
      if (!findPath(root,p,path1)) return NULL;
      if (!findPath(root,q,path2)) return NULL;
      
      int length = path1.size() < path2.size() ? path1.size() : path2.size();
      
      TreeNode* result = root;
      
      for (int i=0; i<length; i++){
          if (path1[i] != path2[i]){
              return result;
          }
                    result = path1[i];
      }
      
      return result;
    }
};
