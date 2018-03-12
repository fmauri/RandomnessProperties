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

    /**
     * 2.13 NIST Cumulative Sums (Cusum) Test
     * If return value is > 0.01, accept the sequence as random
     * Forward mode=1 --- Backward mode=0
     * @return
     */
    double CumulativeSums(bool mode);

    double frequencyMonobit();

    double blockFrequency(int blockSize);

private:
    std::vector<bool> result;
    std::vector<int> partialSums;

};


#endif //RANDOMNESSPROPERTIES_STATISTICALTEST_H
