#ifndef ONLINERETAILANALYZER_QUICKSORT_H
#define ONLINERETAILANALYZER_QUICKSORT_H


#include <vector>
#include "Product.h"

class QuickSort {
private:
public:
    QuickSort();

private:
    std::vector<Product> ProductList;
    int partition (int low, int high);
    void swap(int a, int b);
    void quickSort(int low, int high);


public:

    QuickSort(std::vector<Product> productList);

    void printArray();
    void quickSort();

};


#endif //ONLINERETAILANALYZER_QUICKSORT_H
