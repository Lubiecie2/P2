#pragma once

#include "BST.h"
#include <fstream>


 // @class Pliki
 // @brief Klasa do operacji na plikach zwi¹zanych z drzewem BST.
 
class Pliki {

public:
    // @brief Wczytuje dane z pliku tekstowego do drzewa BST.
    // @param tree Referencja do drzewa BST, do którego zostan¹ wczytane dane.
    // @param filename Nazwa pliku tekstowego do wczytania.
    // @param clearTree Flaga okreœlaj¹ca, czy drzewo powinno byæ wyczyszczone przed wczytaniem.
    static void Pliki_Wczytanie_z_pliku_tekstowego(BST& tree, const std::string& filename, bool clearTree);

    // @brief Zapisuje wêze³ drzewa BST do pliku.
    // @param file Referencja do obiektu std::ofstream, do którego zostanie zapisany wêze³.
    // @param node WskaŸnik na wêze³ drzewa BST, który ma zostaæ zapisany.
    static void Pliki_Zapisanie_wezla(std::ofstream& file, Node* node);

    // @brief Zapisuje ca³e drzewo BST do pliku binarnego.
    // @param tree Referencja do drzewa BST, które ma zostaæ zapisane.
    // @param filename Nazwa pliku binarnego, do którego zostanie zapisane drzewo.
    static void Pliki_Zapisywanie_do_pliki_binarnego(BST& tree, const std::string& filename);

    // @brief Wczytuje dane z pliku binarnego do drzewa BST.
    // @param tree Referencja do drzewa BST, do którego zostan¹ wczytane dane.
    // @param filename Nazwa pliku binarnego do wczytania.
    static void Pliki_Wczytanie_z_pliku_binarnego(BST& tree, const std::string& filename);
};