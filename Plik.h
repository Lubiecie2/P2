#pragma once

#include "BST.h"
#include <fstream>


 // @class Pliki
 // @brief Klasa do operacji na plikach zwi�zanych z drzewem BST.
 
class Pliki {

public:
    // @brief Wczytuje dane z pliku tekstowego do drzewa BST.
    // @param tree Referencja do drzewa BST, do kt�rego zostan� wczytane dane.
    // @param filename Nazwa pliku tekstowego do wczytania.
    // @param clearTree Flaga okre�laj�ca, czy drzewo powinno by� wyczyszczone przed wczytaniem.
    static void Pliki_Wczytanie_z_pliku_tekstowego(BST& tree, const std::string& filename, bool clearTree);

    // @brief Zapisuje w�ze� drzewa BST do pliku.
    // @param file Referencja do obiektu std::ofstream, do kt�rego zostanie zapisany w�ze�.
    // @param node Wska�nik na w�ze� drzewa BST, kt�ry ma zosta� zapisany.
    static void Pliki_Zapisanie_wezla(std::ofstream& file, Node* node);

    // @brief Zapisuje ca�e drzewo BST do pliku binarnego.
    // @param tree Referencja do drzewa BST, kt�re ma zosta� zapisane.
    // @param filename Nazwa pliku binarnego, do kt�rego zostanie zapisane drzewo.
    static void Pliki_Zapisywanie_do_pliki_binarnego(BST& tree, const std::string& filename);

    // @brief Wczytuje dane z pliku binarnego do drzewa BST.
    // @param tree Referencja do drzewa BST, do kt�rego zostan� wczytane dane.
    // @param filename Nazwa pliku binarnego do wczytania.
    static void Pliki_Wczytanie_z_pliku_binarnego(BST& tree, const std::string& filename);
};