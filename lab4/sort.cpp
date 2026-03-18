#include<iostream>
#include "Sort.h"
#include<cstdlib>
#include<cstring>
#include<utility>
#include <filesystem>
#include <random>
#include <ranges>
#include <vector>
#include <bits/std_thread.h>
#include <cstdarg>

using namespace std;

Sort::Sort(int n, int a[]) {
    this->n = n;
    this->v = new int[n];
    for (int i = 0; i < n; i++)
        this->v[i] = a[i];
}

Sort::Sort(int n, int min, int max) {
    if (min > max) std::swap(min, max);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);
    this->n=n;
    this->v=new int[n];
    for (int i = 0; i < n; ++i) {
        this->v[i] = distrib(gen);
    }
}

Sort::Sort(initializer_list<int> list) {
    this->n = list.size();
    this->v = new int[this->n];
    int i = 0;
    for (int element:list) {
        this->v[i] = element;
        i++;
    }
}

Sort::Sort(int const n, ...) {
    va_list ap;
    va_start(ap,n);
    this->n = n;
    this->v = new int[n];
    for (int i = 0; i < n; i++) {
        this->v[i] = va_arg(ap, int);
    }
    va_end(ap);
}

Sort::Sort(char c[]) {
    int size = 0;
    for (int i = 0;i<strlen(c);i++)
        if (c[i]==',')
            size++;
    this->n = size+1;
    this->v = new int[this->n];
    int number = 0;
    int k = 0;
    for (int i = 0;i<=strlen(c);i++) {
        if (isdigit(c[i])) {
            number = number * 10 + (c[i]- '0');
        }else if (c[i] == ','|| c[i] == NULL) {
            this->v[k] = number;
            k++;
            number = 0;
        }
    }
}

void Sort::BubbleSort(bool ascendent) {
    if (ascendent) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (this->v[j] > this->v[j+1]) {
                    std::swap(this->v[j], this->v[j+1]);
                }
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (this->v[j] < this->v[j+1]) {
                    std::swap(this->v[j], this->v[j+1]);
                }
            }
        }
    }

}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;
        if (ascendent) {
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                j--;
            }
        } else {
            while (j >= 0 && v[j] < key) {
                v[j + 1] = v[j];
                j--;
            }
        }
        v[j + 1] = key;
    }
}

void Sort::Print() {
    for (int i = 0; i < n; i++) {
        cout << this->v[i] <<endl;
    }
}

int Sort::GetElementFromIndex(int index) {
    return this->v[index];
}

int Sort::GetElementsCount() {
    return this->n;
}

int Sort::Partition(int low, int high, bool ascendent) {
    int pivot = v[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        bool condition = ascendent ? (v[j] < pivot) : (v[j] > pivot);
        if (condition) {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[high]);
    return (i + 1);
}

void Sort::QuickSortHelper(int low, int high, bool ascendent) {
    if (low < high) {
        int pi = Partition(low, high, ascendent);
        QuickSortHelper(low, pi - 1, ascendent);
        QuickSortHelper(pi + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent) {
    QuickSortHelper(0, this->n - 1, ascendent);
}
