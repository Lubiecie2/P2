#pragma once
 
#include "BST.h"
#include <fstream>

class Pliki {

public:
	static void Pliki_Wczytanie_z_pliku_tekstowego(BST& tree, const std::string& filename, bool clearTree);
	static void Pliki_Zapisanie_wezla(std::ofstream& file, Node* node);
	static void Pliki_Zapisywanie_do_pliki_binarnego(BST& tree, const std::string& filename);
	static void Pliki_Wczytanie_z_pliku_binarnego(BST& tree, const std::string& filename);
};