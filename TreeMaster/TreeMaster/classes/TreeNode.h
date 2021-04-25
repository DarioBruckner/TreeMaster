#ifndef TREENODE_H
#define TREENODE_H
#include<vector>

class TreeNode
{
    public:
        TreeNode() = default;
        ~TreeNode();

        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        int getData();

        void setData(int data);

        void addNode(int inputData);
        void printTree(TreeNode* root, bool* avl);
        float calcAvg(TreeNode* root, float* sum,float* n);
        int calcMax();
        int calcMin();
        void calcBalance(TreeNode* root);
        int getHeight(TreeNode* root);
        std::vector<int> searchValue(TreeNode* root, int searchValue, std::vector<int> values);
        std::vector<int> failedSearch();
        int subtreeSearch(TreeNode* root, std::vector<int> subtree, int counter);
        bool checkIfContains(std::vector<int> subtree, int data);
        TreeNode* findRoot(TreeNode* root, int rootdata);
        void deleteTree(TreeNode* root);
    private:

        int data = -1;
        int balance = 0;




};

#endif // TREENODE_H
