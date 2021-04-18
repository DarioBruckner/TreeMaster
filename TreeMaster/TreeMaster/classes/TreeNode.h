#ifndef TREENODE_H
#define TREENODE_H


class TreeNode
{
    public:
        TreeNode() = default;
        ~TreeNode();

        void setData(int data);

        void addNode(int inputData);
        void printTree();
        float calcAvg(float* sum, float* n);
        int calcMax();
        int calcMin();
        void calcBalance();



    protected:

    private:
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        int data = -1;
        int balance = 0;




};

#endif // TREENODE_H
