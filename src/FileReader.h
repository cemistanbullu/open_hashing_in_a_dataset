#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Product.h"

class FileReader {
private:
    std::string fileName;
public:
    FileReader(const std::string &fileName);

    const std::string &getFileName() const;

    std::vector<Product> ReadFile();

};

