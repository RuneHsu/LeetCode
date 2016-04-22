// Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Date: 2016-04-22
/********************************************************************************** 
* 
* Given a binary tree, find its minimum depth.
* 
* The minimum depth is the number of nodes along the shortest path from the root node 
* down to the nearest leaf node.
*               
**********************************************************************************/

//travel all nodes for twice and if the tree is largely unbalance, it is very time consuming
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

//Itarator way
class Solution {
    public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int i = 0;
        while(!q.empty()){
            i++;
            int k = q.size();
            for (int j=0; j<k; j++) {                       // visit all the node in this level
                TreeNode* cur = q.front();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                q.pop();
                if (cur->left==NULL && cur->right==NULL) return i;
            }
        }
    }
};
