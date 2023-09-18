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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
    
private:
    bool isValidBST(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (!node) return true;
        
        // Verifica se o valor do nó está dentro dos limites permitidos
        if ((minNode && node->val <= minNode->val) || (maxNode && node->val >= maxNode->val))
            return false;
        
        // Verifica a subárvore esquerda com limites atualizados
        // A subárvore esquerda deve ter um valor máximo igual ao valor do nó atual
        // A subárvore direita deve ter um valor mínimo igual ao valor do nó atual
        return isValidBST(node->left, minNode, node) && isValidBST(node->right, node, maxNode);
    }
};