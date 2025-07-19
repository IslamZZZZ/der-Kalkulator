#include <vector>
#include <string>
#include <ostream>

#pragma once
using namespace std;
class Matrix{
    private:
        vector<vector<double>> data;

    public:
        Matrix();
        Matrix(string &filename);
        size_t rows() const;
        size_t cols() const;
        double get(int, int) const;
        void fill(double);
        void change(int, int, double);
        void negative();
        bool isSquare();
        void cutRow(int);
        void cutCol(int);
        void resize(int, int, double);
        void transpose();
        void print();
        double max() const;
        double min() const;
        void add(Matrix);
        void add(double);
        void subtract(Matrix);
        void subtract(double);
        void multiply(Matrix);
        void multiply(double);
        double determinant();
        double minor(int, int);
        Matrix operator+(const Matrix&) const;
        Matrix operator+(double) const;
        Matrix operator-(const Matrix&) const;
        Matrix operator-(double) const;
        Matrix operator*(const Matrix&) const;
        Matrix operator*(double) const;
        double& operator()(int, int);
        double operator()(int, int) const;
        bool operator==(const Matrix&) const;
        friend ostream& operator<<(ostream&, const Matrix&);
        void saveToFile(const string&) const;
        void loadFromFile(const string&);
};