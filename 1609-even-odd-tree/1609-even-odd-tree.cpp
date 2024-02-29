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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool even=true;
        while(!q.empty()){
            int size=q.size();
            int tvar=even?INT_MIN:INT_MAX;
            while(size--){
                TreeNode* temp=q.front();
                q.pop();
                if(even){
                    if((temp->val%2!=0) && tvar<temp->val)tvar=temp->val;
                    else return false;
                }
                else{
                    if((temp->val%2==0)&&tvar>temp->val)tvar=temp->val;
                    else return false;
                }
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            even=!even;
        }
        return true;
    }
};