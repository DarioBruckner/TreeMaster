#include <iostream>
#include <stdio.h>

int main()
{
    int input = 0; 
    std::cout << "Willkommen im TreeMaster, hier k�nnen Sie Ihre Daten mittels \"Bin�rytree-Struktur\" speichern und suchen" << std::endl;
    while(1){
        std::cout << "Was wollen Sie machen? (0) Beendet das Program (1)..." << std::endl;
        std::cin >> input;
        if(input == 0){
            break;
        } else{
            std::cout << "Noch in Arbeit" << std::endl;
        }
    }
}

