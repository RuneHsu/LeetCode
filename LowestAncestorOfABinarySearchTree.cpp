// Source: https://leetcode.com/submissions/detail/57609257/
// Date: 2016-03-29
/*****************************************************************************************************
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two 
 * nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to 
 * be a descendant of itself).”
 *
 *        _______6______
 *       /              \
 *   ___2__          ___8__
 *  /      \        /      \
 * 0       _4       7       9
 *        /  \
 *       3   5
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 
 * 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 * Pay attention that if nodes are 0 and 7, 6 is the LCA, cause 2 is not an ancestor of 7.
 * If there is a node X that its val > q and < p, then not matter q and p are which level children, their LCA
 * only can be X, becuase after X, the nodes has been separated.
 ********************************************************************************************************/
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
       while(root){
           if(p->val > root->val && q->val > root->val) {
                root = root->right;
                continue;
           }
           if(p->val < root->val && q->val < root->val) {
               root = root->left;
               continue;
           }
           return root;
       }
           return NULL;
    }
};

/*******************************************************************************/
// ref: https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/lowest-common-ancestor-of-a-binary-search-tree.cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto s = min(p->val, q->val);
        auto b = max(p->val, q->val);

        while (root->val < s || root->val > b) {
            // Keep searching since root is outside of [s, b].
            root = s <= root->val ? root->left : root->right;
        }

        // s <= root->val && root->val <= b.
        return root;   
    }
};
