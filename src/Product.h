#ifndef ONLINERETAILANALYZER_PRODUCT_H
#define ONLINERETAILANALYZER_PRODUCT_H

#include <iostream>
#include <string>

class Product {


private:
    int Quantity;
    std::string StockCode;
    std::string Description;
public:


    Product(int quantity, std::string stockCode, const std::string &description);

    Product();

    void IncrementQuantity(int quantity);

    std::string getStockCode() const;

    const std::string &getDescription() const;

    int getQuantity() const;

};


#endif //ONLINERETAILANALYZER_PRODUCT_H
