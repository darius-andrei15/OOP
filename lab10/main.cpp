#include <iostream>
#include <exception>
using namespace std;

class InAfaraIndexului : public exception {
    virtual const char* what() const noexcept override {
        return "InAfaraIndexului";
    }
};

class NullPointerException : public exception {
    virtual const char* what() const noexcept override {
        return "NullPointerException";
    }
};

class Compare {
    public:
    virtual int CompareElements(void *e1, void *e2)=0;
};

template<class T>
class ArrayIterator {
private:
    int Current;
    T** List;
public:
    ArrayIterator() : Current(0), List(nullptr){}

    ArrayIterator(int startPos, T** listptr) : Current(startPos), List(listptr) {}

    ArrayIterator& operator++() {
        return Current++;
        return *this;
    }

    ArrayIterator& operator--() {
        return Current--;
        return *this;
    }

    bool operator=(const ArrayIterator<T>& other) {
        Current = other.Current;
        List = other.List;
        return *this;
    }

    bool operator!=(const ArrayIterator<T>& other) {
        return Current != other.Current;
    }

    T* GetElement() {
        if (!List) {
            throw NullPointerException();
        }
        return List[Current];
    }
};

template<class T>
class Array {
private:
    int Capacity;
    T** List;
    int Size;

    void Resize() {
        Capacity = (Capacity == 0)? 10: Capacity*2;
        T** newList = new T*[Capacity];
        for (int i = 0; i < Size; i++) {
            newList[i] = List[i];
        }
        delete[] List;
        List = newList;
    }

public:
    Array() : Capacity(0), List(nullptr), Size(0) {}

    ~Array() {
        for (int i = 0; i < Size; i++) {
            delete List[i];
        }
        delete[] List;
    }

    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T*[Capacity];
    }

    Array (const Array<T>& otherArray): Capacity(otherArray.Capacity), Size(otherArray.Size) {
        List = new T*[Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T*(otherArray.List[i]);
        }
    }

    T& operator[](int index) {
        if (index < 0 || index >= Size) {
            throw InAfaraIndexului();
        }
        return *List[index];
    }

    const Array<T>& operator+=(const T &newElement) {
        if (Size>=Capacity) {
            Resize();
        }
        List[Size++] = new T(newElement);
        return *this;
    }

    const Array<T>& Insert(int index, const T &newElem) {
        if (index < 0 || index >= Size) {
            throw InAfaraIndexului();
        }
        if (Size>=Capacity) {
            Resize();
        }
        for (int i = Size; i > index; i--) {
            List[i] = List[i-1];
        }
        List[index] =new T(newElem);
        return *this;
        Size++;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index >= Size) {
            throw InAfaraIndexului();
        }
        while (Size+otherArray.Size>=Capacity) {
            Resize();
        }
        for (int i = Size-1; i > index; i--) {
            List[i+otherArray.Size] = List[i];
        }
        for (int i = otherArray.Size; i > index; i--) {
            List[index+i]=new T*(otherArray.List[i]);
        }
        return *this;
        Size+=otherArray.Size;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size) {
            throw InAfaraIndexului();
        }
        delete List[index];
        for (int i = index ; i < Size-1; i++) {
            List[i] = List[i+1];
        }
        Size--;
        return *this;
    }

    bool operator=(const Array<T> &otherArray) {
        if (this == &otherArray) {
            return false;
        }
        for (int i = 0; i < Size; i++) {
            delete List[i];
        }
        delete[] List;
        Capacity = otherArray.Capacity;
        Size= otherArray.Size;
        List = new T*[Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(otherArray.List[i]);
        }
        return true;
    }

    void Sort() {
        for (int i = 0; i < Size-1; i++) {
            for (int j = i; j < Size; j++) {
                if ( *List[i]< *List[j]) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size-1; i++) {
            for (int j = i+1; j < Size; j++) {
                if (compare(*List[i],*List[j])>0) {
                    T temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    void Sort(Compare *comparator) {
        for (int i = 0; i < Size-1; i++) {
            for (int j = i+1; j < Size; j++) {
                if (comparator->CompareElements(List[i],List[j])>0) {
                    T temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    int BinarySearch(const T& elem) {
        int left = 0;
        int right = Size-1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (elem == *List[mid]) {
                return mid;
            }
            if (elem < *List[mid]) {
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int left = 0;
        int right = Size-1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (compare(*List[mid],elem)==0) {
                return mid;
            }
            if (compare(*List[mid],elem)<0) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare *comparator) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int cmp = comparator->CompareElements(List[mid], (void*)&elem);
            if (cmp == 0) return mid;
            if (cmp < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem) {
        for (int i = 0; i < Size; i++) {
            if (*List[i] == elem) {
                return i;
            }
        }
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; i++) {
            if (compare(*List[i],elem) == 0) {
                return i;
            }
        }
        return -1;
    }

    int Find(const T& elem, Compare *comparator) {
        for (int i = 0; i < Size; i++) {
            if (comparator->CompareElements(List[i], (void*)&elem) == 0) return i;
        }
        return -1;
    }

    int GetSize() {
        return Size;
    }

    int GetCapacity() {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(0,List);
    }

    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(Size,List);
    }
};
int main() {
    try {
        Array<int> arr;

        arr += 10;
        arr += 20;
        arr += 30;

        cout << "Elementul de la indexul 1 este: " << arr[1] << endl;

        arr.Insert(1, 15);
        cout << "Dupa insert, elementul de la indexul 1 este: " << arr[1] << endl;

        arr.Delete(1);
        cout << "Dupa stergere, elementul de la indexul 1 revine la: " << arr[1] << endl;

        // Fortam o exceptie
        cout << "Incercam sa accesam indexul 100..." << endl;
        cout << arr[100] << endl;

    } catch (exception& e) {
        cout << "Exceptie prinsa: " << e.what() << endl;
    }

    return 0;
}

