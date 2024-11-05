#pragma once

// @struct Node
// @brief Struktura reprezentuj¹ca wêze³ w drzewie poszukiwañ binarnych.
struct Node {
    int data;      // Zmienna przechowuj¹ca wartoœæ wêz³a.
    Node* left;    // WskaŸnik na lewego potomka wêz³a.
    Node* right;   // WskaŸnik na prawego potomka wêz³a.

    // @brief Konstruktor tworz¹cy nowy wêze³.
    // @param v Wartoœæ ca³kowita do zapisania w wêŸle.
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

// @class BST
// @brief Klasa reprezentuj¹ca drzewo poszukiwañ binarnych.
class BST {

public:

    Node* root;    // WskaŸnik na korzeñ drzewa.

    // @brief Konstruktor tworz¹cy nowe drzewo BST.
    BST();

    // @brief Destruktor drzewa BST, usuwa wszystkie wêz³y.
    ~BST();

    // @brief Dodaje nowy element do drzewa BST.
    // @param v Wartoœæ ca³kowita do dodania.
    void BST_dodanie_elementu(int v);

    // @brief Usuwa element o podanej wartoœci z drzewa.
    // @param v Wartoœæ elementu do usuniêcia.
    void BST_usuwanie_elementu(int v);

    // @brief Usuwa element z drzewa zaczynaj¹c od danego wêz³a.
    // @param node WskaŸnik na wêze³, od którego zaczyna siê usuwanie.
    // @param v Wartoœæ elementu do usuniêcia.
    // @return WskaŸnik na korzeñ poddrzewa po usuniêciu elementu.
    Node* BST_usun_element(Node* node, int v);

    // @brief Szuka œcie¿ki do wêz³a o podanej wartoœci.
    // @param node WskaŸnik na wêze³, od którego zaczyna siê szukanie.
    // @param v Wartoœæ do znalezienia.
    // @return WskaŸnik na wêze³ o podanej wartoœci lub nullptr, jeœli nie znaleziono.
    Node* BST_szukaj_drogi(Node* node, int v);

    // @brief Szuka wêz³a o podanej wartoœci.
    // @param v Wartoœæ do znalezienia.
    void BST_szukaj(int v);

    // @brief Wykonuje przejœcie preorder zaczynaj¹c od podanego wêz³a.
    // @param node WskaŸnik na wêze³ pocz¹tkowy.
    void BST_preorder(Node* node);

    // @brief Wyœwietla elementy drzewa w kolejnoœci preorder.
    void BST_preorder_wyswietl();

    // @brief Wykonuje przejœcie inorder zaczynaj¹c od podanego wêz³a.
    // @param node WskaŸnik na wêze³ pocz¹tkowy.
    void BST_inorder(Node* node);

    // @brief Wyœwietla elementy drzewa w kolejnoœci inorder.
    void BST_inorder_wyswietl();

    // @brief Wykonuje przejœcie postorder zaczynaj¹c od podanego wêz³a.
    // @param node WskaŸnik na wêze³ pocz¹tkowy.
    void BST_postorder(Node* node);

    // @brief Wyœwietla elementy drzewa w kolejnoœci postorder.
    void BST_postorder_wyswietl();

    // @brief Usuwa ca³e drzewo zaczynaj¹c od podanego wêz³a.
    // @param node WskaŸnik na korzeñ drzewa lub poddrzewa do usuniêcia.
    void BST_usun_cale_drzewo(Node* node);

    // @brief Usuwa ca³e drzewo i zwalnia przydzielon¹ pamiêæ.
    void BST_usun_cale_drzewo_wyswietl();
};