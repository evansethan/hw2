/*
⚫ Rewrite the pascal.cpp file in Canvas (or your own) to be class-oriented
⚫ Did that make it better and why?
*/

#include <iostream>
#include <string>
#include <vector>
#include <format>


class Triangle {
private:
    std::vector<std::vector<int>> tri;
    int const brickSize = 4;
    int const maxRows = 13;
    int rows;
public:
    Triangle(int numRows) {
        if (numRows > this->maxRows) {
            this->rows = this->maxRows;
        } else {
            this->rows = numRows;
        }

        for (int i = 0; i < this->rows; i++) {
            std::vector<int> row;

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
            std::string row;
            for(int j = 0; j <= i; j++) {
                row += std::format("{:^{}}", this->tri[i][j], this->brickSize);    
            }
            std::cout << std::format("{:^{}}", row, this->rows * this->brickSize) << std::endl;
        }
    }
};


int main() {

    int rows;
    std::cout << "How many rows? ";
    std::cin >> rows;

    Triangle triangle(rows);
    triangle.printTriangle();

    return 0;
}