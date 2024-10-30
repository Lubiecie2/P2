#include "BST.h"
#include <iostream>

BST::BST() : root(nullptr) {}

BST::~BST() {}

void BST::BST_dodanie_elementu(int v) {
    Node* newNode = new Node(v);

    if (root == nullptr) {
        root = newNode;         // <--- P�tla sprawdza czy drzewo jest puste je�li jest to ustawia nowy element jako korze�.
        return;
    }

    Node* obecny_element = root; // <--- Wska�nik jest ustawiwany na korze�
    Node* rodzic = nullptr; // <--- Rodzic jest u�ywany do przechowywania wska�nika w�z�a nadrz�dnego 

    while (obecny_element != nullptr) { // <--- P�tla dzia�a do momentu a� dotrze do w�z�a w kt�ym odpowiednie poddrzewie jest puste   Lewe albo Prawe
                                      
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

void BST::BST_usuwanie_elementu(int v) {
    root = usun_element(root, v);
}

Node* BST::usun_element(Node* node, int v) {
    if (root == nullptr) {
        return root;        // <--- Funkcja sprawdza czy istnieje element w drzewie, je�li nie - zwraca nullptr
    }
    if (v < node->data) {        // <--- Jesli wartosc v jest mniejsza od wartosci biezacego drzewa, przechodzi do lewego poddrzewa
        node->left = usun_element(node->left, v);
    }
    else if (v > node->data) {        // <--- Jesli wartosc v jest wieksza od wartosci biezacego drzewa, przechodzi do prawego poddrzewa
        node->right = usun_element(node->right, v);
    }
    else {        // <--- Jesli wartosc v jest rowna, znaleziono element do usuniecia
        if (node->left == nullptr) {        // <--- Jesli wezel ma tylko prawe poddrzewo lub jest lisciem
            Node* temporary = node->right;        // <--- Przechowuje wskaznik do prawego dziecka
            delete node;        // <--- Usuwa biezacy wezel
            return temporary;        // <--- Zwraca wskaznik lewego dziecka
        }
        if (node->right == nullptr) {// <--- Jesli wezel ma tylko lewe poddrzewo
            Node* temporary = node->left;        // <--- Przechowuje wskaznik do lewego dziecka
            delete node;        // <--- Usuwa biezacy wezel
            return temporary;        // <--- Zwraca wskaznik prawego dziecka
        }
        Node* temporary = node->right;        // <--- Jesli wezel ma dwoje dzieci, szukamy najmniejszy element w prawym poddrzewie
        while (temporary->left != nullptr) {
            temporary = temporary->left;        // <--- Przechodzimy w lewo by znalezc najmniejszy element
        }
        node->data = temporary->data;        // <--- Zamiana wartosciami biezacego wezla z najmniejszym prawego poddrzewa
        node->right = usun_element(node->right, temporary->data);        // <--- Usuniecie tego najmniejszego wezla w prawym poddrzewie, jego wartosc jest juz w biezacym wezle
    }
    return node;        // <--- Zwraca biezacy wezel
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