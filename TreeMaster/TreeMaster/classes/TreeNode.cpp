#include "TreeNode.h"
#include <iostream>


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


    //if noValue add as root
    if(data == -1){
        this->setData(inputData);
        std::cout<<"new Node "<<inputData<<std::endl;

     //if input data < root => left
    }else if(inputData < data) {
        std::cout<<inputData<<" < "<<data<<std::endl;
        std::cout<<"go left"<<std::endl;
        if(left == nullptr) {
        std::cout<<"left is empty"<<std::endl;
        std::cout<<"new Node "<<inputData<<std::endl;
        left = new TreeNode();
        left->setData(inputData);
        }else {
            std::cout<<"recursion goes brrrr"<<std::endl;
            left->addNode(inputData);
        }
    //if input data > root => right
    }else if(inputData > data) {
        std::cout<<inputData<<" > "<<data<<std::endl;
        std::cout<<"go right"<<std::endl;
        if(right == nullptr) {
        std::cout<<"right is empty"<<std::endl;
        std::cout<<"new Node "<<inputData<<std::endl;
        right = new TreeNode();
        right->setData(inputData);
        }else {
            std::cout<<"recursion goes brrrr"<<std::endl;
            right->addNode(inputData);
        }
    }else {
        std::cout<<"repetition => do nothing"<<std::endl;
    }

    /*
    //if input data < root => right
    }else if(right == nullptr && inputData > data) {
        root->right = new TreeNode();
        root->right->setData(inputData);
    }else {

    }


    //if input data < root => left
    if (root->left == nullptr && inputData < root->data) {
        root->left = new TreeNode();
        root->left->setData(inputData);



    //if input data > root => right
    */

}
