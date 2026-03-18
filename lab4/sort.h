//
// Created by Darius on 3/11/2026.
//

#ifndef LAB4_SORT_H
#define LAB4_SORT_H
using namespace std;

class Sort
{
    int n;
    int* v;
private:
    void QuickSortHelper(int low, int high, bool ascendent);
    int Partition(int low, int high, bool ascendent);

public:

    Sort(int n, int a[]);
    Sort(int count, int min, int max);
    Sort(initializer_list<int> list);
    Sort(char c[]);
    Sort(int const,...);

    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};


#endif //LAB4_SORT_H
