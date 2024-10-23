#pragma once

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
    void BST_preorder(Node* node);
    void BST_preorder_wyswietl();
};