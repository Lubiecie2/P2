#pragma once

#include "BST.h"
#include <fstream>

/// @class Pliki
/// @brief Klasa do operacji na plikach zwiazanych z drzewem BST.

class Pliki {

public:
    /// @brief Wczytuje dane z pliku tekstowego do drzewa BST.
    /// @param tree Referencja do drzewa BST, do ktorego zostana wczytane dane.
    /// @param filename Nazwa pliku tekstowego do wczytania.
    /// @param clearTree Flaga okreslajaca, czy drzewo powinno byc wyczyszczone przed wczytaniem.
    static void Pliki_Wczytanie_z_pliku_tekstowego(BST& tree, const std::string& filename, bool clearTree);

    /// @brief Zapisuje wezel drzewa BST do pliku.
    /// @param file Referencja do obiektu std::ofstream, do ktorego zostanie zapisany wezel.
    /// @param node Wskaznik na wezel drzewa BST, ktory ma zostac zapisany.
    static void Pliki_Zapisanie_wezla(std::ofstream& file, Node* node);

    /// @brief Zapisuje cale drzewo BST do pliku binarnego.
    /// @param tree Referencja do drzewa BST, ktore ma zostac zapisane.
    /// @param filename Nazwa pliku binarnego, do ktorego zostanie zapisane drzewo.
    static void Pliki_Zapisywanie_do_pliki_binarnego(BST& tree, const std::string& filename);

    /// @brief Wczytuje dane z pliku binarnego do drzewa BST.
    /// @param tree Referencja do drzewa BST, do ktorego zostana wczytane dane.
    /// @param filename Nazwa pliku binarnego do wczytania.
    static void Pliki_Wczytanie_z_pliku_binarnego(BST& tree, const std::string& filename);
};