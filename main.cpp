#include "hashTable.hpp"
#include <iostream>
#include <string>

using namespace std;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(string line, const HashTable<Product> &probeHash, const HashTable<List<Product>> &chainHash, const vector<string> &categoryVec)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        string ID;
        cout << "Enter the Product Unique ID" << endl;
        cin >> ID;
        cin.ignore();
        cout << "Inside Eval command, Line: " << ID << endl;

        probeHash.find(ID);
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        string category;
        cout << "Enter the Category" << endl;
        getline(cin, category);

        chainHash.listInventory(category, categoryVec);
    }
}

void bootStrap(HashTable<Product> &probeHash, HashTable<List<Product>> &chainHash, vector<string> &categoryVec)
{
    ifstream inputstream;
    inputstream.open("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv");

    // get header
    string header;
    getline(inputstream, header, '\n');
        

    // create Hash Table for find()
    probeHash.createTablePr(inputstream, categoryVec);
    categoryVec.clear();
    inputstream.close();


    //create Hash Table for listInv
    // need to restart the file to read into the chaining table
    inputstream.open("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv");
    getline(inputstream, header, '\n');
    chainHash.createTableCh(inputstream, categoryVec); 
    inputstream.close();

    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
}

int main(int argc, char const *argv[])
{
 
    HashTable<Product> probeHash(100003, 1);
    HashTable<List<Product>> chainHash(1221, 0);
    vector<string> categories;
    
    string line;
    bootStrap(probeHash, chainHash, categories);
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line, probeHash, chainHash, categories);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }


    return 0;
}
