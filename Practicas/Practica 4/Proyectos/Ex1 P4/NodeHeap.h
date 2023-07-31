#ifndef NODE_HEAP
#define NODE_HEAP

template <class E> 
class NodeHeap {
    public:
        NodeHeap (const E& data, int pKey);
        NodeHeap (const NodeHeap& orig);
        virtual ~NodeHeap();
        
        
        /*Consultores*/
        const E& getValue() const;
        const int getKey() const;
        
        /*Modificadores*/
        void setValue(const E& value);
        void setKey(int key);

    private:
        E value;
        int key;
};

/**
 * Default constructor for TAD Position. It initializes the node with teh value 
 * and the Key
 *  
 * @param element
 * @param key
 */
template <class E> 
NodeHeap <E>::NodeHeap(const E& data, int pKey){
    this->value = data;
    this->key = pKey;
}
/**
 * Default constructor for TAD Position. It initializes the node with no children
 * but it needs the value of the node.
 * 
 * @param element
 */
template <class E> 
NodeHeap <E>::NodeHeap(const NodeHeap& orig){
    this->value = orig.value;
    this->key = orig.key;
}



// destructor
template <class E> 
NodeHeap <E>::~NodeHeap(){

}






//Consultores

/**
 * Returns the element of the Node
 * 
 * @return the element of the Node
 */
template <class E> 
const E& NodeHeap<E>::getValue() const{
    return this->value;
}

/**
 * Returns the key of the node
 * 
 * @return the key of the Node
 */
template <class E> 
const int NodeHeap<E>::getKey() const{
    return (this->key);
}



//Modificadores


/**
 * Sets the data of the nodetree
 * 
 * @param Data
 */
template <class E> 
void NodeHeap<E>::setValue(const E& data) {
    this->value = data;
}

/**
 * Sets the key of the nodetree
 * 
 * @param Key
 */
template <class E> 
void NodeHeap<E>::setKey(int key) {
    this->key = key;
}


#endif /* NODE_HEAP */

