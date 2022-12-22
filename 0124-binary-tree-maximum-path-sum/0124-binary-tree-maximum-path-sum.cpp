class Solution {
public:
    int maxi=INT_MIN;
    int sum(TreeNode* curr){
        if(!curr) return 0;
        int lsum=max(0,sum(curr->left));
        int rsum=max(0,sum(curr->right));
        maxi=max(maxi,curr->val+lsum+rsum);
        return curr->val+max(lsum,rsum);
    }
    
    int maxPathSum(TreeNode* root) {
        int pseudo=sum(root);
        return maxi;
    }
};