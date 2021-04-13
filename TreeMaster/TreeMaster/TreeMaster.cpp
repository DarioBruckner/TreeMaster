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
    TreeNode* root;
    root = new TreeNode();
    int input = 0;
    std::cout << "Willkommen im TreeMaster, hier k�nnen Sie Ihre Daten mittels \"Bin�rytree-Struktur\" speichern und suchen" << std::endl;
    while(1){
        std::cout << "Was wollen Sie machen? (0) Beendet das Program (1) load Data from file (2) Print data (3)..." << std::endl;
        std::cin >> input;
        if(input == 0){
            break;
        } else if(input == 1){
            std::string filename;
            std::cout << "pls input Filename" << std::endl;
            std::cin >> filename;
            loadData(filename, root);
        }else if(input == 2){
            printData();
        } else{
            std::cout << "Noch in Arbeit" << std::endl;
        }
    }
}

