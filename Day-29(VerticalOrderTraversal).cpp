/*
Time complexity : O(N*log N)
Space complexity : O(N) ,storing all the nodes along with their x,y  co-ordinates.
My approach : Store the node->val according to their x,y values , for this use a map<int,vector<pair<int,int>>> mp , and sort the vector using a custom comparator.
*/

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
class Solution {
public:
    void helper(TreeNode* root, map<int,vector<pair<int,int>>>& mp ,int x , int y )
    {
        if(root == NULL) return ;
        mp[x].push_back({y,root->val});
        helper(root->left,mp,x-1,y+1);
        helper(root->right,mp,x+1,y+1);
    }
    
    static bool cmp(pair<int,int>&a ,pair<int,int>&b)
    {
        if(a.first < b.first) return true;
        else if( a.first > b.first) return false;
        return ( a.second < b.second );
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        vector<vector<int>> res;
        if(root == NULL) return res;
        map<int,vector<pair<int,int>>> mp;
        int x =0,y=0;
        helper(root,mp,x,y); 
        for(auto it : mp)
        {   
            sort(it.second.begin(),it.second.end(),cmp);
            vector<int> temp;
            for(auto it1 = it.second.begin();it1 != it.second.end();it1++)
            {
                temp.push_back(it1->second);
                
            }
            res.push_back(temp);
           
        }
        
        
        return res;
    }
};
