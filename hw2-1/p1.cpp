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
#include <vector>


std::vector<double> squareTransform(const std::vector<double>&v1) {

    std::vector<double> v2(v1.size());

    std::transform(v1.begin(), v1.end(), v2.begin(),
              [](double a) {return a * a;});

    return v2;
}


int main(){

    std::vector<double> v1 = {1.01, 2.01, 3.01, 4.01};

    std::vector<double> v2 = squareTransform(v1);

    for (double element : v2) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    return 0;
}