//Time Complexity O(n)
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
    
    TreeNode* createTree(int &level,int min_val,int max_val,vector<int>&preorder){
        if(level>=preorder.size()) return NULL;
        if(preorder[level]>min_val && preorder[level]<max_val){
           TreeNode *temp=(TreeNode *)malloc(sizeof(TreeNode));
            temp->val=preorder[level];
            //cout<<temp->val<<endl;
            level++;
            temp->left=createTree(level,min_val,temp->val,preorder);
            temp->right=createTree(level,temp->val,max_val,preorder);
            
            return temp;
        }
        else {
           
            return NULL;
        }
        
        
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    
        int level=0;
        TreeNode *root=createTree(level,INT_MIN,INT_MAX,preorder);
        return root;
        
    }
};