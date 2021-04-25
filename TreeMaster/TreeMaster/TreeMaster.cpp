#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include "classes/TreeNode.h"


/*
* takes data from a file and addes them to the AVL-Tree
*
* @param filename the name of the file that will be read
* @param root     a pointer to the "root" class, so the values can be added accordingly
*
*/

void loadData(std::string filename, TreeNode* root){


    std::ifstream input(filename);

    std::string data;

    std::string nextLine;
    std::string nextValue;

    while(std::getline(input, data)){
        root->addNode(stoi(data));
    }

}


/*
* takes the input from the user and loads the subtree into a vector that is than returned
*
* @param the name of the file
* @return a vector with all the values
*
*/

std::vector<int> loadSubTree(std::string filename){
    std::vector<int> ret;
    
    std::ifstream input(filename);
    std::string data;

    std::string nextLine;
    std::string nextValue;

    while(std::getline(input, data)){
        ret.push_back(stoi(data));
    }
    return ret;
}


/*
* In the main method the user input is handelt with an infite while-loop that break upon a certain user input (0)
*
*
*/

int main(){
    float sum = 0;
    float n = 0;
    float avg = 0;
    int maxValue = 0;
    int minValue = 0;
    bool avl = true;
    TreeNode* root;
    root = new TreeNode();
    int input = 0;
    std::cout << "Willkommen im TreeMaster, hier koennen Sie Ihre Daten mittels \"Binarytree-Struktur\" speichern und suchen" << std::endl;
    while(1){
        std::cout << "Was wollen Sie machen? (0) Beendet das Program (1) Daten einlesen (2) Daten ausgeben (3) Einzelnen Wert suchen (4) Subtree suchen" << std::endl;
        std::cin >> input;
        if(input == 0){
            break;
        } else if(input == 1){
            std::string filename;
            std::cout << "pls input Filename" << std::endl;
            std::cin >> filename;
            loadData(filename, root);
        }else if(input == 2){
            root->calcBalance(root);
            root->printTree(root, &avl);
            std::string avlTree = avl ? "yes" : "no";
            std::cout<<"AVL: "<<avlTree<<std::endl;
            avg = root->calcAvg(root, &sum, &n);
            maxValue = root->calcMax();
            minValue = root->calcMin();
            std::cout<<"min: "<< minValue <<
            ", max: "<< maxValue <<
            ", avg: "<< avg <<std::endl;
        } else if(input == 3){
            int searchValue = 0;
            std::vector<int> values;
            std::cout << "What number do you want to search?" << std::endl;
            std::cin >> searchValue;
            values = root->searchValue(root, searchValue, values);
            if(values[0] == -1){
                std::cout << searchValue << " not found" << std::endl;
            }else{
                std::cout << searchValue << " found";
                for(int val: values){
                    std::cout << " " << val;
                }
                std::cout << std::endl;
            }
        } else if(input == 4){
            std::string filename;
            std::cout<<"Filename des Subtres eingeben:"<<std::endl;
            std::cin >> filename;
            std::vector<int> subtree = loadSubTree(filename);

            

            TreeNode* subtreeRoot = root->findRoot(root, subtree[0]);
            if(subtree.size() == 1 && subtreeRoot != nullptr){
                std::cout << "Subtree Found" << std::endl;
            }else if(subtreeRoot == nullptr){
                std::cout << "Subtree Not Found" << std::endl;
            } else{
                subtree.erase(subtree.begin());
                int count = subtreeRoot->subtreeSearch(subtreeRoot, subtree, 0);

                if(count == subtree.size()){
                    std::cout << "Subtree Found" << std::endl;
                } else{
                    std::cout << "Subtree Not Found" << std::endl;
                }
            }
            

        } else{
            std::cout<<"ungultige Eingabe"<<std::endl;
        }
    }
    root->deleteTree(root);
    root = nullptr;

}

