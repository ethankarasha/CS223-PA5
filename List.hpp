#include "Node.hpp"

template <typename T>
class List
{

public:
    List();
    ~List();

    void insert(Node<T>* newNode);
    void print();
    int numNodes();
    Node<T>* getHead();
    bool isEmpty();
    void setHead(Node<T>* newHead);
    T find(int index);

    void insertionSort(int type); // 1 for asc, 2 for desc

private:
    Node<T>* pHead;
    bool sortAsc(double obj1, double obj2);
    bool sortDesc(double obj1, double obj2);
    void destroyList(Node<T>* pHead);

};

template <typename T>
List<T>::List() //constructor for the list, initializes it and adds the commands from the csv file
{
    pHead = nullptr;
}

template <typename T>
inline List<T>::~List()
{
    if (pHead != nullptr)
    {
        destroyList(pHead);
    }
}

template<typename T>
void List<T>::insert(Node<T>* newNode)
{
    //cout << "pHead: " << pHead << endl; // Check the value of pHead
    //cout << "newNode: " << newNode << endl; // Check if newNode is valid

   if (pHead == nullptr) // if the list is empty, just assign the head to the new node
   {
        pHead = newNode;
   }
   else // new node should point to the head, then the head should be updated to the new node
   {
        newNode->setNext(pHead);
        pHead->setPrev(newNode);
        pHead = newNode;
   }

}

template <typename T>
inline void List<T>::print()
{
    Node<T>* pCur = pHead;

    while(pCur != nullptr) // traverses through the list, and uses the overloaded operator to print data
    {
        cout << "Uniq Id: " << pCur->getData().getUniqId() << endl
        << "Product Name: " << pCur->getData().getProductName() << endl 
        << "Selling Price: " << pCur->getData().getSellingPrice() << endl;

        pCur = pCur->getNext();
    }
}

template <typename T>
inline int List<T>::numNodes() // counts the number of nodes in the list
{
    int num = 0;
    Node<T>* pCur = pHead;

    while (pCur != nullptr)
    {
        pCur = pCur->getNext();
        num++;
    }

    return num;
}

template <typename T>
inline Node<T> *List<T>::getHead()
{
    return this->pHead;
}

template <typename T>
inline bool List<T>::isEmpty()
{
    return (pHead == nullptr);
}

template <typename T>
inline void List<T>::setHead(Node<T> *newHead)
{
    pHead = newHead;
}

template <typename T>
inline T List<T>::find(int index) //finds node at a given index and returns the data in the node
{
    Node<T>* pCur = pHead;
    if (index >= this->numNodes())
    {
        cout << "Please choose a number greater than or equal to " << numNodes() << ": " << endl;
        cin >> index;
    }

    for (int i = 0; i < index; i++)
    {
        pCur = pCur->getNext();
    }

    return pCur->getData();
}

template <typename T>
inline void List<T>::insertionSort(int type)
{
    for (int i = 1; i < this->numNodes(); i++)
    {
        Node<T>* pCur = pHead;
        for(int k = 0; k < i; k++)
        {
            pCur = pCur->getNext();
        }
        
        Node<T>* pPrev = pCur->getPrev();

        if (type == 1)
        {
            while(pCur != pHead && sortAsc(pCur->getData().getSellingPrice(), pPrev->getData().getSellingPrice()))
            {
        
                pPrev->setNext(pCur->getNext());
                pCur->setNext(pPrev);
                if (pPrev->getPrev() != nullptr)
                {
                    pPrev->getPrev()->setNext(pCur);
                }
    
                pCur->setPrev(pPrev->getPrev());
                pPrev->setPrev(pCur);
    
                if (pPrev->getNext() != nullptr)
                {
                    pPrev->getNext()->setPrev(pPrev);
                }
                
                if(pPrev->getData().getUniqId() == pHead->getData().getUniqId())
                {
                    pHead = pCur;
                    pPrev = nullptr;
                }
                else
                {
                    pPrev = pCur->getPrev();
                }
            }
        }
        if (type == 2)
        {
            while(pCur != pHead && sortDesc(pCur->getData().getSellingPrice(), pPrev->getData().getSellingPrice()))
        {
    
            pPrev->setNext(pCur->getNext());
            pCur->setNext(pPrev);
            if (pPrev->getPrev() != nullptr)
            {
                pPrev->getPrev()->setNext(pCur);
            }

            pCur->setPrev(pPrev->getPrev());
            pPrev->setPrev(pCur);

            if (pPrev->getNext() != nullptr)
            {
                pPrev->getNext()->setPrev(pPrev);
            }
            
            if(pPrev->getData().getUniqId() == pHead->getData().getUniqId())
            {
                pHead = pCur;
                pPrev = nullptr;
            }
            else
            {
                pPrev = pCur->getPrev();
            }
        }
        }
    }
}

template <typename T>
inline bool List<T>::sortAsc(double obj1, double obj2)
{
    return obj1 < obj2;
}

template <typename T>
inline bool List<T>::sortDesc(double obj1, double obj2)
{
    return obj1 > obj2;
}

template <typename T>
inline void List<T>::destroyList(Node<T> *pHead)
{
    Node<T>* pTemp;

    while (pHead != nullptr) // while we still have nodes in the list
    {
        pTemp = pHead;
        pHead = pHead->getNext(); //updates the head pointer then deletes the previous head
        delete pTemp;
    }

}
