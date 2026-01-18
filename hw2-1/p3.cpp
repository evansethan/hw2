/*
⚫ In real-life, you’d probably use 
std::inner_product to find the Euclidean 
length of a vector
⚫ Learn about inner_product and use it to find a 
better way to accomplish part 2
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

double distance(const std::vector<double>&v) {
    double sum = std::inner_product(v.begin(), v.end(), v.begin(), 0.0);
    return std::sqrt(sum);
}


int main(){
    std::vector<double> v = {1.23, 4.56, 7.89, 10.11};
    std::cout << distance(v) << std::endl;
    return 0;
}