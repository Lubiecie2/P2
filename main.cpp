#include "BST.h"
#include <iostream>
#include "Plik.h"
#include <string>

int main()
{
    BST drzewo;
    int v;
    char wybor = 'n'; 
    int opcja; 

    Pliki pliki;

    do {
        std::cout << "Wybierz co chcesz zrobic:" << std::endl;
        std::cout << "1. Dodaj nowy element do drzewa BST: " << std::endl;
        std::cout << "2. Usun element drzewa BST: " << std::endl;
        std::cout << "3. Wyswietl drzewo metoda preorder: " << std::endl;
        std::cout << "4. Wyswietl drzewo metoda inorder: " << std::endl;
        std::cout << "5. Wyswietl drzewo metoda postorder: " << std::endl;
        std::cout << "6. Szukaj drogi do wybranego elementu: " << std::endl;
        std::cout << "7. Usun cale drzewo: " << std::endl;
        std::cout << "8. Zapisz do pliku: " << std::endl;
        std::cout << "9. Jesli chcesz wczytac wartosci do drzewa z pliku tekstowego" << std::endl;
        std::cout << "10. Jesli chcesz zapisac zawartosc drzewa do pliku binarnego" << std::endl;
        std::cout << "11. Jesli chcesz wczytac zawartosc pliku binarnego do drzewa" << std::endl;
        std::cout << "12. Jesli chcesz wyjsc z programu" << std::endl;


        std::cin >> opcja;

        switch (opcja) {
        case 1:
            do {
                std::cout << "Podaj wartosc nowego elementu drzewa BST: ";
                std::cin >> v;

                drzewo.BST_dodanie_elementu(v);

                std::cout << "Czy dodac nastepny element ? (t/n): ";
                std::cin >> wybor;

            } while (wybor == 't' || wybor == 'T');
            break;
        case 2:
            do {
                std::cout << "Podaj wartosc elementu drzewa BST, ktora chcesz usunac: ";
                std::cin >> v;

                drzewo.BST_usuwanie_elementu(v);

                std::cout << "Czy usunac nastepny element ? (t/n): ";
                std::cin >> wybor;

            } while (wybor == 't' || wybor == 'T');
            break;
        case 3:
            drzewo.BST_preorder_wyswietl();
            std::cout << std::endl;
            break;

        case 4:
            drzewo.BST_inorder_wyswietl();
            std::cout << std::endl;
            break;

        case 5:
            drzewo.BST_postorder_wyswietl();
            std::cout << std::endl;
            break;
        case 6:
            do {
                std::cout << "Podaj wartosc elementu drzewa BST, ktora chcesz znalezc: ";
                std::cin >> v;

                drzewo.BST_szukaj(v);

                std::cout << "Czy chcesz znalezc inny element ? (t/n): ";
                std::cin >> wybor;

            } while (wybor == 't' || wybor == 'T');
            break;
        case 7:
            drzewo.BST_usun_cale_drzewo_wyswietl();
            std::cout << "Cale drzewo zostalo usuniete" << std::endl;
            break;

        case 8:
            drzewo.BST_zapisz_do_pliku("plik.txt");
            std::cout << "Drzewo zapisano do pliku." << std::endl;
            break;
        }

        case 9:
        {
            std::string filename = "Pliki_Wczytanie_z_pliku_tekstowego.txt";
            pliki.Pliki_Wczytanie_z_pliku_tekstowego(drzewo, filename, true);
        }
        break;


        case 10:
        {
            std::string binFilename = "drzewo.bin";
            pliki.Pliki_Zapisywanie_do_pliki_binarnego(drzewo, binFilename);
            std::cout << "Konczenie programu..." << std::endl;
        }
        break;

        case 11: 
        {
            std::string binFilename = "drzewo.bin"; 
            pliki.Pliki_Wczytanie_z_pliku_binarnego(drzewo, binFilename); 
            std::cout << "Wczytano drzewo z pliku binarnego: " << binFilename << std::endl;
        }
        break;

        }

    } while (opcja != 12); 

    return 0;
}