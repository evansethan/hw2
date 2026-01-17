/*
- Last week we mentioned std::copy. There is a related function in the
<algorithm> header called std::transform, which lets you apply a function
to each element before copying. Look up or Google for std::transform to
understand the precise usage.
- Write a program that puts several doubles in a vector and then uses
std::transform to produce a new vector with each element equal to the square
of the corresponding element in the original vector and print the new vector
(If you use ostream_iterator to print the new vector, you will likely get an
extra comma at the end of the output. Don’t worry if that happens).
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <format>
#include <iterator>
using namespace std;


vector<double> squareTransform(const vector<double>&v1) {

    vector<double> v2(v1.size());

    transform(v1.begin(), v1.end(), v2.begin(),
              [](double a) {return a * a;});

    return v2;
}


int main(){

    vector<double> v1 = {1.23, 4.56, 7.89, 10.11};

    vector<double> v2 = squareTransform(v1);


    // for (double element : v2) {
    //     cout << element << " ";
    // }
    // cout << endl;
    std::ostream_iterator<double> out_it (std::cout,", ");
    std::copy ( v2.begin(), v2.end(), out_it );
    std::cout << std::endl;
    return 0;

}