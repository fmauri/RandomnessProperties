#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>
#include "StatisticalTest.h"

int main() {
    std::ifstream reader("../lfsrs/test2.txt");
    if (!reader) {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }
    std::vector<bool> result;
    std::string line;
    for (int i = 0; !reader.eof(); i++) {
        getline(reader, line);
        if (line != "0" && line != "1") { break; }
        result.push_back(line == "1");
    }
    StatisticalTest st(result);
    std::cout << st.frequencyMonobit() << std::endl;
    std::cout << st.blockFrequency(3) << std::endl;
    return 0;
}