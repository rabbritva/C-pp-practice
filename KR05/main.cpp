#include <iostream>
#include <random>
#include "Set.h"
#include "Figure.h"
using namespace std;



int main() {
    setlocale(LC_ALL, "");

    int arr[] = { 1,1,10,15,1,12,123,234 };
    set<int> Q(arr, 8);
    Q.print();
    set<int> X, Y, Z;
    srand(255);
    for (short i = 0; i < 8; i++) { X.add(rand() % 11); Y.add(rand() % 11); }
    X.print();
    Y.print();
    Z = X + Y;
    Z.print();
    cout << "Z size: " << Z.size() << endl;
    cout << Z[3] << endl;

    Triangle t1("EgipTriangle", 6, 8, 10);
    t1.info();
    Parallelogramm p1("P1", 4, 3, 30, 1.5);
    p1.info();
    printf("Total area: %f", Figure::getTotalArea());

    system("pause>null");
    return 0;
}