#include "BST.h"


BST::BST() : root(nullptr) {}

BST::~BST() {}

void BST::BST_dodanie_elementu(int v) {
    Node* newNode = new Node(v);

    if (root == nullptr) {
        root = newNode;         // <--- Pêtla sprawdza czy drzewo jest puste jeœli jest to ustawia nowy element jako korzeñ
        return;
    }

    Node* obecny_element = root; // <--- WskaŸnik jest ustawiwany na korzeñ
    Node* rodzic = nullptr; // <--- Rodzic jest u¿ywany do przechowywania wskaŸnika wêz³a nadrzêdnego 

    while (obecny_element != nullptr) { // <--- Pêtla dzia³a do momentu a¿ dotrze do wêz³a w któym odpowiednie poddrzewie jest puste   
                                        //      Lewe albo Prawe
        rodzic = obecny_element; 
        if (v < obecny_element->data) {   // <--- Pêtla if przechodzi do lewej strony albo prawej w zale¿noœci od wartoœci elementu 
            obecny_element = obecny_element->left; // PrzejdŸ do lewego poddrzewa
        }
        else {
            obecny_element = obecny_element->right;
        }
    }

    if (v < rodzic->data) {
        rodzic->left = newNode; 
    }
    else {                          // <--- Pêtla dodaje element na praw¹ strone albo lew¹, w zale¿noœci od wartoœci rodzica
        rodzic->right = newNode; 
    }
}