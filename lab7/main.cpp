#include <iostream>
#include <stdio.h>

template <typename T>
class Vector {
private:
    T* elements;
    int currentSize;
    int capacity;

    void resize() {
        capacity *= 2;
        T* new_elements = new T[capacity];

        for (int i = 0; i < currentSize; i++) {
            new_elements[i] = elements[i];
        }

        delete[] elements;
        elements = new_elements;
    }

public:
    Vector() {
        capacity = 2;
        currentSize = 0;
        elements = new T[capacity];
    }

    ~Vector() {
        delete[] elements;
    }

    void push(T value) {
        if (currentSize == capacity) {
            resize();
        }
        elements[currentSize] = value;
        currentSize++;
    }

    T pop() {
        if (currentSize > 0) {
            currentSize--;
            return elements[currentSize];
        }
        return T();
    }

    void remove(int index) {
        if (index >= 0 && index < currentSize) {
            for (int i = index; i < currentSize - 1; i++) {
                elements[i] = elements[i + 1];
            }
            currentSize--;
        }
    }

    void insert(int index, T value) {
        if (index >= 0 && index <= currentSize) {
            if (currentSize == capacity) {
                resize();
            }
            for (int i = currentSize; i > index; i--) {
                elements[i] = elements[i - 1];
            }
            elements[index] = value;
            currentSize++;
        }
    }

    void sort(int (*callback)(T, T) = nullptr) {
        for (int i = 0; i < currentSize - 1; i++) {
            for (int j = 0; j < currentSize - i - 1; j++) {
                bool shouldSwap = false;

                if (callback != nullptr) {
                    if (callback(elements[j], elements[j + 1]) > 0) {
                        shouldSwap = true;
                    }
                } else {
                    if (elements[j] > elements[j + 1]) {
                        shouldSwap = true;
                    }
                }

                if (shouldSwap) {
                    T temp = elements[j];
                    elements[j] = elements[j + 1];
                    elements[j + 1] = temp;
                }
            }
        }
    }

    int count() {
        return currentSize;
    }

    void print() {
        for (int i = 0; i < currentSize; i++) {
            std::cout << elements[i] << " ";
        }
        std::cout << "\n";
    }

    T get(int index) {
        if (index >= 0 && index < currentSize) {
            return elements[index];
        }
        return T();
    }

    void set(int index, T value) {
        if (index >= 0 && index < currentSize) {
            elements[index] = value;
        }
    }

    int firstIndexOf(T value, int (*callback)(T, T) = nullptr) {
        for (int i = 0; i < currentSize; i++) {
            if (callback != nullptr) {
                if (callback(elements[i], value) == 0) {
                    return i;
                }
            } else {
                if (elements[i] == value) {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main() {
    Vector<int> v;
    v.push(10);
    v.push(20);
    v.push(30);
    v.insert(1, 15);

    v.print();

    printf("%d\n", v.pop());

    v.remove(0);
    v.print();

    return 0;
}

    
