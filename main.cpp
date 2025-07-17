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
    Matrix mat = matE - matZ;
    cout << "--------------------" << endl;
    matE.print();
    cout << "--------------------" << endl;
    matZ.print();
    cout << "--------------------" << endl;
    mat.print();
    cout << "--------------------" << endl;
    (matE - 5).print();
    cout << "--------------------" << endl;
    return 0;
}
