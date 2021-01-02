/*
Time complexity : O(h) , where h is the height of the tree
Space complexity : O(h) 
My approach : simultaneouly traverse in both original and cloned , when target is found in original then return reference of cloned tree's node. 
*/


class Solution {
public:
    void PreorderHelper(TreeNode* original, TreeNode* cloned , TreeNode* target,TreeNode* &res)
    {
        if(original == NULL or cloned == NULL ) return;
        if(original == target ) res = cloned;
        PreorderHelper(original->left,cloned->left,target,res);
        PreorderHelper(original->right,cloned->right,target,res);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        
         if(cloned == NULL or original == NULL ) return NULL;
         TreeNode* res ;
         PreorderHelper(original,cloned,target,res);
        
        return res;
        
    }
};
