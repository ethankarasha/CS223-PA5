#pragma once
#include "List.hpp"

template <typename T>
class HashTable
{
public:
    HashTable(int newSize, int collisions);
    ~HashTable();

    uint32_t getIndex(string key) const;
    int getIndexCh(vector<string> categories, string key) const;
    int getSize() const;
    T* getTable() const;

    void createTablePr(ifstream& inputstream, vector<string>& categoryVec);
    void createTableCh(ifstream& inputstream, vector<string>& categoryVec);
    void find(const string key) const;
    void insertProbe(T newProduct, int& numcollisons, int& numelements);
    void insertChain(Product newData, vector<string> categoryVec);
    void listInventory(string key, vector<string> categoryVec) const;

private:
    int collisionType; // 0 for chaining, 1 for probing
    int size; // depends on the data being inserted
    double loadFactor;
    T* productTable;
};

template <typename T>
inline HashTable<T>::HashTable(int newSize, int collisions)
{
    size = newSize;
    productTable = new T[size];
    collisionType = collisions;
}

template <typename T>
inline HashTable<T>::~HashTable()
{
    delete[] productTable;
}

template <typename T>
inline uint32_t HashTable<T>::getIndex(string key) const
{

    uint64_t hash_value = XXH3_64bits(key.c_str(), key.size());  // Using xxHash
    uint32_t index = hash_value % size;

    // cout << "Key: " << key << " -> Hash: " << hash_value << " -> Index: " << index << endl;

    if (size != 0)
    {
        return index;
    }
    else
    {
        cout << "Size = 0" << endl;
        return -1;
    }
}

template <typename T>
inline int HashTable<T>::getIndexCh(vector<string> categories, string key) const 
{
    int j;
    //cout << "Category Size: " << int(categories.size()) << endl;

    for (j = 0; j < int(categories.size()) + 1 ; j++)
    {
        if (categories[j] == key)
        {
            //cout << "Category Size: " << int(categories.size()) << endl;
            return j;
        }
    }

    return -1;
}

template <typename T>
inline int HashTable<T>::getSize() const
{
    return size;
}

template <typename T>
inline T *HashTable<T>::getTable() const
{
    return productTable;
}

template <typename T>
inline void HashTable<T>::createTablePr(ifstream& inputstream, vector<string>& categoryVec)
{
    T newData;
    int numcollisions = 0;
    int numelements = 0;

    while (inputstream.peek() != EOF)
    {
        newData = createProduct(inputstream, categoryVec);
        insertProbe(newData, numcollisions, numelements);
    }    
}

template <typename T>
inline void HashTable<T>::createTableCh(ifstream &inputstream, vector<string> &categoryVec)
{
    Product newData;
    
    while(inputstream.peek() != EOF)
    {
        newData = createProduct(inputstream, categoryVec);
        insertChain(newData, categoryVec);
    }
}

template <typename T>
inline void HashTable<T>::find(const string uniqID) const 
{
    uint32_t index;
    uint32_t i = 1;

    index = getIndex(uniqID);
    uint32_t ogIndex = index;

    if (productTable[index].getUniqId() == uniqID)
    {
        productTable[index].printData();
    }
    else
    {
        while (productTable[index].getUniqId() != uniqID) // follow the quadractic path until you find where it was inserted
        {
            index = (ogIndex + (i * i)) % size;
            i++;

            if (index == ogIndex)
            {
                cout << "Product Not found" << endl;
                return;
            }
        }
        productTable[index].printData();
    }
}

template <typename T>
inline void HashTable<T>::insertProbe(T newProduct, int& numcollisions, int& numelements)
{ 
    uint32_t indexPr = getIndex(newProduct.getUniqId());
    uint32_t originalIndex = indexPr;
    int i = 1;
    newProduct.exists = true;
    
    while (productTable[indexPr].exists) // if there has already been an insert, we have a collision
    {
        numcollisions++;
        indexPr = (originalIndex + (i * i)) % size;
        i++;
    }

    productTable[indexPr] = newProduct;
    numelements++;
    loadFactor = (double)numelements / size;
    
}

template <typename T>
inline void HashTable<T>::insertChain(Product newData, vector<string> categoryVec)
{
    int indexCh;

    for (auto i : newData.getCategories()) // go through a products categories
    {
        indexCh = getIndexCh(categoryVec, i); // get the index, insert in the list
        Node<Product>* pMem = new Node<Product>(newData);
        productTable[indexCh].insert(pMem);
    }
}

template <typename T>
inline void HashTable<T>::listInventory(string key, vector<string> categoryVec) const
{
    int index = getIndexCh(categoryVec, key);

    if (productTable[index].getHead() == nullptr)
    {
        cout << "NULL" << endl;
    }

    productTable[index].print(); // print out the list

    // for more info if wanted
    // cout << "Index = " << index << endl;
    // cout << "List Size: " << productTable[index].numNodes() << endl;
}
