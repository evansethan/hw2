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
#include <string>
#include <vector>
#include <format>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

double distance(const vector<double>&v) {
    double sum = accumulate(v.begin(), v.end(), 0.0, [](double acc, double i) {
        return acc + (i * i);
    });
    return sqrt(sum);
}


int main(){
    vector<double> v = {1.23, 4.56, 7.89, 10.11};
    cout << distance(v) << endl;
    return 0;
}