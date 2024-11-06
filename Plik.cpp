#include "Plik.h"
#include "BST.h"
#include <iostream>

void Pliki::Pliki_Wczytanie_z_pliku_tekstowego(BST& tree, const std::string& filename, bool clearTree) {
    
    int v;   // <--- Zmienna przechowuje warto�� odczytan� z pliku

    std::ifstream file(filename);   // <--- Otwarcie pliku testkowego do odczytu 

    if (!file) {                                                                         // <--- P�tla sprawdza czy plik zosta� poprawnie otwarty   
        std::cerr << "Nie mozna otworzyc pliku tekstowego: " << filename << std::endl;          
        return;                                                                                 
    }
    while (file >> v) {                     // <--- P�tla while odczytuje kolejne liczby z pliku
        tree.BST_dodanie_elementu(v);       // <--- Ka�da odczytana liczba jest przekazywana doo metody, kt�ra dodaje j� do drzewa BST 
    }
    file.close();   // <--- Po zako�czeniu odczytu plik zostaje zamkni�ty
}


void Pliki::Pliki_Zapisanie_wezla(std::ofstream& file, Node* node) {
    
    if (node == nullptr) {     // <--- Program ko�czy dzia�anie je�li w�ze� jest pusty 
        return; 
    }

    file.write(reinterpret_cast<char*>(&node->data), sizeof(node->data)); // <--- Funkcja write zapisuje warto�� bie��cego w�z�a w formacie binarnym do pliku

    Pliki_Zapisanie_wezla(file, node->left);   // <--- Zapisywanie lewego poddrzewia     // Rekurencja odwiedza wszystkie w�z�y drzewa w kolejno�ci preorder  
    Pliki_Zapisanie_wezla(file, node->right);  // <--- Zapisywanie prawego poddrzewia    
}


void Pliki::Pliki_Zapisywanie_do_pliki_binarnego(BST& tree, const std::string& filename) {
    
    std::ofstream file(filename, std::ios::binary);   // <--- Otwarcie pliku binarnego do zapisu
    
    if (!file) {                                             // <--- P�tla sprawdza czy plik zosta� poprawnie otwarty  
        std::cerr << "Nie mo�na otworzy� pliku do zapisu: " << filename << std::endl;
        return;
    }
    
    Pliki_Zapisanie_wezla(file, tree.root); // Rozpoczyna si� zapis ca�ego drzewa przekazuj�c wska�nik na korze� jako pocz�tkowy w�ze� 
    
    file.close();
}


void Pliki::Pliki_Wczytanie_z_pliku_binarnego(BST& tree, const std::string& filename) {

    std::ifstream file(filename, std::ios::binary);                 // <--- Otwarcie pliku binarnego do odczytu 

    if (!file) {                                        // <--- P�tla sprawdza czy plik zosta� poprawnie otwarty 

        std::cerr << "Nie mo�na otworzy� pliku do wczytania: " << filename << std::endl;  
        return;
    }

    int v;  // <--- Zmienna kt�ra przechowuje odczytan� liczbe z pliku 

    while (file.read(reinterpret_cast<char*>(&v), sizeof(v))) {    // <--- P�tla odczytuje dane z pliku. Funkcja Read() odczytuje dane z pliku w postaci
                                                                   // surowych bajt�w i zapisuje je do zmiennej v. Zmienna v jest typu int, wi�c jej przekazanie
        tree.BST_dodanie_elementu(v);                              // do funkcji read() oczekuje wska�nika do pami�ci w formie char* dlatego jest zastosowane 
                                                                   // reinterpret_cast<char*>(&value) w celu przekonwertowania wska�nika na odpowiedni typ.
    }
    file.close();
}