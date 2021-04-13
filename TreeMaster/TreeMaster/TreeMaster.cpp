#include <iostream>
#include <stdio.h>
#include "classes/TreeNode.h"

int main()
{
    TreeNode* root;
    root = new TreeNode();
    int input = 0;
    std::cout << "Willkommen im TreeMaster, hier können Sie Ihre Daten mittels \"Binärytree-Struktur\" speichern und suchen" << std::endl;
    while(1){
        std::cout << "Was wollen Sie machen? (0) Beendet das Program (1)..." << std::endl;
        std::cin >> input;
        if(input == 0){
            break;
        } else{
            //test addNode function:
            root->addNode(5);
            root->addNode(3);
            root->addNode(7);
            root->addNode(8);
            root->addNode(17);
            root->addNode(5);
            std::cout << "Noch in Arbeit" << std::endl;
        }
    }
}

