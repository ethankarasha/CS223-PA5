#include "product.hpp"

Product::Product()
{
    deleted = false;
    exists = false;
}

string Product::getUniqId() const
{
    return uniqID;
}

string Product::getProductName() const
{
    return productName;
}

string Product::getBrandName() const
{
    return brandName;
}

string Product::getAsin() const
{
    return asin;
}

vector<string> &Product::getCategories()
{
    return categories;
}

string Product::getUpceanCode() const 
{ 
    return upceanCode; 
}

string Product::getPrice() const 
{ 
    return price; 
}

double Product::getSellingPrice() const 
{ 
    return sellingPrice; 
}

string Product::getQuantity() const 
{ 
    return quantity; 
}

string Product::getModelNumber() const 
{ 
    return modelNumber; 
}

string Product::getAboutProduct() const 
{ 
    return aboutProduct; 
}

string Product::getProductSpecification() const 
{ 
    return productSpecification; 
}

string Product::getTechnicalDet() const 
{ 
    return technicalDet; 
}

string Product::getShippingWeight() const 
{ 
    return shippingWeight; 
}

string Product::getProductDim() const 
{ 
    return productDim; 
}

string Product::getImage() const 
{ 
    return image; 
}

string Product::getVariants() const 
{ 
    return variants; 
}

string Product::getSku() const 
{ 
    return sku; 
}

string Product::getProductUrl() const 
{ 
    return productUrl; 
}

string Product::getStock() const 
{ 
    return stock; 
}

string Product::getProductDet() const 
{ 
    return productDet; 
}

string Product::getDimensions() const 
{ 
    return dimensions; 
}

string Product::getColor() const 
{ 
    return color; 
}

string Product::getIngredients() const 
{ 
    return ingredients; 
}

string Product::getDirections() const 
{ 
    return directions; 
}

string Product::getIsAmazonSeller() const 
{ 
    return isAmazonSeller; 
}

string Product::getSizeQualVar() const 
{ 
    return sizeQualVar; 
}

string Product::getProductDesc() const 
{ 
    return productDesc; 
}

void Product::setUniqId(string newID)
{
    uniqID = newID;
}

void Product::setProductName(string newProd)
{
    productName = newProd;
}

void Product::setBrandName(string newBrand)
{
    brandName = newBrand;
}

void Product::setAsin(string newAsin)
{
    asin = newAsin;
}

void Product::setUpceanCode(string value) 
{ 
    upceanCode = value; 
}

void Product::setPrice(string value) 
{ 
    price = value; 
}

void Product::setSellingPrice(double value) 
{ 
    sellingPrice = value; 
}

void Product::setQuantity(string value) 
{ 
    quantity = value; 
}

void Product::setModelNumber(string value) 
{ 
    modelNumber = value; 
}

void Product::setAboutProduct(string value) 
{ 
    aboutProduct = value; 
}

void Product::setProductSpecification(string value) 
{ 
    productSpecification = value; 
}

void Product::setTechnicalDet(string value) 
{ 
    technicalDet = value; 
}

void Product::setShippingWeight(string value) 
{ 
    shippingWeight = value; 
}

void Product::setProductDim(string value) 
{ 
    productDim = value; 
}

void Product::setImage(string value) 
{ 
    image = value; 
}

void Product::setVariants(string value) 
{ 
    variants = value; 
}

void Product::setSku(string value) 
{ 
    sku = value; 
}

void Product::setProductUrl(string value) 
{ 
    productUrl = value; 
}

void Product::setStock(string value) 
{ 
    stock = value; 
}

void Product::setProductDet(string value) 
{ 
    productDet = value; 
}

void Product::setDimensions(string value) 
{ 
    dimensions = value; 
}

void Product::setColor(string value) 
{ 
    color = value; 
}

void Product::setIngredients(string value) 
{ 
    ingredients = value; 
}

void Product::setDirections(string value) 
{ 
    directions = value; 
}

void Product::setIsAmazonSeller(string value) 
{ 
    isAmazonSeller = value; 
}

void Product::setSizeQualVar(string value) 
{ 
    sizeQualVar = value; 
}

void Product::setProductDesc(string value) 
{ 
    productDesc = value; 
}
void Product::printData()
{
    if (!uniqID.empty() && uniqID != "\"\"")
    {
        cout << "Uniq ID: " << uniqID << endl;
    }
    else
    {
        cout << "Uniq ID: NA" << endl;
    }
    if (!productName.empty() && productName != "\"\"") {
        cout << "Product Name: " << productName << endl;
    } else {
        cout << "Product Name: NA" << endl;
    }
    
    if (!brandName.empty() && brandName != "\"\"") {
        cout << "Brand Name: " << brandName << endl;
    } else {
        cout << "Brand Name: NA" << endl;
    }
    
    if (!asin.empty() && asin != "\"\"") {
        cout << "ASIN: " << asin << endl;
    } else {
        cout << "ASIN: NA" << endl;
    }

    if (!categories.empty())
    {
        cout << "Categories: ";
    
        for (auto i: categories)
        {
            cout << i;
            if (i != categories.back())
            {
                cout << ", ";
            }
        }
    }
    else
    {
        cout << "Categories: NA";
    }
    

    cout << endl;
    
    if (!upceanCode.empty() && upceanCode != "\"\"") {
        cout << "UPC/EAN Code: " << upceanCode << endl;
    } else {
        cout << "UPC/EAN Code: NA" << endl;
    }
    
    if (!price.empty() && price != "\"\"") {
        cout << "Price: " << price << endl;
    } else {
        cout << "Price: NA" << endl;
    }
    
    if (sellingPrice != 0.0) {
        cout << "Selling Price: " << sellingPrice << endl;
    } else {
        cout << "Selling Price: NA" << endl;
    }
    
    if (!quantity.empty() && quantity != "\"\"") {
        cout << "Quantity: " << quantity << endl;
    } else {
        cout << "Quantity: NA" << endl;
    }
    
    if (!modelNumber.empty() && modelNumber != "\"\"") {
        cout << "Model Number: " << modelNumber << endl;
    } else {
        cout << "Model Number: NA" << endl;
    }
    
    if (!aboutProduct.empty() && aboutProduct != "\"\"") {
        cout << "About Product: " << aboutProduct << endl;
    } else {
        cout << "About Product: NA" << endl;
    }
    
    if (!productSpecification.empty() && productSpecification != "\"\"") {
        cout << "Product Specification: " << productSpecification << endl;
    } else {
        cout << "Product Specification: NA" << endl;
    }
    
    if (!technicalDet.empty() && technicalDet != "\"\"") {
        cout << "Technical Details: " << technicalDet << endl;
    } else {
        cout << "Technical Details: NA" << endl;
    }
    
    if (!shippingWeight.empty() && shippingWeight != "\"\"") {
        cout << "Shipping Weight: " << shippingWeight << endl;
    } else {
        cout << "Shipping Weight: NA" << endl;
    }
    
    if (!productDim.empty() && productDim != "\"\"") {
        cout << "Product Dimensions: " << productDim << endl;
    } else {
        cout << "Product Dimensions: NA" << endl;
    }
    
    if (!image.empty() && image != "\"\"") {
        cout << "Image: " << image << endl;
    } else {
        cout << "Image: NA" << endl;
    }
    
    if (!variants.empty() && variants != "\"\"") {
        cout << "Variants: " << variants << endl;
    } else {
        cout << "Variants: NA" << endl;
    }
    
    if (!sku.empty() && sku != "\"\"") {
        cout << "SKU: " << sku << endl;
    } else {
        cout << "SKU: NA" << endl;
    }
    
    if (!productUrl.empty() && productUrl != "\"\"") {
        cout << "Product URL: " << productUrl << endl;
    } else {
        cout << "Product URL: NA" << endl;
    }
    
    if (!stock.empty() && stock != "\"\"") {
        cout << "Stock: " << stock << endl;
    } else {
        cout << "Stock: NA" << endl;
    }
    
    if (!productDet.empty() && productDet != "\"\"") {
        cout << "Product Details: " << productDet << endl;
    } else {
        cout << "Product Details: NA" << endl;
    }
    
    if (!dimensions.empty() && dimensions != "\"\"") {
        cout << "Dimensions: " << dimensions << endl;
    } else {
        cout << "Dimensions: NA" << endl;
    }
    
    if (!color.empty() && color != "\"\"") {
        cout << "Color: " << color << endl;
    } else {
        cout << "Color: NA" << endl;
    }
    
    if (!ingredients.empty() && ingredients != "\"\"") {
        cout << "Ingredients: " << ingredients << endl;
    } else {
        cout << "Ingredients: NA" << endl;
    }
    
    if (!directions.empty() && directions != "\"\"") {
        cout << "Directions: " << directions << endl;
    } else {
        cout << "Directions: NA" << endl;
    }
    
    if (!isAmazonSeller.empty() && isAmazonSeller != "\"\"") {
        cout << "Is Amazon Seller: " << isAmazonSeller << endl;
    } else {
        cout << "Is Amazon Seller: NA" << endl;
    }
    
    if (!sizeQualVar.empty() && sizeQualVar != "\"\"") {
        cout << "Size/Quantity Variant: " << sizeQualVar << endl;
    } else {
        cout << "Size/Quantity Variant: NA" << endl;
    }
    
    if (!productDesc.empty() && productDesc != "\"\"") 
    {
        cout << "Product Description: " << productDesc << endl;
    } else {
        cout << "Product Description: NA" << endl;
    }

}

Product createProduct(ifstream& inputstream, vector<string>& categoryVec)
{
    Product newProduct;

    newProduct.exists = true;
    string line;
    string token;
    bool insideQuotes = false;
    char c; // get leading quote


    // uniqId
    getline(inputstream, line, ',');
    newProduct.setUniqId(line);

    // Product Name
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setProductName(line);
    
    // Brand Name
    line.clear(); 
    line = readInQuotes(inputstream);
    newProduct.setBrandName(line);

    // Asin
    getline(inputstream, line, ',');
    newProduct.setAsin(line);           
    line.clear();

    // Categories
    c = inputstream.get();

    if (c == '\"')
    {
        while (c != ',' || insideQuotes)
        {
            if (c == '\"') // start of a quote, want to ignore commas in quotatations
            {
                insideQuotes = true;
                c = inputstream.get();
            }
            while (c != '\"') // add every character, including commas
            {
                if (c == '|') // we've read a category, put it in the vector
                {
                    // erase the space
                    if (!line.empty())
                    {
                        line.pop_back();
                    }

                    newProduct.getCategories().push_back(line);
                    auto it = find(categoryVec.begin(), categoryVec.end(), line);

                    if (it == categoryVec.end()) // the category hasn's been accounted for yet, push it into the vector
                    {
                        categoryVec.push_back(line);
                    }

                    c = inputstream.get(); // get the whitespace trailing after the '|'
                    line.clear();
                    c = inputstream.get();
                }

                line += c;
                c = inputstream.get();
            }

            if (!line.empty())
            {
                line.pop_back();
            }

            newProduct.getCategories().push_back(line);
            auto it = find(categoryVec.begin(), categoryVec.end(), line);

            if (it == categoryVec.end()) // the category hasn's been accounted for yet, push it into the vector
            {
                categoryVec.push_back(line);
            }

            // no longer in the quotes, update c and set the bool to false
            insideQuotes = false;
            c = inputstream.get();
        }
    }
    else
    {
        while (c != ',') // add every character
        {
            if (c == '|') // we've read a category, put it in the vector
            {
                // erase the space
                if (!line.empty())
                {
                    // Remove leading and trailing spaces
                    line.erase(0, line.find_first_not_of(" \t"));
                    line.erase(line.find_last_not_of(" \t") + 1);
                }
                newProduct.getCategories().push_back(line);
                auto it = find(categoryVec.begin(), categoryVec.end(), line);

                if (it == categoryVec.end()) // the category hasn's been accounted for yet, push it into the vector
                {
                    categoryVec.push_back(line);
                }

                c = inputstream.get(); // get the whitespace trailing after the '|'
                line.clear();
                c = inputstream.get();
            }

            line += c;
            c = inputstream.get();
        }

        if (!line.empty())
        {
            // Remove leading and trailing spaces
            line.erase(0, line.find_first_not_of(" \t"));
            line.erase(line.find_last_not_of(" \t") + 1);      
        }
        newProduct.getCategories().push_back(line);
        auto it = find(categoryVec.begin(), categoryVec.end(), line);

        if (it == categoryVec.end()) // the category hasn's been accounted for yet, push it into the vector
        {
            categoryVec.push_back(line);
        }
    }
    line.clear(); // resets the line


    // Upc Ean Code
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setUpceanCode(line);

    // List Price
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setPrice(line);

    // Selling Price
    double price;
    line.clear();
    line = readInQuotes(inputstream);
    line.erase(remove(line.begin(), line.end(), '$'), line.end());
    price = stod(line);
    newProduct.setSellingPrice(price);

    // Quantity
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setQuantity(line);

    // Model Number
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setModelNumber(line);

    // About Product
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setAboutProduct(line);

    // Product Specifications
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setProductSpecification(line);

        
    // Technical Details
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setTechnicalDet(line);
    
    // Shipping Weight
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setShippingWeight(line);

    // Product Dimensions
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setProductDim(line);

    // Image
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setImage(line);

    // Variants
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setVariants(line);

    // Sku
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setSku(line);

    // Product Url
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setProductUrl(line);

    // Stock
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setStock(line);

    // Product Details
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setProductDet(line);

    // Dimensions
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setDimensions(line);

    // Color
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setColor(line);

    // Ingredients
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setIngredients(line);

    // Direction To Use
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setDirections(line);

    // Is Amazon Seller
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setIsAmazonSeller(line);

    // Size Quantity Variant
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setSizeQualVar(line);

    // Product Description
    line.clear();
    line = readInQuotes(inputstream);
    newProduct.setProductDesc(line);

 
    return newProduct;
}

string readInQuotes(ifstream &inputstream)
{
    string line;
    bool insideQuotes = false;

    char c = inputstream.get(); // get leading quote  

    if (c != '\"') // there are no quotes, just read until you find a comma
    {
        while (c != ',' && c != '\n') // add every character
        {
            line += c;
            c = inputstream.get();
        }
    }
    else // we are at a leading quote
    {
        line += c;
        c = inputstream.get();
        insideQuotes = true;

        while ((c != ','  && c != '\n') || insideQuotes)
        {
            if (c == '\"') // start of a quote, want to ignore commas in quotatations
            {
                if (inputstream.peek() == '\"') // double quote
                {
                    line += c;
                    c = inputstream.get();
                    line += c;
                    c = inputstream.get();
                }
                else // closing quote
                {
                    line += c;
                    c = inputstream.get();
                    insideQuotes = false;
                }
            }
            else
            {
                line += c;
                c = inputstream.get();
            }
        }
    }

    return line;
}
