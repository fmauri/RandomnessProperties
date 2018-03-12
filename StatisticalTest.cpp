//
// Created by mauri on 11.03.18.
//

#include "StatisticalTest.h"

StatisticalTest::StatisticalTest(std::vector<bool> input) {
    result = std::move(input);
    int sum = 0;
    for (int i = 0; i < result.size(); i++) {
        for (unsigned long j = 0; j <= i; j++) {
            sum += (result.at(j) ? 1 : -1);
        }
        partialSums.push_back(sum);
        sum = 0;
    }
}

double StatisticalTest::CumulativeSums(bool mode) {

    std::vector<int> partialSumsDer;
    partialSumsDer = partialSums;
    partialSumsDer.push_back(0);
    partialSumsDer.insert(partialSumsDer.begin(), 0);
    return 0;
}

double StatisticalTest::frequencyMonoBit() {
    int sum = 0;
    for (auto const &item: result) {
        sum += (item ? 1 : -1);
    }
    double testStatistic = std::abs(sum) / std::sqrt(result.size());
    double result = erfc(testStatistic / std::sqrt(2));
    return result;
}

double StatisticalTest::blockFrequency(const int blockSize) {
    unsigned long blocksNum = result.size() / blockSize;
    std::vector<double> proportions;
    double sum = 0;
    unsigned long x = 0;
    for (unsigned long i = 0; i < blocksNum; ++i) {
        for (int j = 0; j < blockSize; j++) {
            sum += (result.at(x) ? 1 : 0);
            ++x;
        }
        proportions.push_back((sum / blockSize));
        sum = 0;
    }
    double summationNotation = 0;
    for (auto const &item: proportions) {
        summationNotation += (pow((item - 0.5), 2.0000));
    }
    double x2obs = (4 * (blockSize * (summationNotation)));
    double result = boost::math::gamma_p(blocksNum / 2.00, x2obs / 2.00);
    return (1 - result);
}

double StatisticalTest::TestStatisticAndReferenceDistribution() {
    double sum = 0;
    for (auto &&i : result) {
        sum += (i ? 1 : 0);
    }
    double p = sum / result.size();
    double tau = 2 / (sqrt(result.size()));
    if (fabs(p - double(1 / 2)) >= tau) {
        return 0;
    }
    sum = 1;
    for (unsigned long i = 0; i < result.size() - 1; ++i) {
        sum += (result.at(i) == result.at(i + 1) ? 0 : 1);
    }
    double up = fabs(sum - (2.00 * double(result.size()) * p * (1.00 - p)));
    double down = (2.00 * sqrt(2.00 * double(result.size())) * p * (1.00 - p));
    double division = up / down;
    double out = erfc(division);
    return out;
}
