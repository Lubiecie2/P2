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

};