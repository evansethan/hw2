/*
⚫ As yet another way to calculate the Euclidean 
length of a vector, is also a four argument 
version of accumulate that can combine 
transform and accumulate in a single step. Use 
this to provide another solution to part 2 of 
this problem
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

double distance(const std::vector<double>&v) {
    double sum = std::accumulate(v.begin(), v.end(), 0.0, [](double acc, double i) {
        return acc + (i * i);
    });
    return std::sqrt(sum);
}


int main(){
    std::vector<double> v = {1.23, 4.56, 7.89, 10.11};
    std::cout << distance(v) << std::endl;
    return 0;
}