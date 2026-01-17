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
#include <string>
#include <vector>
#include <format>
#include <iterator>     // std::ostream_iterator
#include <numeric>
#include <cmath>
using namespace std;


vector<double> squareTransform(const vector<double>&v1) {

    vector<double> v2(v1.size());

    transform(v1.begin(), v1.end(), v2.begin(),
              [](double a) {return a * a;});

    return v2;
}


double pythagoras(const vector<double>&v1) {

    vector<double> v2 = squareTransform(v1);

    double sum = std::accumulate(
        v2.begin(),   // Arg 1: Iterator to the beginning of the range
        v2.end(),     // Arg 2: Iterator to the end of the range
        0                  // Arg 3: Initial value and type for the accumulation
    );

    return sqrt(sum);
}


int main(){

    vector<double> v1 = {1.23, 4.56, 7.89, 10.11};

    cout << pythagoras(v1) << endl;

    return 0;

}