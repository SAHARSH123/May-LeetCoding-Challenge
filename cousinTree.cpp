/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    void preorderTraverse(TreeNode *root,int par,int depth,unordered_map<int,pair<int,int>>&m1){
        if(root==NULL) return;
        m1[root->val]={depth,par};
        preorderTraverse(root->left,root->val,depth+1,m1);
        preorderTraverse(root->right,root->val,depth+1,m1);
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,pair<int,int>>m1;
        preorderTraverse(root,-1,0,m1);
        if(m1[x].first==m1[y].first && m1[x].second!=m1[y].second) return true;
        return false;
    }
};