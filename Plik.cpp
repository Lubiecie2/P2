#include "Plik.h"
#include "BST.h"
#include <iostream>

void Pliki::Pliki_Wczytanie_z_pliku_tekstowego(BST& tree, const std::string& filename, bool clearTree) {
    
    int v;

    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Nie mozna otworzyc pliku tekstowego: " << filename << std::endl;
        return;
    }
    while (file >> v) {
        tree.BST_dodanie_elementu(v);
    }
    file.close();
}
void Pliki::Pliki_Zapisanie_wezla(std::ofstream& file, Node* node) {
    
    if (node == nullptr) {     // <--- Program koñczy dzia³anie jeœli wêze³ jest pusty 
        return; 
    }

    file.write(reinterpret_cast<char*>(&node->data), sizeof(node->data));

    Pliki_Zapisanie_wezla(file, node->left);   // <--- Zapisywanie lewego poddrzewia 
    Pliki_Zapisanie_wezla(file, node->right);  // <--- Zapisywanie prawego poddrzewia 
}

void Pliki::Pliki_Zapisywanie_do_pliki_binarnego(BST& tree, const std::string& filename) {
    
    std::ofstream file(filename, std::ios::binary);
    
    if (!file) {
        std::cerr << "Nie mo¿na otworzyæ pliku do zapisu: " << filename << std::endl;
        return;
    }
    
    Pliki_Zapisanie_wezla(file, tree.root); // Rozpoczynamy zapis od korzenia
    
    file.close();
}

void Pliki::Pliki_Wczytanie_z_pliku_binarnego(BST& tree, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Nie mo¿na otworzyæ pliku do wczytania: " << filename << std::endl;
        return;
    }
    int value;
    while (file.read(reinterpret_cast<char*>(&value), sizeof(value))) {
        tree.BST_dodanie_elementu(value); // Dodaj ka¿dy element do drzewa
    }
    file.close();
}