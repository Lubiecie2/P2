#include "BST.h"
#include <iostream>

BST::BST() : root(nullptr) {}

BST::~BST() {}

void BST::BST_dodanie_elementu(int v) {
    Node* newNode = new Node(v);

    if (root == nullptr) {
        root = newNode;         // <--- Pêtla sprawdza czy drzewo jest puste jeœli jest to ustawia nowy element jako korzeñ.
        return;
    }

    Node* obecny_element = root; // <--- WskaŸnik jest ustawiwany na korzeñ
    Node* rodzic = nullptr; // <--- Rodzic jest u¿ywany do przechowywania wskaŸnika wêz³a nadrzêdnego 

    while (obecny_element != nullptr) { // <--- Pêtla dzia³a do momentu a¿ dotrze do wêz³a w któym odpowiednie poddrzewie jest puste   Lewe albo Prawe
                                      
        rodzic = obecny_element; 
        if (v < obecny_element->data) {   // <--- Pêtla if przechodzi do lewej strony albo prawej w zale¿noœci od wartoœci elementu 
            obecny_element = obecny_element->left; 
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

Node* BST::BST_usun_element(Node* node, int v) {
    if (node == nullptr) {
        return nullptr;        // <--- Funkcja sprawdza czy istnieje element w drzewie, jeœli nie - zwraca nullptr
    }
    if (v < node->data) {        // <--- Jesli wartosc v jest mniejsza od wartosci biezacego drzewa, przechodzi do lewego poddrzewa
        node->left = BST_usun_element(node->left, v);
    }
    else if (v > node->data) {        // <--- Jesli wartosc v jest wieksza od wartosci biezacego drzewa, przechodzi do prawego poddrzewa
        node->right = BST_usun_element(node->right, v);
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
        node->right = BST_usun_element(node->right, temporary->data);        // <--- Usuniecie tego najmniejszego wezla w prawym poddrzewie, jego wartosc jest juz w biezacym wezle
    }
    return node;        // <--- Zwraca biezacy wezel
}

void BST::BST_usuwanie_elementu(int v) {
    root = BST_usun_element(root, v);
}

Node* BST::BST_szukaj_drogi(Node* node, int v) {
    if (node == nullptr) {        // <--- Zwraca nullptr, jesli wezel jest pusty
        return nullptr;
    }
    std::cout << node->data;        // <--- Wypisuje biezacy wezel, przez ktory przechodzi
    if (v < node->data) {
        std::cout << " -> ";
        return BST_szukaj_drogi(node->left, v);        // <--- Przeszukuje lewe poddrzewo rekurencyjnie
    }
    else if (v > node->data) {
        std::cout << " -> ";
        return BST_szukaj_drogi(node->right, v);        // <--- Przeszukuje prawe poddrzewo rekurencyjnie
    }
    else {
        return node;        // <--- Gdy znajdzie element, zwraca biezacy wezel
    }
}

void BST::BST_szukaj(int v) {
    std::cout << "Droga do elementu " << v << ": ";
    if (BST_szukaj_drogi(root, v) == nullptr) {        // <--- Sprawdza, czy istnieje poszukiwany element, jesli nie - wypisuje komunikat i zwraca nullptr
        std::cout << "Brak elementu." << std::endl;
    }
    else {
        std::cout << std::endl;
    }
}

void BST::BST_preorder(Node* node) {
   
    if (node == nullptr) {
        return;
    }

    std::cout << node->data << " "; // <--- Przetwarzany jest korzeñ
   
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

void BST::BST_zapisz_do_pliku(const std::string& nazwa_pliku) {
    std::ofstream plik(nazwa_pliku);
    if (!plik) {    // <--- Sprawdza, czy plik zostal otwarty
        std::cout << "Nie mo¿na otworzyæ pliku do zapisu." << std::endl;
        return;
    }
    BST_zapisz_inorder_do_pliku(root, plik);    // <--- Zapis drzewa
    plik.close();    // <--- Zamyka plik
}

void BST::BST_zapisz_inorder_do_pliku(Node* node, std::ofstream& plik) {    // <--- Metoda przyjmuje wskaznik do aktulnego wezla od referencje do obiektu pliku
    if (node == nullptr) {    // <--- Sprawdza, czy biezacy wezel jest pusty, konczy dzialanie metody
        return;
    }
    BST_zapisz_inorder_do_pliku(node->left, plik);    // <--- Zapisuje od lewego dziecka do biezacego wezla
    plik << node->data << " ";     // <--- Zapisuje do pliku wartosc biezacego wezla
    BST_zapisz_inorder_do_pliku(node->right, plik);
}