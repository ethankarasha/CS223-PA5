#include "Node.hpp"

template <typename T>
class List
{

public:
    List();
    //List(List&& other) noexcept; 
    ~List();

    void insert(Node<T>* newNode);
    void insertEnd(Node<T>* newNode);
    void print();
    int numNodes();
    Node<T>* getHead();
    bool isEmpty();
    void setHead(Node<T>* newHead);
    T find(int index);

    void insertionSort(int type); // 1 for asc, 2 for desc

private:
    Node<T>* pHead;
    void destroyList(Node<T>* pHead);

};

template <typename T>
List<T>::List() //constructor for the list, initializes it and adds the commands from the csv file
{
    pHead = nullptr;
}

// template <typename T>
// inline List<T>::List(List &&other) noexcept
// {
//     pHead = other.pHead();
//     other.pHead = nullptr;

// }

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
inline void List<T>::insertEnd(Node<T> *newNode)
{
    Node<T>* pCur = pHead;

    if (pHead == nullptr)
    {
        pHead = newNode;
    }
    else
    {
        while (pCur->getNext() != nullptr)
        {
            pCur = pCur->getNext();
        }

        pCur->setNext(newNode);
        newNode->setPrev(pCur);
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
inline bool sortAsc(T obj1, T obj2)
{
    return obj1 < obj2;
}

template <typename T>
inline bool sortDesc(T obj1, T obj2)
{
    return obj1 > obj2;
}

template <typename T>
inline void List<T>::insertionSort(int type)
{
    for (int i = 1; i < this->numNodes(); i++)
    {
        Node<T>* pCur = pHead;
        for(int k = 0; k < i; k++) // find the node we want to sort
        {
            pCur = pCur->getNext();
        }
        
        Node<T>* pPrev = pCur->getPrev();

        if (type == 1)
        {
            // while we are not at the beginning ans should swap, swap
            // manage pointers so that we don't lose track
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
Node<T>* splitList(Node<T>* pHead)
{
    Node<T>* fast = pHead;
    Node<T>* slow = pHead;
    Node<T>* temp;

    // when fast reaches the end of the list, slow will be pointing to the middle node
    while (fast != nullptr && fast->getNext() != nullptr)
    {
        fast = fast->getNext()->getNext();
        if (fast != nullptr)
        {
            slow = slow->getNext();
        }
    }

    temp = slow->getNext();
    slow->setNext(nullptr);
    return temp;
}

template <typename T>
Node<T>* mergeSort(Node<T>* pHead, int type)
{
    Node<T>* subHead;

    if (pHead == nullptr || pHead->getNext() == nullptr)
    {
        return pHead;
    }

    subHead = splitList(pHead);

    Node<T>* sortedLeft = mergeSort(pHead, type);
    Node<T>* sortedRight = mergeSort(subHead, type);

    return merge(sortedLeft, sortedRight, type);
}

template <typename T>
Node<T>* merge(Node<T>*& head1, Node<T>*& head2, int type)
{
    Node<T>* pCur1 = head1;
    Node<T>* pCur2 = head2;
    Node<T>* newHead;

    if (head1 == nullptr)
    {
        return head2;
    }
    if (head2 == nullptr)
    {
        return head1;
    }


    if (type == 1)
    {
        Node<T>* pLess = lessThan(pCur1, pCur2);
        newHead = pLess; // tracks the lesser value;
        Node<T>* pMerged = newHead; // tracks the new list
    
        // move the pointer that we just took forward
        if (pLess == pCur1)
        {
            pCur1 = pCur1->getNext();
        }
        else if (pLess == pCur2)
        {
            pCur2 = pCur2->getNext();
        }
    
        // determing the lesser, append it and then move forward
        while (pCur1 != nullptr && pCur2 != nullptr)
        {
            pLess = lessThan(pCur1, pCur2);
            pMerged->setNext(pLess);
            pMerged = pMerged->getNext();
    
            if (pLess == pCur1)
            {
                pCur1 = pCur1->getNext();
            }
            else if (pLess == pCur2)
            {
                pCur2 = pCur2->getNext();
            }
        }
    
        // when one list is used up, just append the rest of the other list
        if (pCur1 == nullptr && pCur2 != nullptr)
        {
            while (pCur2 != nullptr)
            {
                pMerged->setNext(pCur2);
                pMerged = pMerged->getNext();
                pCur2 = pCur2->getNext();
            }
        }
    
        if (pCur2 == nullptr && pCur1 != nullptr)
        {
            while (pCur1 != nullptr)
            {
                pMerged->setNext(pCur1);
                pMerged = pMerged->getNext();
                pCur1 = pCur1->getNext();
            }
        }
    }

    if (type == 2) // same process but for the descending version
    {
        Node<T>* pMore = greaterThan(pCur1, pCur2);
        newHead = pMore; // tracks the greater value;
        Node<T>* pMerged = newHead; // tracks the new list

        if (pMore == pCur1)
        {
            pCur1 = pCur1->getNext();
        }
        else if (pMore == pCur2)
        {
            pCur2 = pCur2->getNext();
        }

        while (pCur1 != nullptr && pCur2 != nullptr)
        {
            pMore = greaterThan(pCur1, pCur2);
            pMerged->setNext(pMore);
            pMerged = pMerged->getNext();

            if (pMore == pCur1)
            {
                pCur1 = pCur1->getNext();
            }
            else if (pMore == pCur2)
            {
                pCur2 = pCur2->getNext();
            }
        }

        if (pCur1 == nullptr && pCur2 != nullptr)
        {
            while (pCur2 != nullptr)
            {
                pMerged->setNext(pCur2);
                pMerged = pMerged->getNext();
                pCur2 = pCur2->getNext();
            }
        }

        if (pCur2 == nullptr && pCur1 != nullptr)
        {
            while (pCur1 != nullptr)
            {
                pMerged->setNext(pCur1);
                pMerged = pMerged->getNext();
                pCur1 = pCur1->getNext();
            }
        }

    }
    
    return newHead;
}



template<typename T>
Node<T>*& greaterThan(Node<T>*& node1, Node<T>*& node2)
{
    if (node1->getData().getSellingPrice() >= node2->getData().getSellingPrice())
    {
        return node1;
    }
    else{
        return node2;
    }
}
template<typename T>
Node<T>*& lessThan(Node<T>*& node1, Node<T>*& node2)
{
    if (node1->getData().getSellingPrice() >= node2->getData().getSellingPrice())
    {
        return node2;
    }
    else{
        return node1;
    }
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


