// 606. Construct String from Binary Tree
// https://leetcode.com/problems/construct-string-from-binary-tree/

/*
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example, 
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode* t) {
	if (t) {
		gc(t->left);
		gc(t->right);
		delete t;
	}
}

class Solution {
public:
	string tree2str(TreeNode* t) {
		if (!t) {
			return "";
		}
		if (!t->left and !t->right) {
			return to_string(t->val);
		}
		if (t->left and !t->right) {
			return to_string(t->val) + "(" + tree2str(t->left) + ")";
		}
		return to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
	}
};

int main(void) {
	Solution solution;
	TreeNode *t;
	string answer, result;

	t = new TreeNode(1);
	t->left = new TreeNode(2);
	t->right = new TreeNode(3);
	t->left->left = new TreeNode(4);
	answer = "1(2(4))(3)";
	result = solution.tree2str(t);
	gc(t);
	assert(answer == result);

	t = new TreeNode(1);
	t->left = new TreeNode(2);
	t->right = new TreeNode(3);
	t->left->right = new TreeNode(4);
	answer = "1(2()(4))(3)";
	result = solution.tree2str(t);
	gc(t);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}