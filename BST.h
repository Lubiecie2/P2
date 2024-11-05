#pragma once
#include <fstream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

class BST {

public:

    Node* root;

    BST();
    ~BST();

    void BST_dodanie_elementu(int v);
    void BST_usuwanie_elementu(int v);
    Node* BST_usun_element(Node* node, int v);
    Node* BST_szukaj_drogi(Node* node, int v);
    void BST_szukaj(int v);
    void BST_preorder(Node* node);
    void BST_preorder_wyswietl();
    void BST_inorder(Node* node);
    void BST_inorder_wyswietl();
    void BST_postorder(Node* node);
    void BST_postorder_wyswietl();
    void BST_usun_cale_drzewo(Node* node);
    void BST_usun_cale_drzewo_wyswietl();
    void BST_zapisz_do_pliku(const std::string& nazwa_pliku);
    void BST_zapisz_inorder_do_pliku(Node* node, std::ofstream& plik);
};