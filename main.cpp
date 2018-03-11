#include <string>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::string letter;
    int i;
    std::string line;
    std::vector<std::string> result;
    std::ifstream reader("../lfsrs/output.txt");
    if (!reader) {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }

    for (i = 0; !reader.eof(); i++) {
        getline(reader, line);
        result.push_back(line);
    }
    for (auto const &item : result) {
        std::cout << item << std::endl;
    }
    
    return 0;
}