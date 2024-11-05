#pragma once

// @struct Node
// @brief Struktura reprezentuj�ca w�ze� w drzewie poszukiwa� binarnych.
struct Node {
    int data;      // Zmienna przechowuj�ca warto�� w�z�a.
    Node* left;    // Wska�nik na lewego potomka w�z�a.
    Node* right;   // Wska�nik na prawego potomka w�z�a.

    // @brief Konstruktor tworz�cy nowy w�ze�.
    // @param v Warto�� ca�kowita do zapisania w w�le.
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

// @class BST
// @brief Klasa reprezentuj�ca drzewo poszukiwa� binarnych.
class BST {

public:

    Node* root;    // Wska�nik na korze� drzewa.

    // @brief Konstruktor tworz�cy nowe drzewo BST.
    BST();

    // @brief Destruktor drzewa BST, usuwa wszystkie w�z�y.
    ~BST();

    // @brief Dodaje nowy element do drzewa BST.
    // @param v Warto�� ca�kowita do dodania.
    void BST_dodanie_elementu(int v);

    // @brief Usuwa element o podanej warto�ci z drzewa.
    // @param v Warto�� elementu do usuni�cia.
    void BST_usuwanie_elementu(int v);

    // @brief Usuwa element z drzewa zaczynaj�c od danego w�z�a.
    // @param node Wska�nik na w�ze�, od kt�rego zaczyna si� usuwanie.
    // @param v Warto�� elementu do usuni�cia.
    // @return Wska�nik na korze� poddrzewa po usuni�ciu elementu.
    Node* BST_usun_element(Node* node, int v);

    // @brief Szuka �cie�ki do w�z�a o podanej warto�ci.
    // @param node Wska�nik na w�ze�, od kt�rego zaczyna si� szukanie.
    // @param v Warto�� do znalezienia.
    // @return Wska�nik na w�ze� o podanej warto�ci lub nullptr, je�li nie znaleziono.
    Node* BST_szukaj_drogi(Node* node, int v);

    // @brief Szuka w�z�a o podanej warto�ci.
    // @param v Warto�� do znalezienia.
    void BST_szukaj(int v);

    // @brief Wykonuje przej�cie preorder zaczynaj�c od podanego w�z�a.
    // @param node Wska�nik na w�ze� pocz�tkowy.
    void BST_preorder(Node* node);

    // @brief Wy�wietla elementy drzewa w kolejno�ci preorder.
    void BST_preorder_wyswietl();

    // @brief Wykonuje przej�cie inorder zaczynaj�c od podanego w�z�a.
    // @param node Wska�nik na w�ze� pocz�tkowy.
    void BST_inorder(Node* node);

    // @brief Wy�wietla elementy drzewa w kolejno�ci inorder.
    void BST_inorder_wyswietl();

    // @brief Wykonuje przej�cie postorder zaczynaj�c od podanego w�z�a.
    // @param node Wska�nik na w�ze� pocz�tkowy.
    void BST_postorder(Node* node);

    // @brief Wy�wietla elementy drzewa w kolejno�ci postorder.
    void BST_postorder_wyswietl();

    // @brief Usuwa ca�e drzewo zaczynaj�c od podanego w�z�a.
    // @param node Wska�nik na korze� drzewa lub poddrzewa do usuni�cia.
    void BST_usun_cale_drzewo(Node* node);

    // @brief Usuwa ca�e drzewo i zwalnia przydzielon� pami��.
    void BST_usun_cale_drzewo_wyswietl();
};