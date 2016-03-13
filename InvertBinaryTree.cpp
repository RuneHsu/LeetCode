// Source: https://leetcode.com/problems/invert-binary-tree/
// Date: 2016-03-13

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*********************************
 * Invert a binary tree.
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 * 
 * to
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 * *******************************************/
class Solution {
public:

    TreeNode* invertTree_recursive(TreeNode* root){
        if (root = NULL) return root;
        TreeNode* node = invertTree_recursive(root->left);
        root->left = invertTree_recursive(root->right);
        root->right = node;
        return root;
    }
    
    TreeNode* invertTree_no_recursive(TreeNode* root) {
        if (root = NULL) return root;
        vector<TreeNode*> stack;
    
        stack.push_back(root);
    
        while(!stack.empty()){
            TreeNode* node = stack.back();
            stack.pop_back();
            swap(node->left, node->right);
            if (node->left) stack.push_back(node->left);
            if (node->right) stack.push_back(node->right);
        
        }
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root){
        if(rand()%2 == 0){
            return invertTree_recursive(root);
        }
        return invertTree_no_recursive(root);
    }
};


// Another version of invert binary tree
// Source: https://www.quora.com/What-is-the-algorithmic-approach-to-invert-a-given-binary-tree
/*******************************************
 * For example
 * Given:   1
 *         / \ 
 *        2   3 
 *             \
 *              4 
 * output:   4 
 *           /
 *          2   3
 *           \ /
 *            1
 *
 *All that is required is to convert the children as parents and parents as children in the binary tree.
 * ***********************************************/
 
 class Solution{
     public:
     TreeNode* invertTree(root){
         if (root = NULL) return NULL;
         TreeNode* leftChild, rightChild;
         if (root->left){
             leftChild = invertTree(root->left);
             leftChild->right = root;
         }
         if (root->right){
             rightChild = invertTree(root->right);
             rightChild->left = root;
         }
         root->left = NULL;
         root->right = NULL;
         
         return root;
     }
 }
 
 /***************** Another solution ****************/
 struct node {
    int Value;
    struct node* left, *right;
};
 
void Invert( node* current, node* parent){
    if( current== NULL) return;
    if( current->left != NULL){
        Invert(current->left, current);
        current->left=NULL;
    }
    if( current->right != NULL){
        Invert(current->right, current);
        current->right=NULL;
    }
    current->left = parent;
    return;
}
 
int main(){
    Invert(root,NULL);/*Call the Invert function with current node as root and its parent as NULL*/
    return 0;
}
 
