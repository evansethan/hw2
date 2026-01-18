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
using namespace std;


double median1(vector<double> v) {

    sort(v.begin(), v.end());
    return v[(v.size()/2)];
}

double median2(vector<double> v) {

    int mid = v.size()/2;
    partial_sort(v.begin(), v.begin() + mid + 1, v.end());
    return v[mid];
}

double median3(vector<double> v) {

    int mid = v.size()/2;
    nth_element(v.begin(), v.begin() + mid, v.end());
    return v[mid];
}

auto median4(vector<auto> v) {
    int mid = v.size()/2;
    nth_element(v.begin(), v.begin() + mid, v.end());
    return v[mid];
}

// Unused, same as median4()
template<typename T>
T median4Extra(vector<T> v) {
    int mid = v.size()/2;
    nth_element(v.begin(), v.begin() + mid, v.end());
    return v[mid];
}

double median5(vector<auto> v) {
    int n = v.size();
    int mid = n/2;

    if (n % 2 != 0) {
        nth_element(v.begin(), v.begin() + mid, v.end());
        return v[mid];
    } else {
        nth_element(v.begin(), v.begin() + mid - 1, v.end());
        nth_element(v.begin(), v.begin() + mid, v.end());
        return double(v[mid] + v[mid - 1]) / 2;
    }
}

int main(){
    vector<double> v1 = {1.23, 7.89, 10.11, 4.56, 2.53, 8.88, 10.44};
    vector<double> v2 = {1.23, 7.89, 10.11, 4.56, 2.53, 8.88, 10.44};
    vector<double> v3 = {1.23, 7.89, 10.11, 4.56, 2.53, 8.88, 10.44};
    vector<int> ints = {1, 7, 10, 4, 2, 8, 10};
    vector<int> even1 = {1, 7, 10, 4, 2, 8, 10, 6};
    vector<double> even2 = {1.23, 7.89, 10.11, 4.56, 2.53, 8.88, 10.44, 8.45};
    cout << median1(v1) << endl; // 7.89
    cout << median2(v2) << endl; // 7.89
    cout << median3(v3) << endl; // 7.89
    cout << median4(ints) << endl; // 7
    cout << median5(even1) << endl; // 6.5
    cout << median5(even2) << endl; // 8.17
    return 0;
}