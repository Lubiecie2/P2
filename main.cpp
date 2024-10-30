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
        std::cout << "2. Usun element drzewa BST: " << std::endl;
        std::cout << "3. Wyswietl drzewo metoda preorder: " << std::endl;
        std::cout << "4. Wyswietl drzewo metoda inorder: " << std::endl;
        std::cout << "5. Wyswietl drzewo metoda postorder: " << std::endl;
        std::cout << "6. Szukaj drogi do wybranego elementu: " << std::endl;
        std::cout << "7. Usun cale drzewo: " << std::endl;
        std::cout << "8. Jesli chcesz wyjsc z programu" << std::endl;

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
            do {
                std::cout << "Podaj wartosc elementu drzewa BST, ktora chcesz usunac: ";
                std::cin >> v;

                drzewo.BST_usuwanie_elementu(v);

                std::cout << "Czy usunac nastepny element ? (t/n): ";
                std::cin >> wybor;
            } while (wybor == 't' || wybor == 'T');
            break;
        case '3':
            drzewo.BST_preorder_wyswietl();
            std::cout << std::endl;
            break;

        case '4':
            drzewo.BST_inorder_wyswietl();
            std::cout << std::endl;
            break;

        case '5':
            drzewo.BST_postorder_wyswietl();
            std::cout << std::endl;
            break;
        case '6':
            do {
                std::cout << "Podaj wartosc elementu drzewa BST, ktora chcesz znalezc: ";
                std::cin >> v;

                drzewo.BST_szukaj(v);

                std::cout << "Czy chcesz znalezc inny element ? (t/n): ";
                std::cin >> wybor;
            } while (wybor == 't' || wybor == 'T');
            break;
        case '7':
            drzewo.BST_usun_cale_drzewo_wyswietl();
            std::cout << "cale drzewo zostalo usuniete" << std::endl;
            break;
        }
    }while (opcja != '8');

    return 0;
}

