#include "BST.h"
#include <iostream>

int main()
{
    BST drzewo;
    int v;
    char wybor;


    do {
        std::cout << "Podaj wartosc nowego elementu drzewa BST: ";
        std::cin >> v;

        drzewo.BST_dodanie_elementu(v);
        
        std::cout << "Czy doodac nastepny element ? (t/n): ";
        std::cin >> wybor;
    } while (wybor == 't' || wybor == 'T');

    drzewo.BST_preorder_wyswietl();
    
    drzewo.BST_inorder_wyswietl();

    drzewo.BST_postorder_wyswietl();
}
