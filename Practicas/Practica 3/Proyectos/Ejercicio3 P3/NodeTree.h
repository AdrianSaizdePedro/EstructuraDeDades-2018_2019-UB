#ifndef POSITION_H
#define POSITION_H

template <class E> 
class NodeTree {
    public:
        NodeTree (const E& data, NodeTree<E>* padre);
        NodeTree (const E& data);
        NodeTree (const NodeTree& orig);
        virtual ~NodeTree();
        
        /*Consultores*/
        NodeTree<E>* parent();
        NodeTree<E>* right();
        NodeTree<E>* left();
        
        bool hasRight();
        bool hasLeft();
        bool isRoot();
        bool isExternal();
        const E& getElement() const;
        const int& getHeight() const;
        
        /*Modificadores*/
        void setElement(const E& data);
        void setRight(NodeTree<E>* rightAux);
        void setLeft(NodeTree<E>* leftAux);
        void setParent(NodeTree<E>* parentAux);
        void setHeight(const int& newHeight);
    
        private:
            NodeTree<E>* leftP;
            NodeTree<E>* rightP;
            NodeTree<E>* parentP;
            E elementP;
            int height;

};

/**
 * Default constructor for TAD Position. It initializes the node with no children
 * but it needs the value of the node and the parent.
 * 
 * @param element
 * @param parentAux
 */
template <class E> 
NodeTree <E>::NodeTree(const E& data, NodeTree<E>* padre) {
    this->elementP = data;
    this->parentP = padre;
    this->leftP = 0;
    this->rightP = 0;
    this->height = 1;
}

/**
 * Default constructor for TAD Position. It initializes the node with no children
 * but it needs the value of the node.
 * 
 * @param element
 */
template <class E> 
NodeTree <E>::NodeTree(const E& data) {
    this->elementP = data;
    this->leftP = 0;
    this->rightP = 0;
    this->height = 0;
}

template <class E> 
NodeTree <E>::NodeTree(const NodeTree& orig) {
    this->elementP = orig.elementP;
    this->leftP = orig.leftP;
    this->rightP = orig.rightP;
    this->parentP = orig.parentP;
    this->height = orig.height;
}

// destructor
template <class E>
NodeTree<E>::~NodeTree(){
    
}

/**
 * Returns the parant of the node.
 * 
 * @return the parent of the node
 */
template <class E> 
NodeTree<E>* NodeTree <E>::parent(){
    return this->parentP;
}

/**
 * Returns the right child of the node.
 * 
 * @return the right child of the node
 */
template <class E> 
NodeTree<E>* NodeTree <E>::right(){
    return this->rightP;
}

/**
 * Returns the left child of the node.
 * 
 * @return the left child of the node
 */
template <class E> 
NodeTree<E>* NodeTree <E>::left(){
    return this->leftP;
}

/**
 * Returns if the node has Right or not (of the tree)
 * 
 * @return true if only if the node has Right
 */
template <class E> 
bool NodeTree<E>::hasRight(){
    return (this->right() != 0);
}

/**
 * Returns if the node has Left or not (of the tree)
 * 
 * @return true if only if the node has Left
 */
template <class E> 
bool NodeTree<E>::hasLeft(){
    return (this->left() != 0);
}

/**
 * Returns if the node is the root or not (of the tree)
 * 
 * @return true if only if the node has no parent (is root)
 */
template <class E> 
bool NodeTree<E>::isRoot(){
    return (this->parent() == 0);
}

/**
 * Returns if the node is external or not (in the tree)
 * 
 * @return true if only if the node has no children (is external)
 */
template <class E> 
bool NodeTree<E>::isExternal(){
    return (this->left() == 0 && this->right() == 0);
}

/**
 * Returns the element of the Node
 * 
 * @return the element of the Node
 */
template <class E> 
const E& NodeTree<E>::getElement() const{
    return (this->elementP);
}

/**
 * Returns the height of the Node
 * 
 * @return the height of the Node
 */
template <class E> 
const int& NodeTree<E>::getHeight() const{
    return (this->height);
}





//Modificadores


/**
 * Sets the data of the nodetree
 * 
 * @param Data
 */
template <class E> 
void NodeTree<E>::setElement(const E& data) {
    this->elementP = data;
}

/**
 * Sets the right child of the node with a given one (as a pointer).
 * 
 * @param rightAux
 */
template <class E> 
void NodeTree<E>::setRight(NodeTree<E>* rightAux) {
    this->rightP = rightAux;
}

/**
 * Sets the left child of the node with a given one (as a pointer).
 * 
 * @param leftAux
 */
template <class E> 
void NodeTree<E>::setLeft(NodeTree<E>* leftAux) {
    this->leftP = leftAux;
}

/**
 * Changes the parent of the node with a given one (as a pointer).
 * 
 * @param parentAux
 */
template <class E> 
void NodeTree<E>::setParent(NodeTree<E>* parentAux) {
    this->parentP = parentAux;
}

/**
 * Cambia la altura
 * 
 * @param newHeight
 */
template <class E>
void NodeTree<E>::setHeight(const int& newHeight){
    this->height = newHeight;
}

#endif /* POSITION_H */

