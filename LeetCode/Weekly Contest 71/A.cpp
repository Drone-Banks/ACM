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
private:
	vector<int> ans;
public:
	void solve(TreeNode* root)
	{
		if(root==NULL) return;
		solve(root->left);
		ans.push_back(root->val);
		solve(root->right);
	}
    int minDiffInBST(TreeNode* root) {
        solve(root);
		int dis = INT_MAX;
		for(int i=1;i<ans.size();i++)
		{
			dis = min(dis, ans[i]-ans[i-1]);
		}
		return dis;
    }
};