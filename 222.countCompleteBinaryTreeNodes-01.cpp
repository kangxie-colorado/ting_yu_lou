class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
    
        int nodes {0};
        queue<TreeNode*> q;

        q.push(root);
        nodes++;
    
        while (q.empty() == false) {
            TreeNode* node = q.front();            
            q.pop();
    
            if (node->left != nullptr) {
                q.push(node->left);
                nodes++;
            } 
            else {
                break;
            }        
    
            if (node->right != nullptr) {
                q.push(node->right);
                nodes++;
            }
            else {
                break;
            }

        }
        return nodes;
        
    }
};
