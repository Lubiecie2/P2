#pragma once
 
#include "BST.h"
#include <fstream>

class Pliki {

public:
	static void Pliki_Wczytanie_z_pliku_tekstowego(BST& tree, const std::string& filename, bool clearTree);
};