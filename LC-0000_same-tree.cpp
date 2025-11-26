/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right
(right) {}
 * };
 */
class Solution {
public:
bool bfs(TreeNode* p, TreeNode* q){
    if(p==NULL && q==NULL)return true;
    if(p!=NULL && q==NULL)return false;
    if(p==NULL && q!=NULL)return false;
    if(q->val==p->val){
    return bfs(p->left ,q->left)&& bfs(p->right,q->right);
