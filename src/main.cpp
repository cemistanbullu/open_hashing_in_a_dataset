#include <iostream>
#include <vector>
#include "FileReader.h"
#include "Product.h"
#include "QuickSort.h"
#include <chrono>


int main() {

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    FileReader reader("/Users/cemistanbullu/Desktop/OnlineRetail.csv");
    std::vector<Product> productList;
    std::vector<Product> list;
    //std::unordered_map<std::string, std::pair<int, std::string> > productList;
    //std::vector<Product> productList;
    try {
        productList = reader.ReadFile();
    }
    catch(const char * x){
        std::cout << "Caught exception from ReadFile(): " << x;
        return -1;
    }

    QuickSort q(productList);
    q.quickSort();
    q.printArray();

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "\nTotal Elapsed Time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() /1000000.0 << " seconds"<<std::endl;


    return 0;
}
