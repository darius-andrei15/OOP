#include <iostream>
#include "Sort.h"
using namespace std;
int main() {
    cout << "1. Constructor: Valori Aleatoare (si InsertSort) \n";
    Sort s1(7, 10, 50);
    s1.InsertSort(false);
    s1.Print();

    cout<<" Constructor cu initializator \n ";
    Sort s2({ 50, 20, 10, 40, 30 });
    s2.BubbleSort();
    s2.Print();

    cout<<"Sortare vector deja stiut: \n ";
    int arr[] = { 9, 7, 5, 3, 1, 8, 6, 4, 2 };
    Sort s3(9,arr);
    s3.QuickSort();
    s3.Print();

    std::cout << "4. Constructor cu parametri variadici (QuickSort descrescator):\n";
    Sort s4(6, 111, 333, 222, 555, 444, 666);
    s4.QuickSort(false);
    s4.Print();

    std::cout << "5. Constructor din string (BubbleSort crescator):\n";
    Sort s5("10,40,100,5,70");
    s5.BubbleSort();
    s5.Print();
}
