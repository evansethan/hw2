/*
⚫ Rewrite the pascal.cpp file in Canvas (or your own) to be class-oriented
⚫ Did that make it better and why?
*/

#include <iostream>
#include <string>
#include <vector>
#include <format>
using namespace std;


class Triangle {
private:
    vector<vector<int>> tri;
    int brickSize = 4;
    int rows;
public:
    Triangle(int numRows) {
        this->rows = numRows;

        for (int i = 0; i < this->rows; i++) {
            vector<int> row;

            for (int j = 0; j < i + 1; j++) {

                if (j == 0 || j == i ) {row.push_back(1); continue;};
        
                int num = this->tri[i-1][j] + this->tri[i-1][j-1];
                row.push_back(num);
            }
            this->tri.push_back(row);
        }
    }
    void printTriangle() {
        for(int i = 0; i < this->rows; i++) {
            string row;
            for(int j = 0; j <= i; j++) {
                row += format("{:^{}}", this->tri[i][j], this->brickSize);    
            }
            cout << format("{:^{}}", row, this->rows * this->brickSize) << endl;
        }
    }
};


int main() {

    int rows;
    cout << "How many rows? ";
    cin >> rows;

    Triangle triangle(rows);
    triangle.printTriangle();

    return 0;
}
