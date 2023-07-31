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
        
        void nodeDesequilibrio(NodeTree<E>* p);

        void rightRotation(NodeTree<E>* p);
        void leftRotation(NodeTree<E>* p);
        
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
        this->nodeDesequilibrio(guia);
    }
}

template <class E> 
void BinarySearchTree<E>::nodeDesequilibrio(NodeTree<E>* p){

    int BF = 0, heightIz, heightDr;
    NodeTree<E>* aux2 = p;
    while (aux2 != this->rootB) {
        aux2 = aux2->parent();
        
        if(aux2->hasRight() && aux2->hasLeft()){
            aux2->setHeight(max(aux2->left()->getHeight(),aux2->right()->getHeight())+1);
            BF = aux2->left()->getHeight() - aux2->right()->getHeight();
        } else if(aux2->hasRight()){
            aux2->setHeight(aux2->right()->getHeight()+1);
            BF = -aux2->right()->getHeight();
        } else if(aux2->hasLeft()) {
            aux2->setHeight(aux2->left()->getHeight() +1);
            BF = aux2->left()->getHeight();
        }
        //Left Left Case
        if(BF>1 && p->getKey()<aux2->left()->getKey()){
            this->rightRotation(aux2);
        }   
        //Right Right Case
        else if(BF<-1 && p->getKey()> aux2->right()->getKey()){
            this->leftRotation(aux2);
        }

        //Left Right Case
        else if(BF>1 && p->getKey()>aux2->left()->getKey()){
            this->leftRotation(aux2->left());
            this->rightRotation(aux2);
        }
        //Right Left Case
        else if(BF<-1 && p->getKey()<aux2->right()->getKey()){
            this->rightRotation(aux2->right());
            this->leftRotation(aux2);
        }
        
    }
    cout<<endl;
    cout<<endl;
}
template <class E>
void BinarySearchTree<E>::leftRotation(NodeTree<E>* p) {
    NodeTree<E>* pare = p;                  // pare 
    NodeTree<E>* hijoDr = p->right();        // hijo Derecho

    pare->setRight(hijoDr->left());
    if(hijoDr->hasLeft())
        hijoDr->left()->setParent(pare);
    
    hijoDr->setLeft(pare);
    hijoDr->setParent(pare->parent());
    if(!p->isRoot()){
        if(hijoDr->parent()->right() == pare){
            hijoDr->parent()->setRight(hijoDr);
        } else if(hijoDr->parent()->left() == pare){
            hijoDr->parent()->setLeft(hijoDr);
        }
    } else{
        this->rootB = hijoDr;
    }
    pare->setParent(hijoDr);
    
    
    if(p->hasLeft() && p->hasRight()){
        p->setHeight(max(p->left()->getHeight(), p->right()->getHeight()) + 1);
    } else if(p->hasRight()){
        p->setHeight(p->right()->getHeight() + 1);
    } else if(p->hasLeft()){
        p->setHeight(p->left()->getHeight() + 1);
    } else{
        p->setHeight(1);
    }
    if(hijoDr->hasLeft() && hijoDr->hasRight()){
        hijoDr->setHeight(max(hijoDr->left()->getHeight(), hijoDr->right()->getHeight()) + 1);
    } else if(hijoDr->hasRight()){
        hijoDr->setHeight(hijoDr->right()->getHeight() + 1);
    } else if(hijoDr->hasLeft()){
        hijoDr->setHeight(hijoDr->left()->getHeight() + 1);
    } else{
        hijoDr->setHeight(1);
    }
}


template <class E>
void BinarySearchTree<E>::rightRotation(NodeTree<E>* p) {
    
    NodeTree<E>* pare = p;                  // pare 
    NodeTree<E>* hijoIz = p->left();        // hijo Izquierdo

    pare->setLeft(hijoIz->right());
    if(hijoIz->hasRight())
        hijoIz->right()->setParent(pare);
    
    hijoIz->setRight(pare);
    hijoIz->setParent(pare->parent());
    if(!p->isRoot()){
        if(hijoIz->parent()->right() == pare){
            hijoIz->parent()->setRight(hijoIz);
        } else if(hijoIz->parent()->left() == pare){
            hijoIz->parent()->setLeft(hijoIz);
        }
    } else{
        this->rootB = hijoIz;
    }
    pare->setParent(hijoIz);
    
    if(p->hasLeft() && p->hasRight()){
        p->setHeight(max(p->left()->getHeight(), p->right()->getHeight()) + 1);
    } else if(p->hasRight()){
        p->setHeight(p->right()->getHeight() + 1);
    } else if(p->hasLeft()){
        p->setHeight(p->left()->getHeight() + 1);
    } else{
        p->setHeight(1);
    }
    
    if(hijoIz->hasLeft() && hijoIz->hasRight()){
        hijoIz->setHeight(max(hijoIz->left()->getHeight(), hijoIz->right()->getHeight()) + 1);
    } else if(hijoIz->hasRight()){
        hijoIz->setHeight(hijoIz->right()->getHeight() + 1);
    } else if(hijoIz->hasLeft()){
        hijoIz->setHeight(hijoIz->left()->getHeight() + 1);
    } else{
        hijoIz->setHeight(1);
    }

}
#endif /* BINARYSEARCHTREE_H */

