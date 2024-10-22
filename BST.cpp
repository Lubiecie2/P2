#include "BST.h"


BST::BST() : root(nullptr) {}

BST::~BST() {}

void BST::BST_dodanie_elementu(int v) {
    Node* newNode = new Node(v);

    if (root == nullptr) {
        root = newNode;         // <--- P�tla sprawdza czy drzewo jest puste je�li jest to ustawia nowy element jako korze�
        return;
    }

    Node* obecny_element = root; // <--- Wska�nik jest ustawiwany na korze�
    Node* rodzic = nullptr; // <--- Rodzic jest u�ywany do przechowywania wska�nika w�z�a nadrz�dnego 

    while (obecny_element != nullptr) { // <--- P�tla dzia�a do momentu a� dotrze do w�z�a w kt�ym odpowiednie poddrzewie jest puste   
                                        //      Lewe albo Prawe
        rodzic = obecny_element; 
        if (v < obecny_element->data) {   // <--- P�tla if przechodzi do lewej strony albo prawej w zale�no�ci od warto�ci elementu 
            obecny_element = obecny_element->left; // Przejd� do lewego poddrzewa
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