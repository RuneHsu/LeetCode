// Source: https://leetcode.com/submissions/detail/58772425/
// Date: 2016-04-11
/********************************************************************************** 
* 
* Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
* (ie, from left to right, level by level from leaf to root).
* 
* For example:
* Given binary tree {3,9,20,#,#,15,7},
* 
*     3
*    / \
*   9  20
*     /  \
*    15   7
* 
* return its bottom-up level order traversal as:
* 
* [
*   [15,7],
*   [9,20],
*   [3]
* ]
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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        vector<vector<int> > ret;
		ret.clear();
		if(root == NULL)
			return ret;
		queue<TreeNode*> S;
		S.push(root);
		S.push(NULL);
		vector<int> tmp;
		while(!S.empty()){
			//travesal current level
			TreeNode* p = S.front();
			S.pop();
			if(p!=NULL)
			{
				tmp.push_back(p->val);
				if(p->left) 
					S.push(p->left);
				if(p->right)
					S.push(p->right);
			}else{
				if(!tmp.empty())
				{	
					S.push(NULL);
					ret.push_back(tmp);
					tmp.clear();
				}
			}
		}
		reverse(ret.begin(),ret.end());
        return ret;
    }
};
