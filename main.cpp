#include "BST.h"
#include <iostream>

int main()
{
    BST drzewo;
    int v;
    char wybor;
    char opcja;

    do {
        std::cout << "Witaj, wybierz co chcesz zrobic:" << std::endl;
        std::cout << "1. Dodaj nowy element do drzewa BST: " << std::endl;
        std::cout << "2. Wyswietl drzewo metoda preorder: " << std::endl;
        std::cout << "3. Wyswietl drzewo metoda inorder: " << std::endl;
        std::cout << "4. Wyswietl drzewo metoda postorder: " << std::endl;
        std::cout << "5. Jesli chcesz wyjsc z programu" << std::endl;

        std::cin >> opcja;

        switch (opcja) {
        case '1':
            do {
                std::cout << "Podaj wartosc nowego elementu drzewa BST: ";
                std::cin >> v;

                drzewo.BST_dodanie_elementu(v);

                std::cout << "Czy doodac nastepny element ? (t/n): ";
                std::cin >> wybor;
            } while (wybor == 't' || wybor == 'T');
            break;

        case '2':
            drzewo.BST_preorder_wyswietl();
            std::cout << std::endl;
            break;

        case '3':
            drzewo.BST_inorder_wyswietl();
            std::cout << std::endl;
            break;

        case '4':
            drzewo.BST_postorder_wyswietl();
            std::cout << std::endl;
            break;
        }
    }while (opcja != '5');

    return 0;
}

/*
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
*/