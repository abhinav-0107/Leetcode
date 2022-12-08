class Solution {
public:
	void dfs(TreeNode* curr,vector<int>&v){
		if(!curr) return;
		if(!curr->left && !curr->right){
			v.push_back(curr->val);
			return;
		} 
		dfs(curr->left,v);
		dfs(curr->right,v);
	}

	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int>v1,v2;
		dfs(root1,v1);
		dfs(root2,v2);
		return v1==v2;
	}
};