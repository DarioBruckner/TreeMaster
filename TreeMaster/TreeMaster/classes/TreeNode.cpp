#include "TreeNode.h"
#include <iostream>
#include <algorithm>
#include <vector>


TreeNode::~TreeNode()
{
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}


int TreeNode::getData(){
    return data;
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


}

void TreeNode::printTree(TreeNode* root) {

    if(root == nullptr)
        return;

    right->printTree(right);

    left->printTree(left);

    std::cout<<"bal("<<data<<") = "<<balance<<std::endl;

}

void TreeNode::calcBalance(TreeNode* root) {

    if(root == nullptr)
        return;

    right->calcBalance(right);

    left->calcBalance(left);

    this->balance = getHeight(right) - getHeight(left);


}

int TreeNode::getHeight(TreeNode* root)
{
    if (root == NULL)
        return 0;
    else
        return std::max(getHeight(root->left), getHeight(root->right) + 1);
}

float TreeNode::calcAvg(TreeNode* root, float* sum,float* n) {


    if(root == nullptr) {
        return 0;
    }



    right->calcAvg(right, sum , n);

    left->calcAvg(left, sum, n);

    *sum += data;
    *n += 1;

    float avg  = *sum / *n;

    return avg;

}

int TreeNode::calcMax() {

    if(right == nullptr) {
        return data;
    }

    right->calcMax();

}

int TreeNode::calcMin() {

    if(left == nullptr) {
        return data;
    }

    left->calcMin();
}


std::vector<int> TreeNode::searchValue(TreeNode* root, int searchValue, std::vector<int> values){
    TreeNode* currentNode = root;
    int nodeData = currentNode->getData();
    if(nodeData == -1){
        return failedSearch();
    }
    
    if(nodeData == searchValue){
        values.push_back(nodeData);
        return values;
    } else if(nodeData > searchValue){
        if(currentNode->left == nullptr){
            return failedSearch();
        } else{
            currentNode = currentNode->left;
            values.push_back(nodeData);
            values = currentNode->searchValue(currentNode, searchValue, values);
        }
        
    } else if(nodeData < searchValue){
        if(currentNode->right == nullptr){
            return failedSearch();
        } else{
            currentNode = currentNode->right;
            values.push_back(nodeData);
            values = currentNode->searchValue(currentNode, searchValue, values);
        }
    }
    return values;
    
}


std::vector<int> TreeNode::failedSearch(){
    std::vector<int> failed;
    failed.push_back(-1);
    return failed;
}






