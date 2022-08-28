// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

class Solution
{
public:
    // Function to convert binary tree to doubly linked list and return it.

    Node *bToDLL(Node *root)
    {
        // your code here

        if (!root)
            return nullptr;
        Node *left = bToDLL(root->left);
        Node *right = bToDLL(root->right);

        root->right = right;
        if (right)
            right->left = root;

        if (left)
        {
            Node *tmp = left;
            while (tmp->right)
                tmp = tmp->right;
            tmp->right = root;
            root->left = tmp;
            return left;
        }

        return root;
    }
};