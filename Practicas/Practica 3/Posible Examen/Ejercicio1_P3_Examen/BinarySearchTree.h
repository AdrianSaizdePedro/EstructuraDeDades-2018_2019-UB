#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <stdexcept>
#include "NodeTree.h"

using namespace std;

template <class E> class BinarySearchTree {
    public:
        /*Constructores y destructores*/
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree<E>& orig);
        virtual ~BinarySearchTree();
        void deleteTree(NodeTree<E>* p) const;
        
        /*Consultores*/
        int size() const; 
        int height() const;
        bool isEmpty() const;
        NodeTree<E>* root();
        bool search (const E& element) const;
        void showPreorder() const {if (this->isEmpty()) cout << "Tree is empty" << endl;
                                    else this->showPreorder (this->rootB);};
        void showPostorder() const {if (this->isEmpty()) cout << "Tree is empty" << endl;
                                    else this->showPostorder (this->rootB);};
        void showInorder() const {if (this->isEmpty()) cout << "Tree is empty" << endl;
                                    else this->showInorder (this->rootB);};
        void showLeafNodes() const {if (this->isEmpty()) cout << "Tree is empty" << endl;
                                    else this->showLeafNodes(this->rootB);};
        
        //Ejercicio 1
        NodeTree<E>* showACMB(const E element1, const E element2);
        NodeTree<E>* showACMB(NodeTree<E>* nodo, const E element1, const E element2);
        //Ejercicio 2
        E showMIN (const E& element);
        //Ejercicio 3
        bool hasOnlyOneChild();
        bool hasOnlyOneChild(NodeTree<E>* nodo);
        
        /*Modificadores*/
        void insert (const E& element);
    private:
        int size(NodeTree<E>* subArbre) const;
        int height(NodeTree<E>* p) const;
        void showPreorder(NodeTree<E>* elem) const;
        void showPostorder(NodeTree<E>* elem) const;
        void showInorder(NodeTree<E>* elem) const;
        void showLeafNodes(NodeTree<E>* elem) const;
        
        /*Atributos*/
        NodeTree<E>* rootB;
};

/**
 * Default constructor for TAD BinarySearchTree. It initilizes the tree with no members.
 */
template <class E> 
BinarySearchTree <E>::BinarySearchTree() {
    this->rootB = 0;
}

/**
 * Copy constructor of a tree
 */
template <class E> 
BinarySearchTree <E>::BinarySearchTree(const BinarySearchTree& orig) {
    this->rootB = orig->root();
}

/**
 * Default destructor for TAD BinarySearchTree. It deletes all tree nodes by deleting the root one.
 */
template <class E> 
BinarySearchTree <E>::~BinarySearchTree() {
    deleteTree(rootB);
}

template <class E>
void BinarySearchTree<E>::deleteTree(NodeTree<E>* p) const {
    if(p == NULL) return;
    
    deleteTree(p->left());
    deleteTree(p->right());
    
    cout << "Eliminant node: " << p->getElement() << endl;
    delete p;
}






//Consultores

/**
 * Returns the size of the tree (number of members). And distinguis if is empty or not.
 * 
 * @return int with the size of the tree
 */
template <class E> 
int BinarySearchTree <E>::size() const {
    if (rootB == 0) 
        return 0; 
    else 
        return size(rootB);
}

/**
 * Returns the size of the tree (number of members).
 * 
 * @return int with the size of the tree
 */
template <class E>
int BinarySearchTree <E>::size(NodeTree<E>* subArbre) const {
    if(subArbre->isExternal()){
        return 1;
    }
    else if(subArbre->left() != 0 && subArbre->right() != 0){
        return size(subArbre->left()) + size(subArbre->right()) + 1;
    }
    else if(subArbre->right() != 0){
        return size (subArbre->right()) + 1;
    }
    else{
        return size (subArbre->left()) + 1;
    }
}

// Altura de l'arbre
/**
 * Returns the height of the tree (number of members).
 * 
 * @return int with the height of the tree
 */
template <class E>
int BinarySearchTree<E>::height() const {
    if (rootB == 0){
        return 0;
    } 
    else {
        return height(this->rootB);
    }
    
}

template <class E>
int BinarySearchTree<E>::height(NodeTree<E>* p) const {
    if (p->isExternal()) {
        return 1;
    }
    else if (p->right() == 0) {
        return height(p->left()) + 1;
    }
    else if (p->left() == 0) {
        return height(p->right()) + 1;
    }
    else {
        return max(height(p->right()), height(p->left())) + 1;
    }
    
}


/**
 * Returns if the tree is empty or not (has no members)
 * 
 * @return true if only if the size of the tree is 0
 */
template <class E> 
bool BinarySearchTree <E>::isEmpty() const {
    return (this->size() == 0);
}

/**
 * Returns a pointer to the root Position node.
 * 
 * @return a pointer to the root Position node
 */
template <class E> 
NodeTree<E>* BinarySearchTree<E>::root() {
    if (this->isEmpty()){
        throw new out_of_range ("Tree is empty");
    }
    else 
        return this->rootB;
}

/**
 * Returns if an element is in the tree or not.
 * 
 * @param element
 * @return true if only if the element is in tree.
 */
template <class E> 
bool BinarySearchTree <E>::search(const E& element) const {
    NodeTree <E>* guia = this->rootB;
    bool trobat = guia->getElement() == element;
    bool final = false;
        while(!trobat && !final) {
            //Si les muntanyes coinciden
            if (guia->getElement() == element) {
                trobat = true;
            }
            //Si el nodo es mayor que el elemento a comparar
            else if(guia->getElement() > element) {
                if (!guia->left() == 0) {
                    guia = guia->left(); 
                }
                else {
                    final = true;
                }
            }
            //Si el nodo es menor que el elemento a comparar
            else {
                if (!guia->right() == 0) {
                    guia = guia->right(); 
                }
                else {
                    final = true;
                }
            }
        }
    return trobat;
}

/**
 * Auxiliary function that alows to print the tree in a preorder way by using recoursivity.
 * 
 * @param elem
 */
template <class E> 
void BinarySearchTree <E>::showPreorder(NodeTree<E>* elem) const {
    cout << elem->getElement()<< " ";
    if (!elem->isExternal()) {
        if(elem->left() != 0) 
            showPreorder (elem->left());
        if(elem->right() != 0) 
            showPreorder (elem->right());
    }
}

/**
 * Auxiliary function that alows to print the tree in a postorder way by using recoursivity.
 * 
 * @param elem
 */
template <class E> 
void BinarySearchTree <E>::showPostorder(NodeTree<E>* elem) const {
    if (!elem->isExternal()) {
        if(elem->left() != 0) 
            showPostorder (elem->left());
        if(elem->right() != 0)
            showPostorder (elem->right());
    }
    cout << elem->getElement() << " ";
}

/**
 * Auxiliary function that alows to print the tree in an inorder way by using recoursivity.
 * 
 * @param elem
 */
template <class E> 
void BinarySearchTree <E>::showInorder(NodeTree<E>* elem) const {
    if (!elem->isExternal() && elem->left() != 0) {
        showInorder (elem->left());
    }
    cout << elem->getElement() <<" ";
    if (!elem->isExternal() && elem->right() != 0) {
        showInorder (elem->right());
    }
}

/**
 * Auxiliary function that alows to print the the leafs of the tree by using recoursivity.
 * 
 * @param elem
 */
template <class E> 
void BinarySearchTree <E>::showLeafNodes(NodeTree<E>* elem) const {
    if (elem->isExternal()) {
        cout << elem->getElement() << " " ;
    }
    else {
        if (elem->left() != 0) {
            showLeafNodes(elem->left());
        }
        if (elem->right() != 0) {
            showLeafNodes(elem->right());
        }
    }
}
//Ejercicio 1
template <class E>
NodeTree<E>* BinarySearchTree<E>::showACMB(const E element1, const E element2){
    if(root() == nullptr){
        cout<<"El arbol está Vacío"<<endl;
    } else {
        if(element1<element2)
            return showACMB(root(), element1, element2);
        else
            return showACMB(root(), element2, element1);
    }
}

template <class E>
NodeTree<E>* BinarySearchTree<E>::showACMB(NodeTree<E>* nodo, const E element1, const E element2){
    if (nodo->getElement() == element1 || nodo->getElement() == element2){
        return nodo;
    } else if (element1<nodo->getElement() && element2>nodo->getElement()){
        return nodo;
    } else if (element1<nodo->getElement() && element2<nodo->getElement()){
        showACMB(nodo->left(),element1,element2);
    }else{
        showACMB(nodo->right(),element1,element2);
    }
    
}

//Ejercicio 2
template <class E>
E BinarySearchTree<E>::showMIN(const E& element){
    bool trobat = false;
    if (this->isEmpty())  {
        cout<<"Arbol Vacío"<<endl; 
    }
    else {
        NodeTree <E>* guia = this->rootB;
        while(!trobat) {
            if(guia->getElement() == element){
                return guia->getElement();
            }
            if(guia->getElement() > element) {
                if (guia->left() != 0 ) 
                    guia = guia->left(); 
                else {
                    while(guia->getElement() > element){
                        guia = guia->parent();
                        if(guia->getElement() == this->rootB->getElement()){
                            return -1;
                        }
                    }
                    return guia->getElement();
                }
            }
            else  {
                if (guia->right() != 0) 
                    guia = guia->right(); 
                else {
                    while(guia->getElement() > element){
                        guia = guia->parent();
                        if(guia->getElement() == this->rootB->getElement()){
                            return -1;
                        }
                    }
                    return guia->getElement();
                }
            }
        }
    }
}


//Ejericio 3
template <class E>
bool BinarySearchTree<E>::hasOnlyOneChild(){
    if(root() == nullptr){
        cout<<"El arbol está Vacío"<<endl;
    } else {
        return hasOnlyOneChild(root());
    }
}

template <class E>
bool BinarySearchTree<E>::hasOnlyOneChild(NodeTree<E>* nodo){
    if (nodo->isExternal())
        return true;
    else if(nodo->hasLeft() && nodo->hasRight())
        return false;
    else if(nodo->hasLeft()){
        hasOnlyOneChild(nodo->left());
    } else 
        hasOnlyOneChild(nodo->right());
}

/**
 * Inserts a node which will represent the given element. Notice that there can't
 * be two equal nodes (with the same element) and that the nodes are inserted orderly.
 * 
 * @param element
 */
template <class E> 
void BinarySearchTree <E>::insert(const E& element) {
    if (this->isEmpty())  {
        this->rootB = new NodeTree<E>(element); 
    }
    else {
        NodeTree <E>* nou;
        NodeTree <E>* guia = this->rootB;
        while(guia->getElement() != element) {
            
            if(guia->getElement() > element) {
                if (guia->left() != 0) 
                    guia = guia->left(); 
                else {
                    nou = new NodeTree<E>(element, guia);
                    guia->setLeft(nou);
                    guia = nou;
                }
            }
            else {
                if (guia->right() != 0) 
                    guia = guia->right(); 
                else {
                    nou = new NodeTree<E>(element, guia);
                    guia->setRight(nou);
                    guia = nou;
                }
            }
        }
    }
}

#endif /* BINARYSEARCHTREE_H */

