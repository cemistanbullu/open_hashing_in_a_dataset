#include "Product.h"


Product::Product(int quantity, std::string stockCode, const std::string &description) : Quantity(quantity),
                                                                                        StockCode(stockCode),
                                                                                        Description(description) {}

Product::Product(): Quantity(0), StockCode(0), Description("") {}

std::string Product::getStockCode() const {
    return StockCode;
}

const std::string &Product::getDescription() const {
    return Description;
}

int Product::getQuantity() const {
    return Quantity;
}


void Product::IncrementQuantity(int qunatity){
    Quantity += qunatity;
}
