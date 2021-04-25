#include "TreeNode.h"
#include <iostream>
#include <algorithm>
#include <vector>


TreeNode::~TreeNode()
{

}


int TreeNode::getData(){
    return data;
}

void TreeNode::setData(int data) {

    this->data = data;

}

/*
* function that adds a new node to a tree and sets its data value
*
* @param input      the integer value that will be stored as data of the new node
*
*/


void TreeNode::addNode(int inputData) {


    //if noValue add as root
    if(data == -1){
        this->setData(inputData);


     //if input data < root => left
    }else if(inputData < data) {
        if(left == nullptr) {
        left = new TreeNode();
        left->setData(inputData);
        }else {
            left->addNode(inputData);
        }
    //if input data > root => right
    }else if(inputData > data) {
        if(right == nullptr) {
        right = new TreeNode();
        right->setData(inputData);
        }else {
            right->addNode(inputData);
        }
    }else {
    }


}

/*
* function traverses through a Tree and prints the data from all Nodes
*
* @param root      pointer to the root TreeNode
* @param avl       bool that will be false if any node has a balance higher then 1 or lower then -1
*
*/

void TreeNode::printTree(TreeNode* root, bool* avl) {

    if(root == nullptr)
        return;

    right->printTree(right, avl);

    left->printTree(left, avl);


    std::cout<<"bal("<<data<<") = "<<balance;

    if(balance < -1 || balance > 1) {
        std::cout<<" (AVL violation!)";
        *avl = false;
    }

    std::cout<<std::endl;

}

/*
* function that calculates the balance factor for each TreeNode
*
* @param root      pointer to the root TreeNode
*
*/


void TreeNode::calcBalance(TreeNode* root) {

    if(root == nullptr)
        return;

    right->calcBalance(right);

    left->calcBalance(left);

    this->balance = getHeight(right) - getHeight(left);


}

/*
* function that calculates height of a given tree
*
* @param root     pointer to the root TreeNode
*
* @return         returns the height as an integer value
*
*/

int TreeNode::getHeight(TreeNode* root)
{
    if (root == NULL)
        return 0;
    else
        return std::max(getHeight(root->left), getHeight(root->right) + 1);
}

/*
* function traverses through a Tree and calculates the average of the data values of all TreeNodes
*
* @param root      pointer to the root TreeNode
* @param sum       pointer to the sum of all Nodes
* @param n         pointer to a counter for the number of Nodes
*
* @return          returns the average of all data Values as a float value
*/

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

/*
* function that calculates maximum data value of a given tree
*
* @param root     pointer to the root TreeNode
*
* @return         returns the maximum data value as an integer
*
*/

int TreeNode::calcMax() {

    if(right == nullptr) {
        return data;
    }

    right->calcMax();

}

/*
* function that calculates minmum data value of a given tree
*
* @param root     pointer to the root TreeNode
*
* @return         returns the minmum data value as an integer
*
*/


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



/*
* Returns a vector with a -1 as its first value
*
* @return failed a int vector with -1 as its first element
*/

std::vector<int> TreeNode::failedSearch(){
    std::vector<int> failed;
    failed.push_back(-1);
    return failed;
}

/*
* Searches the AVL-Tree recursively for a sub tree, returns the amount of elements that have been found
*
* @param root       the pointer to the root of the subtree
* @param subtree    the subtree in form of a int vector
* @param counter    the number of elements that have been found
*
* @return ccounter  the current count of elements found
*/


int TreeNode::subtreeSearch(TreeNode* root, std::vector<int> subtree, int counter){

    int ccounter = counter;
    if(root == nullptr || ccounter == subtree.size()){
        return ccounter;
    }
    if(checkIfContains(subtree, root->getData())){
        ccounter++;
    }


    ccounter = left->subtreeSearch(left, subtree , ccounter);

    ccounter = right->subtreeSearch(right, subtree, ccounter);



    return ccounter;
}


/*
* function that checks if the data is inside of the vector of the subtree
*
* @param subtree    a int vector containing the values
* @param data       the data that that is beeing checked
*
* @return           true/false depending if the elements exists
*/

bool TreeNode::checkIfContains(std::vector<int> subtree, int data){
    if(std::find(subtree.begin(), subtree.end(), data) != subtree.end()){
        return true;
    } else{
        return false;
    }
}

/*
* gets a data value and is supposed to find the Treenode Element that cointains said value
*
*
* @param root       the root of the tree
* @param rootdata   the data that is beeing searched
*
* @return retnode   the pointer to the node that contains the value (nullptr if it doenst exsist)
*/


TreeNode* TreeNode::findRoot(TreeNode* root, int rootdata){
    TreeNode* currentNode = root;
    TreeNode* retNode = nullptr;
    int nodeData = currentNode->getData();

    if(currentNode == nullptr || currentNode->getData() == -1){
        return nullptr;
    }


    if(nodeData == rootdata){
        return currentNode;
    } else if(nodeData > rootdata){
        if(currentNode->left == nullptr){
            return nullptr;
        } else{
            currentNode = currentNode->left;
            retNode = findRoot(currentNode, rootdata);
        }
    } else if(nodeData < rootdata){
        if(currentNode->right == nullptr){
            return nullptr;
        } else{
            currentNode = currentNode->right;
            retNode = findRoot(currentNode, rootdata);
        }
    }

    return retNode;
}

/*
* function traverses through a Tree and deletes all Nodes
*
* @param root      pointer to the root TreeNode
*
*/

void TreeNode::deleteTree(TreeNode* root) {

    if(root == nullptr)
        return;

    right->deleteTree(right);
    left->deleteTree(left);

    delete root;

}



