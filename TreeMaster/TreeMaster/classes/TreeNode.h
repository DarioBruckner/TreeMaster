#ifndef TREENODE_H
#define TREENODE_H


class TreeNode
{
    public:
        TreeNode() = default;
        ~TreeNode();
        void addNode(TreeNode* root, int inputData);
        void setData(int data);

    protected:

    private:
        int data;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;


};

#endif // TREENODE_H
