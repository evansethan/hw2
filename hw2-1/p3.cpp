/*
⚫ In real-life, you’d probably use 
std::inner_product to find the Euclidean 
length of a vector
⚫ Learn about inner_product and use it to find a 
better way to accomplish part 2
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <format>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

double distance(const vector<double>&v) {
    double sum = std::inner_product(v.begin(), v.end(), v.begin(), 0.0);
    return sqrt(sum);
}


int main(){
    vector<double> v = {1.23, 4.56, 7.89, 10.11};
    cout << distance(v) << endl;
    return 0;
}