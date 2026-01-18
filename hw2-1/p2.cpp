/*
⚫ We will extend the program in part 1 to calculate and print the distance of
a vector from the origin.
⚫ There is also a function in the <numeric> header called accumulate that can
be used to add up all the items in a collection. 
⚫ (Googling for “accumulate numeric example” gives some good examples of using
accumulate. We’re interested in the 3 argument version of accumulate).
⚫ After squaring each element of the vector as in part 1, use accumulate to
add up the squares and then take the square root. (That this is the distance
from the origin is the famous Pythagorean theorem, which works in any number
of dimensions).
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>


std::vector<double> squareTransform(const std::vector<double>&v1) {

    std::vector<double> v2(v1.size());

    std::transform(v1.begin(), v1.end(), v2.begin(),
              [](double a) {return a * a;});

    return v2;
}


double distance(const std::vector<double>&v1) {

    std::vector<double> v2 = squareTransform(v1);
    double sum = std::accumulate(v2.begin(), v2.end(), 0.0);
    return std::sqrt(sum);
}


int main(){

    std::vector<double> v1 = {1.23, 4.56, 7.89, 10.11};

    std::cout << distance(v1) << std::endl;

    return 0;

}