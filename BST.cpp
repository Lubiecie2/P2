#include "BST.h"
#include <iostream>

BST::BST() : root(nullptr) {}

BST::~BST() {}

void BST::BST_dodanie_elementu(int v) {
    Node* newNode = new Node(v);

    if (root == nullptr) {
        root = newNode;         // <--- P�tla sprawdza czy drzewo jest puste je�li jest to ustawia nowy element jako korze�...
        return;
    }

    Node* obecny_element = root; // <--- Wska�nik jest ustawiwany na korze�
    Node* rodzic = nullptr; // <--- Rodzic jest u�ywany do przechowywania wska�nika w�z�a nadrz�dnego 

    while (obecny_element != nullptr) { // <--- P�tla dzia�a do momentu a� dotrze do w�z�a w kt�ym odpowiednie poddrzewie jest puste   
                                        //      Lewe albo Prawe
        rodzic = obecny_element; 
        if (v < obecny_element->data) {   // <--- P�tla if przechodzi do lewej strony albo prawej w zale�no�ci od warto�ci elementu 
            obecny_element = obecny_element->left; 
        }
        else {
            obecny_element = obecny_element->right;
        }
    }

    if (v < rodzic->data) {
        rodzic->left = newNode; 
    }
    else {                          // <--- P�tla dodaje element na praw� strone albo lew�, w zale�no�ci od warto�ci rodzica
        rodzic->right = newNode; 
    }
}

void BST::BST_preorder(Node* node) {
   
    if (node == nullptr) {
        return;
    }

    std::cout << node->data << " "; // <--- Przetwarzany jest korze�
   
    BST_preorder(node->left);     // <--- Przetwarzane jest lewe poddrzewie
    
    BST_preorder(node->right);    // <--- Przetwarzane jest prawe prawe poddrzewie
}


void BST::BST_preorder_wyswietl() {
   
    BST_preorder(root);  
    
    std::cout << std::endl;
}

void BST::BST_inorder(Node* node) {

    if (node == nullptr) {
        return;
    }

    BST_inorder(node->left);

    std::cout << node->data << " ";

    BST_inorder(node->right);

}

void BST::BST_inorder_wyswietl() {
    
    BST_inorder(root);

    std::cout << std::endl;
}

void BST::BST_postorder(Node* node) {

    if (node == nullptr) {
        return;
    }

    BST_postorder(node->left);

    BST_postorder(node->right);

    std::cout << node->data << " ";
}

void BST::BST_postorder_wyswietl() {

    BST_postorder(root);

    std::cout << std::endl;
}

void BST::BST_usun_cale_drzewo(Node* node) {
  
    if (node == nullptr) {
        return;
    }

    BST_usun_cale_drzewo(node->left);

    BST_usun_cale_drzewo(node->right);

    std::cout << node->data << std::endl;
    
    delete node;
}

void BST::BST_usun_cale_drzewo_wyswietl() {
    
    BST_usun_cale_drzewo(root);
    
    root = nullptr;
}