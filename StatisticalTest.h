//
// Created by mauri on 11.03.18.
//

#ifndef RANDOMNESSPROPERTIES_STATISTICALTEST_H
#define RANDOMNESSPROPERTIES_STATISTICALTEST_H

#include <string>
#include <fstream>
#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <boost/math/special_functions/gamma.hpp>

class StatisticalTest {
public:

    explicit StatisticalTest(std::vector<bool> input);

    double frequencyMonoBit();

    double blockFrequency(int blockSize);

    double runsTest();

private:
    std::vector<bool> result;

};


#endif //RANDOMNESSPROPERTIES_STATISTICALTEST_H
