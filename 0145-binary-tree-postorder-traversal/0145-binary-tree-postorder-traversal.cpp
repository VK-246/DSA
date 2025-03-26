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
void PostOrder(TreeNode* root, vector<int> &post){
    if( root == nullptr ){return;}
    PostOrder(root->left,post);
    PostOrder(root->right,post);
    post.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        PostOrder(root,post);
        return post;
    }
};