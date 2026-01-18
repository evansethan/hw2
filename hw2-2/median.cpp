/*
⚫ One of the above slides referred to a function median, that takes the median
of a vector of doubles.
⚫ Part 1. Write the median function using the sort function in the algorithm
header.
⚫ Part 2. Write the median function using the partial_sort function in the
algorithm header. Is this more efficient? Why do you think that? (You can give
an intuitive or practical answer without precise mathematical analysis)
⚫ Part 3. Write the median function using the nth_element function header.
Do you think this is even more efficient? Why?
⚫ Part 4 - Extra credit: Write a template function that can find the median
of a vector of any appropriate type.
⚫ Although we haven’t discussed writing our own template functions yet,
looking at the template function for squaring from last week’s slides
⚫ You can use any of the underlying algorithms from parts 1 to 3 above
⚫ More extra credit. If there are an even number of elements, use the
average of the middle 2 element
*/

#include <algorithm>
#include <vector>
#include <iostream>



double median1(std::vector<double> v) {

    std::sort(v.begin(), v.end());
    return v[(v.size()/2)];
}

double median2(std::vector<double> v) {

    int mid = v.size()/2;
    std::partial_sort(v.begin(), v.begin() + mid + 1, v.end());
    return v[mid];
}

double median3(std::vector<double> v) {

    int mid = v.size()/2;
    std::nth_element(v.begin(), v.begin() + mid, v.end());
    return v[mid];
}

auto median4(std::vector<auto> v) {
    int mid = v.size()/2;
    std::nth_element(v.begin(), v.begin() + mid, v.end());
    return v[mid];
}

// Unused, same as median4()
template<typename T>
T median4Extra(std::vector<T> v) {
    int mid = v.size()/2;
    std::nth_element(v.begin(), v.begin() + mid, v.end());
    return v[mid];
}

double median5(std::vector<auto> v) {
    int n = v.size();
    int mid = n/2;

    if (n % 2 != 0) {
        std::nth_element(v.begin(), v.begin() + mid, v.end());
        return v[mid];
    } else {
        std::nth_element(v.begin(), v.begin() + mid - 1, v.end());
        std::nth_element(v.begin(), v.begin() + mid, v.end());
        return double(v[mid] + v[mid - 1]) / 2;
    }
}

int main(){
    std::vector<double> v1 = {1.23, 7.89, 10.11, 4.56, 2.53, 8.88, 10.44};
    std::vector<double> v2 = {1.23, 7.89, 10.11, 4.56, 2.53, 8.88, 10.44};
    std::vector<double> v3 = {1.23, 7.89, 10.11, 4.56, 2.53, 8.88, 10.44};
    std::vector<int> ints = {1, 7, 10, 4, 2, 8, 10};
    std::vector<int> even1 = {1, 7, 10, 4, 2, 8, 10, 6};
    std::vector<double> even2 = {1.23, 7.89, 10.11, 4.56, 2.53, 8.88, 10.44, 8.45};
    std::cout << median1(v1) << std::endl; // 7.89
    std::cout << median2(v2) << std::endl; // 7.89
    std::cout << median3(v3) << std::endl; // 7.89
    std::cout << median4(ints) << std::endl; // 7
    std::cout << median5(even1) << std::endl; // 6.5
    std::cout << median5(even2) << std::endl; // 8.17
    return 0;
}