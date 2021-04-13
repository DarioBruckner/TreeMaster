#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>


std::vector<int> arr;


void loadData(std::string filename){
  

    std::ifstream input(filename);
    
    std::string data;

    std::string nextLine;
    std::string nextValue;

    while(std::getline(input, data)){
        arr.push_back(stoi(data));
    }

}

void printData(){
    for(int value : arr){
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main(){
    int input = 0; 
    std::cout << "Willkommen im TreeMaster, hier können Sie Ihre Daten mittels \"Binärytree-Struktur\" speichern und suchen" << std::endl;
    while(1){
        std::cout << "Was wollen Sie machen? (0) Beendet das Program (1) load Data from file (2) Print data (3)..." << std::endl;
        std::cin >> input;
        if(input == 0){
            break;
        } else if(input == 1){
            std::string filename;
            std::cout << "pls input Filename" << std::endl;
            std::cin >> filename;
            loadData(filename);
        }else if(input == 2){
            printData();
        } else{
            std::cout << "Noch in Arbeit" << std::endl;
        }
    }
}

