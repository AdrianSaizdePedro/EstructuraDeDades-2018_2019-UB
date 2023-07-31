#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <stdexcept>
#include <vector>
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
        int heightMax() const;
        int heightMin() const;
        bool isEmpty() const;
        NodeTree<E>* root();
        bool search (const E& element) const;
        void showPreorder() const {if (this->isEmpty()) cout << "Tree is empty" << endl;
                                    else this->showPreorder (this->rootB);};
        void showPostorder() const {if (this->isEmpty()) cout << "Tree is empty" << endl;
                                    else this->showPostorder (this->rootB);};
        void showInorder() const {if (this->isEmpty()) cout << "Tree is empty" << endl;
                                    else this->showInorder (this->rootB);};
                                    
        vector<int> getInorder(NodeTree<E>* elem) const;
        void showLeafNodes() const {if (this->isEmpty()) cout << "Tree is empty" << endl;
                                    else this->showLeafNodes(this->rootB);};
        
        /*Modificadores*/
        void insert (const E& element, int key);
    private:
        void setRoot(NodeTree<E>* root);
        int size(NodeTree<E>* subArbre) const;
        int heightMax(NodeTree<E>* p) const;
        int heightMin(NodeTree<E>* p) const;
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
    
    cout << "Eliminant node: " << p->getKey() << endl;
    delete p;
}






//Consultores

template <class E> 
void BinarySearchTree <E>::setRoot(NodeTree<E>* root){
    this->rootB(root);
}


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
int BinarySearchTree<E>::heightMax() const {
    if (rootB == 0){
        return 0;
    } 
    else {
        return heightMax(this->rootB);
    }
    
}

template <class E>
int BinarySearchTree<E>::heightMax(NodeTree<E>* p) const {
     if (p->isExternal()) {
        return 1;
    }
    else if (p->right() == 0) {
        return (heightMax(p->left()) + 1);
    }
    else if (p->left() == 0) {
        return (heightMax(p->right()) + 1);
    }
    else {
        return (max(heightMax(p->right()), heightMax(p->left()))+ 1);
    }
    
}



template <class E>
int BinarySearchTree<E>::heightMin() const {
    if (rootB == 0){
        return 0;
    } 
    else {
        return heightMin(this->rootB);
    }
    
}

template <class E>
int BinarySearchTree<E>::heightMin(NodeTree<E>* p) const {
     if (p->isExternal()) {
        return 1;
    }
    else if (p->right() == 0) {
        return (heightMin(p->left()) + 1);
    }
    else if (p->left() == 0) {
        return (heightMin(p->right()) + 1);
    }
    else {
        return (min(heightMin(p->right()), heightMin(p->left())) + 1 );
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
    bool trobat = guia->getKey() == element;
    bool final = false;
        while(!trobat && !final) {
            //Si les muntanyes coinciden
            if (guia->getKey() == element) {
                trobat = true;
            }
            //Si el nodo es mayor que el elemento a comparar
            else if(guia->getKey() > element) {
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
    cout << elem->getKey()<< " " << endl;
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
    cout << elem->getKey() << " ";
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
    cout << elem->getKey();
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
        cout << elem->getKey() << " " ;
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

/**
 * Inserts a node which will represent the given element. Notice that there can't
 * be two equal nodes (with the same element) and that the nodes are inserted orderly.
 * 
 * @param element
 */
template <class E> 
void BinarySearchTree <E>::insert(const E& element, int key) {
    if (this->isEmpty())  {
        this->rootB = new NodeTree<E>(element, key); 
    }
    else {
        NodeTree <E>* nou;
        NodeTree <E>* guia = this->rootB;
        while(guia->getKey() != key) {
            if(guia->getKey() > key) {
                if (guia->left() != 0) 
                    guia = guia->left(); 
                else {
                    nou = new NodeTree<E>(element, guia, key);
                    guia->setLeft(nou);
                    guia = nou;
                }
            }
            else {
                if (guia->right() != 0) 
                    guia = guia->right(); 
                else {
                    nou = new NodeTree<E>(element, guia, key);
                    guia->setRight(nou);
                    guia = nou;
                }
            }
        }
    }
}

#endif /* BINARYSEARCHTREE_H */

