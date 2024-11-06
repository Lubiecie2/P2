#include "Plik.h"
#include "BST.h"
#include <iostream>

void Pliki::Pliki_Wczytanie_z_pliku_tekstowego(BST& tree, const std::string& filename, bool clearTree) {
    
    int v;   // <--- Zmienna przechowuje wartoúÊ odczytanπ z pliku

    std::ifstream file(filename);   // <--- Otwarcie pliku testkowego do odczytu 

    if (!file) {                                                                         // <--- PÍtla sprawdza czy plik zosta≥ poprawnie otwarty   
        std::cerr << "Nie mozna otworzyc pliku tekstowego: " << filename << std::endl;          
        return;                                                                                 
    }
    while (file >> v) {                     // <--- PÍtla while odczytuje kolejne liczby z pliku
        tree.BST_dodanie_elementu(v);       // <--- Kaøda odczytana liczba jest przekazywana doo metody, ktÛra dodaje jπ do drzewa BST 
    }
    file.close();   // <--- Po zakoÒczeniu odczytu plik zostaje zamkniÍty
}


void Pliki::Pliki_Zapisanie_wezla(std::ofstream& file, Node* node) {
    
    if (node == nullptr) {     // <--- Program koÒczy dzia≥anie jeúli wÍze≥ jest pusty 
        return; 
    }

    file.write(reinterpret_cast<char*>(&node->data), sizeof(node->data)); // <--- Funkcja write zapisuje wartoúÊ bieøπcego wÍz≥a w formacie binarnym do pliku

    Pliki_Zapisanie_wezla(file, node->left);   // <--- Zapisywanie lewego poddrzewia     // Rekurencja odwiedza wszystkie wÍz≥y drzewa w kolejnoúci preorder  
    Pliki_Zapisanie_wezla(file, node->right);  // <--- Zapisywanie prawego poddrzewia    
}


void Pliki::Pliki_Zapisywanie_do_pliki_binarnego(BST& tree, const std::string& filename) {
    
    std::ofstream file(filename, std::ios::binary);   // <--- Otwarcie pliku binarnego do zapisu
    
    if (!file) {                                             // <--- PÍtla sprawdza czy plik zosta≥ poprawnie otwarty  
        std::cerr << "Nie moøna otworzyÊ pliku do zapisu: " << filename << std::endl;
        return;
    }
    
    Pliki_Zapisanie_wezla(file, tree.root); // Rozpoczyna siÍ zapis ca≥ego drzewa przekazujπc wskaünik na korzeÒ jako poczπtkowy wÍze≥ 
    
    file.close();
}


void Pliki::Pliki_Wczytanie_z_pliku_binarnego(BST& tree, const std::string& filename) {

    std::ifstream file(filename, std::ios::binary);                 // <--- Otwarcie pliku binarnego do odczytu 

    if (!file) {                                        // <--- PÍtla sprawdza czy plik zosta≥ poprawnie otwarty 

        std::cerr << "Nie moøna otworzyÊ pliku do wczytania: " << filename << std::endl;  
        return;
    }

    int v;  // <--- Zmienna ktÛra przechowuje odczytanπ liczbe z pliku 

    while (file.read(reinterpret_cast<char*>(&v), sizeof(v))) {    // <--- PÍtla odczytuje dane z pliku. Funkcja Read() odczytuje dane z pliku w postaci
                                                                   // surowych bajtÛw i zapisuje je do zmiennej v. Zmienna v jest typu int, wiÍc jej przekazanie
        tree.BST_dodanie_elementu(v);                              // do funkcji read() oczekuje wskaünika do pamiÍci w formie char* dlatego jest zastosowane 
                                                                   // reinterpret_cast<char*>(&value) w celu przekonwertowania wskaünika na odpowiedni typ.
    }
    file.close();
}