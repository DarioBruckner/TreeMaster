#include "TreeNode.h"


TreeNode::~TreeNode()
{
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}

void TreeNode::setData(int data) {

    this->data = data;

}

void TreeNode::addNode(int inputData) {

    /*
    //if noValue add as root
    if(left == nullptr && right == nullptr)
        this->setData(intData);
    else()


    //if input data < root => left
    if (root->left == nullptr && inputData < root->data) {
        root->left = new TreeNode();
        root->left->setData(inputData);
    }else if(root->right == nullptr && inputData > root->data) {
        root->right = new TreeNode();
        root->right->setData(inputData);
    }


    //if input data > root => right
    */

}
