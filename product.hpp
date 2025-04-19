#pragma once
#include "header.hpp"

class Product
{
public:
    Product();

    // setters, getters
    string getUniqId() const;
    string getProductName() const;
    string getBrandName() const;
    string getAsin() const;
    vector<string>& getCategories();
    string getUpceanCode() const;
    string getPrice() const;
    double getSellingPrice() const;
    string getQuantity() const;
    string getModelNumber() const;
    string getAboutProduct() const;
    string getProductSpecification() const;
    string getTechnicalDet() const;
    string getShippingWeight() const;
    string getProductDim() const;
    string getImage() const;
    string getVariants() const;
    string getSku() const;
    string getProductUrl() const;
    string getStock() const;
    string getProductDet() const;
    string getDimensions() const;
    string getColor() const;
    string getIngredients() const;
    string getDirections() const;
    string getIsAmazonSeller() const;
    string getSizeQualVar() const;
    string getProductDesc() const;

    void setUniqId(string newID);
    void setProductName(string newProd);
    void setBrandName(string newBrand);
    void setAsin(string newAsin);
    void setUpceanCode(string value);
    void setPrice(string value);
    void setSellingPrice(double value);
    void setQuantity(string value);
    void setModelNumber(string value);
    void setAboutProduct(string value);
    void setProductSpecification(string value);
    void setTechnicalDet(string value);
    void setShippingWeight(string value);
    void setProductDim(string value);
    void setImage(string value);
    void setVariants(string value);
    void setSku(string value);
    void setProductUrl(string value);
    void setStock(string value);
    void setProductDet(string value);
    void setDimensions(string value);
    void setColor(string value);
    void setIngredients(string value);
    void setDirections(string value);
    void setIsAmazonSeller(string value);
    void setSizeQualVar(string value);
    void setProductDesc(string value);

    
    void printData();
    bool deleted;
    bool exists;
    
private:
    string uniqID;
    string productName;
    string brandName;
    string asin;
    vector<string> categories;
    string upceanCode;
    string price;
    double sellingPrice;
    string quantity;
    string modelNumber;
    string aboutProduct;
    string productSpecification;
    string technicalDet;
    string shippingWeight;
    string productDim;
    string image;
    string variants;
    string sku;
    string productUrl;
    string stock;
    string productDet;
    string dimensions;
    string color;
    string ingredients;
    string directions;
    string isAmazonSeller;
    string sizeQualVar;
    string productDesc;    
};

Product createProduct(ifstream& inputstream, vector<string>& categoryVec);
string readInQuotes(ifstream& inputstream);
