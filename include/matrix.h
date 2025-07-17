#include <vector>
#include <string>

#pragma once
using namespace std;
class Matrix{
    private:
        vector<vector<double>> data;

    public:
        Matrix();
        Matrix(string &filename);
        size_t rows();
        size_t cols();
        double get(int, int);
        void change(int, int, double);
        void print();
        void add(Matrix);
        void add(double);
        void subtract(Matrix);
        void multiply(Matrix);
        void multiply(double);
        void resize(int, int, double);
        void transpose();
        double determinant();
        bool isSquare();
        void cutRow(int);
        void cutCol(int);
        double minor(int, int);
        Matrix operator+(const Matrix&) const;
        Matrix operator+(double) const;
        Matrix operator-(const Matrix&) const;
        Matrix operator-(double) const;
        void negative();
};