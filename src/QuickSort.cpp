#include "QuickSort.h"
#include <iostream>
#include <vector>

QuickSort::QuickSort(std::vector<Product> productList):ProductList(productList) {}

int QuickSort::partition(int low, int high) {
    int pivot = ProductList.at(high).getQuantity(); // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++){

        if (ProductList[j].getQuantity() < pivot){
            i++;
            swap(i, j);
        }
    }
    swap(i+1, high);
    return (i + 1);
}

void QuickSort::swap(int a, int b) {
    std::swap(ProductList[a],ProductList[b]);
}

void QuickSort::printArray() {
    int i,k = 1;
    printf("%-23s%-40s%-15s\n","Product(StockCode)","Description","TotalQuantity");
    std::cout<< "-------------------------------------------------------------------------------" << std::endl;
    for (i = ProductList.size()-1; i > ProductList.size()-11; i--){
        printf("%d- %-20s%-40s%d\n", k, ProductList[i].getStockCode().c_str(),ProductList[i].getDescription().c_str(),ProductList[i].getQuantity());
        k++;
    }
}

void QuickSort::quickSort(int low, int high) {
    if (low < high)
    {

        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void QuickSort::quickSort() {
    quickSort(0, ProductList.size()-1);
}

QuickSort::QuickSort() {}
