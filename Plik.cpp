#include "Plik.h"
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