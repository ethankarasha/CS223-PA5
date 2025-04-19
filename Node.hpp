#include "product.hpp"

template <typename T>
class Node
{
public:
    Node (T newProduct);
    ~Node();
    
    T getData();
    Node<T>* getNext() const;
    Node<T>* getPrev() const;

    void setNext(Node<T>* newNext);
    void setPrev(Node<T>* newPrev);
private:
    Node<T>* pNext;
    Node<T>* pPrev;
    T product;
};

template <typename T>
Node<T>::Node(T newProduct)
{
    product = newProduct; // calls overloaded assignment operator for T if necessary
    pNext = nullptr;
    pPrev = nullptr
}

template <typename T>
inline Node<T>::~Node()
{
    // nothing to delete inside here, deletion of Nodes is handled by destroy list and the list destructor
}

template <typename T>
inline T Node<T>::getData()
{
    return product;
}

template <typename T>
inline Node<T> *Node<T>::getNext() const
{
    return pNext;
}

template <typename T>
inline Node<T> *Node<T>::getPrev() const
{
    return pPrev;
}

template <typename T>
inline void Node<T>::setNext(Node<T>* newNext)
{
    pNext = newNext;
}

template <typename T>
inline void Node<T>::setPrev(Node<T> *newPrev)
{
    pPrev = newPrev;
}
