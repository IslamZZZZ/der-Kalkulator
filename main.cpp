#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "math.h"
#include "matrix.h"

int main(int argc, char *argv[]) {
    string fnE = "../matrices/Erst.txt";
    string fnZ = "../matrices/Zweiste.txt";
    Matrix matE(fnE);
    Matrix matZ(fnZ);
    cout << add(dif(7,3), mult(4,5)) << endl;
    matE.print();
    cout << matE.isSquare() << endl;
    matZ.print();
    cout << matZ.isSquare() << endl;
    matE.multiply(matZ);
    matE.print();
    cout << matE.isSquare() << endl;
    cout << matZ.determinant() << endl;
    return 0;
}
