#include "FileReader.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include "Product.h"
#include <chrono>


FileReader::FileReader(const std::string &fileName) : fileName(fileName) {}


const std::string &FileReader::getFileName() const {
    return fileName;
}


std::vector<Product> FileReader::ReadFile() {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    std::ifstream in(getFileName());
    if (in.fail())
        throw "Error while reading file.";
        //std::cerr << "Error while reading. " << std::endl;


    //stores StockCode as key and descp, quantity as value of map
    //std::unordered_map<std::string, std::pair<int, std::string> > productList;
    std::unordered_map<std::string, Product > productMap;
    std::vector<Product> productList;
    //std::vector<Product> productList;

    std::vector<std::string> row;
    std::string line, word, temp;

    std::getline(in, line); // for description of csv file

    while (in.good()) {
        row.clear();
        getline(in, line);
        if (line == "")
            break;

        std::stringstream s(line);

        while (std::getline(s, word, ';')) {
            row.push_back(word);
        }

        std::string stockCode = row[1]; //stock code of row
        std::string description = row[2]; // description part of row
        //int quantity =  abs(stoi(row[3])); // quantity of product
        int quantity =  stoi(row[3]); // quantity of product
        Product product(quantity, stockCode, description);

        /*
        auto it = std::find_if(productList.begin(), productList.end(), Product::Finder(product.getStockCode()));
        if(it != productList.end()){
            it->IncrementQuantity(product.getQuantity());
        }else{
            productList.push_back(product);
        }
        */

        auto got = productMap.find(product.getStockCode());

        if ( got == productMap.end() ){
            std::string stockCode = product.getStockCode();
            productMap.insert({stockCode, product});
        }
        else
            got->second.IncrementQuantity(product.getQuantity());


    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

     for(auto it= productMap.begin(); it!= productMap.end(); it++){
        productList.push_back(it->second);
    }

    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() /1000000.0 << "s"<<std::endl;
    return productList;
}

