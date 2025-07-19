#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <ostream>
#include <iomanip>

using namespace std;

#include "matrix.h"

Matrix::Matrix() {};

Matrix::Matrix(string &filename) {
    ifstream fin(filename);
    if(!fin) {
        cerr << "Couldn't find file " << filename << endl;
        return;
    }
    string line;
    while(getline(fin, line)) {
        istringstream iss(line);
        double num;
        vector<double> row;
        while(iss >> num) {
            row.push_back(num);
        }
        if(!row.empty()) {
            data.push_back(row);
        }
    }
}

size_t Matrix::rows() const {
    return data.size();
}

size_t Matrix::cols() const {
    return data.empty() ? 0 : data[0].size();
}

double Matrix::get(int i, int j) const {
    return data[i-1][j-1];
}

void Matrix::fill(double val) {
    for(int i = 1; i <= rows(); ++i) {
        for(int j = 1; j <= cols(); ++j) {
            change(i, j, val);
        }
    }
}

void Matrix::change(int i, int j, double val) {
    data[i-1][j-1] = val;
}

void Matrix::negative() {
    for(int i = 1; i <= rows(); ++i) {
        for(int j = 1; j <= cols(); ++j) {
            change(j, i, get(i, j) * (-1) );
        }
    }
}

bool Matrix::isSquare() {
    return rows() == cols();
}

void Matrix::cutRow(int i) {
    data.erase(data.begin() + i - 1);
}

void Matrix::cutCol(int j) {
    for(int i = 0; i < rows(); ++i) {
        data[i].erase(data[i].begin() + j - 1);
    }
}

void Matrix::resize(int i, int j, double val) {
    data.clear();
    vector<double> row (j, val);
    for(int w = 0; w < i; ++w) {
        data.push_back(row);
    }
}

void Matrix::transpose() {
    Matrix neu;
    neu.resize(cols(), rows(), 0);
    for(int i = 1; i <= rows(); ++i) {
        for(int j = 1; j <= cols(); ++j) {
            neu.change(j, i, get(i, j));
        }
    }
    data = neu.data;
}

void Matrix::print() {
    for(const auto& row : data) {
        for(double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

double Matrix::max() const {
    double val = -numeric_limits<double>::infinity();
    for(int i = 1; i <= rows(); ++i) {
        for(int j = 1; j <= cols(); ++j) {
            if(val < get(i, j)) val = get(i, j);
        }
    }
    return val;
}

double Matrix::min() const {
    double val = numeric_limits<double>::infinity();
    for(int i = 1; i <= rows(); ++i) {
        for(int j = 1; j <= cols(); ++j) {
            if(val > get(i, j)) val = get(i, j);
        }
    }
    return val;
}

void Matrix::add(Matrix mat) {
    for(int i = 1; i <= rows(); ++i) {
        for(int j = 1; j <= cols(); ++j) {
            double sum = get(i, j) + mat.get(i, j);
            change(i, j, sum);
        }
    }
}

void Matrix::add(double val) {
    for(int i = 1; i <= rows(); ++i) {
        for(int j = 1; j <= cols(); ++j) {
            change(i, j, get(i, j) + val);
        }
    }
}

void Matrix::subtract(Matrix mat) {
    mat.negative();
    add(mat);
}

void Matrix::subtract(double val) {
    add(val * (-1));
}

void Matrix::multiply(Matrix mat) {
    if(cols() != mat.rows()) {
        cerr << "IT'S A MISTAKE" << endl;
        return;
    }
    Matrix result;
    result.resize(rows(), mat.cols(), 0);
    for(int i = 1; i <= rows(); ++i) {
        for(int j = 1; j <= mat.cols(); ++j) {
            double sum = 0;
            for(int k = 1; k <= cols(); ++k) {
                sum += get(i, k) * mat.get(k, j);
            }
            result.change(i, j, sum);
        }
    }
    data = result.data;
}

void Matrix::multiply(double val) {
    for(int i = 1; i <= rows(); ++i) {
        for(int j = 1; j <= cols(); ++j) {
            change(i, j, get(i, j) * val);
        }
    }
}


double Matrix::determinant() {
    if(!isSquare()) {
        cerr << "IT'S A MISTAKE" << endl;
        return -1;
    }
    if(rows() == 1) return get(1, 1);
    if(rows() == 2) return get(1, 1)*get(2, 2) - get(1, 2)*get(2, 1);
    double sum = 0;
    for(int i = 1; i <= rows(); ++i) {
        Matrix cut;
        cut.data = data;
        cut.cutCol(i);
        cut.cutRow(1);
        int sign = (i % 2 == 1) ? 1 : -1;
        sum += get(1, i) * cut.determinant() * sign;
    }
    return sum;
}

double Matrix::minor(int i, int j) {
    if(!isSquare()) {
        cerr << "IT'S A MISTAKE" << endl;
        return -1;
    }
    Matrix neu;
    neu.data = data;
    neu.cutRow(i);
    neu.cutCol(i);
    int sign = (i + j) % 2 == 0 ? 1 : -1;
    return sign * neu.determinant();
}

Matrix Matrix::operator+(const Matrix& mat) const {
    Matrix result;
    result.data = data;
    result.add(mat);
    return result;
}

Matrix Matrix::operator+(double val) const {
    Matrix result;
    result.data = data;
    result.add(val);
    return result;
}

Matrix Matrix::operator-(const Matrix& mat) const {
    Matrix result;
    result.data = data;
    result.subtract(mat);
    return result;
}

Matrix Matrix::operator-(double val) const {
    Matrix result;
    result.data = data;
    result.subtract(val);
    return result;
}

Matrix Matrix::operator*(const Matrix& mat) const {
    Matrix result;
    result.data = data;
    result.multiply(mat);
    return result;
}

Matrix Matrix::operator*(double val) const {
    Matrix result;
    result.data = data;
    result.multiply(val);
    return result;
}

double& Matrix::operator()(int i, int j) {
    return data[i-1][j-1];
}

double Matrix::operator()(int i, int j) const {
    return data[i-1][j-1];
}

bool Matrix::operator==(const Matrix& other) const {
    if(rows() != other.rows() || cols() != other.cols()) return false;
    for(int i = 1; i <= rows(); ++i) {
        for(int j = 1; j <= cols(); ++j) {
            if(get(i, j) != other.get(i, j)) return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& os, const Matrix& mat) {
    for (int i = 1; i <= mat.rows(); ++i) {
        for (int j = 1; j <= mat.cols(); ++j)
            os << std::setw(8) << mat.get(i, j);
        os << std::endl;
    }
    return os;
}

void Matrix::saveToFile(const string& filename) const {
    ofstream out(filename);
    for(int i = 1; i <= rows(); ++i) {
        for(int j = 1; j <= cols(); ++j) {
            if(j == cols()) out << get(i, j) << "\n";
            else out << get(i,j) << " ";
        }
    }
    out.close();
}

void Matrix::loadFromFile(const string& filename) {
    ifstream fin(filename);
    if(!fin) {
        cerr << "Couldn't find file " << filename << endl;
        return;
    }
    data.clear();
    string line;
    while(getline(fin, line)) {
        istringstream iss(line);
        double num;
        vector<double> row;
        while(iss >> num) {
            row.push_back(num);
        }
        if(!row.empty()) {
            data.push_back(row);
        }
    }
}