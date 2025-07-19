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
    Matrix mat = matE * matZ;
    matE(2,3) = 11;
    cout << "--------------------" << endl;
    matE.print();
    cout << "--------------------" << endl;
    matZ.print();
    cout << "--------------------" << endl;
    mat.print();
    cout << "--------------------" << endl;
    (matE - 5).print();
    cout << "--------------------" << endl;
    cout << matE(2,3) << endl;
    cout << mat << endl;
    mat.transpose();
    mat.saveToFile("../matrices/Erst.txt");
    matE.loadFromFile("../matrices/Erst.txt");
    cout << matE << endl;
    
    return 0;
}
