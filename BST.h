#pragma once
#include <fstream>

// @struct Node
// @brief Struktura reprezentujaca wezel w drzewie poszukiwan binarnych.
struct Node {
    int data;      // Zmienna przechowujaca wartosc wezla.
    Node* left;    // Wskaznik na lewego potomka wezla.
    Node* right;   // Wskaznik na prawego potomka wezla.

    // @brief Konstruktor tworzacy nowy wezel.
    // @param v Wartosc calkowita do zapisania w wezle.
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

// @class BST
// @brief Klasa reprezentujaca drzewo poszukiwan binarnych.
class BST {

public:

    Node* root;    // Wskaznik na korzen drzewa.

    // @brief Konstruktor tworzacy nowe drzewo BST.
    BST();

    // @brief Destruktor drzewa BST, usuwa wszystkie wezly.
    ~BST();

    // @brief Dodaje nowy element do drzewa BST.
    // @param v Wartosc calkowita do dodania.
    void BST_dodanie_elementu(int v);

    // @brief Usuwa element o podanej wartosci z drzewa.
    // @param v Wartosc elementu do usuniecia.
    void BST_usuwanie_elementu(int v);

    // @brief Usuwa element z drzewa zaczynajac od danego wezla.
    // @param node Wskaznik na wezel, od ktorego zaczyna sie usuwanie.
    // @param v Wartosc elementu do usuniecia.
    // @return Wskaznik na korzen poddrzewa po usunieciu elementu.
    Node* BST_usun_element(Node* node, int v);

    // @brief Szuka sciezki do wezla o podanej wartosci.
    // @param node Wskaznik na wezel, od ktorego zaczyna sie szukanie.
    // @param v Wartosc do znalezienia.
    // @return Wskaznik na wezel o podanej wartosci lub nullptr, jesli nie znaleziono.
    Node* BST_szukaj_drogi(Node* node, int v);

    // @brief Szuka wezla o podanej wartosci.
    // @param v Wartosc do znalezienia.
    void BST_szukaj(int v);

    // @brief Wykonuje przejscie preorder zaczynajac od podanego wezla.
    // @param node Wskaznik na wezel poczatkowy.
    void BST_preorder(Node* node);

    // @brief Wyswietla elementy drzewa w kolejnosci preorder.
    void BST_preorder_wyswietl();

    // @brief Wykonuje przejscie inorder zaczynajac od podanego wezla.
    // @param node Wskaznik na wezel poczatkowy.
    void BST_inorder(Node* node);

    // @brief Wyswietla elementy drzewa w kolejnosci inorder.
    void BST_inorder_wyswietl();

    // @brief Wykonuje przejscie postorder zaczynajac od podanego wezla.
    // @param node Wskaznik na wezel poczatkowy.
    void BST_postorder(Node* node);

    // @brief Wyswietla elementy drzewa w kolejnosci postorder.
    void BST_postorder_wyswietl();

    // @brief Usuwa cale drzewo zaczynajac od podanego wezla.
    // @param node Wskaznik na korzen drzewa lub poddrzewa do usuniecia.
    void BST_usun_cale_drzewo(Node* node);

    // @brief Usuwa cale drzewo i zwalnia przydzielona pamiec.
    void BST_usun_cale_drzewo_wyswietl();

    // @brief Zapisuje drzewo BST do pliku tekstowego.
    // @param nazwa_pliku Nazwa pliku, do ktorego zostanie zapisane drzewo.
    void BST_zapisz_do_pliku(const std::string& nazwa_pliku);

    // @brief Zapisuje elementy drzewa w kolejnosci inorder do pliku.
    // @param node Wskaznik na aktualny wezel drzewa.
    // @param plik Referencja do obiektu std::ofstream, do ktorego zostana zapisane elementy.
    void BST_zapisz_inorder_do_pliku(Node* node, std::ofstream& plik);
};