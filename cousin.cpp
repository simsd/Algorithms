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

/*
    Problem: find if two nodes are cousins through checking if they have the 
    same depth and different parents (not siblings)

    Algorithm:
    
    Use dfs to find the depth of x and y ==> save these values
    Use dfs to find the parent of x and y ==> save these values
    
    Make sure that the parent's do not match for both
*/

class Solution {
public:
    
    int depth(TreeNode* root, int target, int level){
        if(root == nullptr)
            return 0;
        else{
            if(root->val == target)
                return level;
            
            int found = depth(root->left, target, level +1);
            if(found != 0)
                return found;
            
            return depth(root->right, target, level + 1);
            
        }
    }
    
    void parent_finder(TreeNode* root, TreeNode*& parent,  int target){
        if(root == nullptr)
            return;
        else{
            parent_finder(root->left, parent, target);
            if((root->left != nullptr && root->left->val == target) || (root->right != nullptr && root->right->val == target)){
                parent = root;
                return;
            }
            parent_finder(root->right, parent,  target); 
        }
    }
    
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(x == y)
            return false;
        
        int x_depth = depth(root, x, 1);
        int y_depth = depth(root, y, 1);
        cout << x_depth << endl;
        TreeNode* x_parent = nullptr, *y_parent = nullptr;
        parent_finder(root, x_parent, x);
        parent_finder(root, y_parent, y);
        if(x_depth != y_depth || x_parent == y_parent)
            return false;
        
        
        return true;
        
    }
};
