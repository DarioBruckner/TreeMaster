#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include "classes/TreeNode.h"



void loadData(std::string filename, TreeNode* root){


    std::ifstream input(filename);

    std::string data;

    std::string nextLine;
    std::string nextValue;

    while(std::getline(input, data)){
        root->addNode(stoi(data));
    }

}

void printData(){

}



int main(){
    float sum = 0;
    float n = 0;
    float avg = 0;
    int maxValue = 0;
    int minValue = 0;
    TreeNode* root;
    root = new TreeNode();
    int input = 0;
    std::cout << "Willkommen im TreeMaster, hier k�nnen Sie Ihre Daten mittels \"Bin�rytree-Struktur\" speichern und suchen" << std::endl;
    while(1){
        std::cout << "Was wollen Sie machen? (0) Beendet das Program (1) load Data from file (2) Print data (3)Run Tests (4)..." << std::endl;
        std::cin >> input;
        if(input == 0){
            break;
        } else if(input == 1){
            std::string filename;
            std::cout << "pls input Filename" << std::endl;
            std::cin >> filename;
            loadData(filename, root);
        }else if(input == 2){
            root->printTree(root);
        } else if(input == 3){
            root->addNode(5);
            root->addNode(3);
            root->addNode(17);
            root->addNode(9);
            root->addNode(23);
            root->addNode(54);
            root->addNode(11);
            root->addNode(79);
            root->addNode(30);
            root->addNode(12);
            //root->printTree();
            avg = root->calcAvg(root, &sum, &n);
            maxValue = root->calcMax();
            minValue = root->calcMin();
            root->calcBalance(root);
            std::cout << avg << std::endl;
            std::cout << maxValue << std::endl;
            std::cout << minValue << std::endl;
        } else if(input == 4){
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

        } else{
            std::cout << "Noch in Arbeit" << std::endl;
        }
    }
}

