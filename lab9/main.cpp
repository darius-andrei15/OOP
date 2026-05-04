#include <iostream>
using namespace std;
template <class KEY, class VALUE>
class MAP {
private:
    KEY cheie[100];
    VALUE valoare[100];
    int index;

public:
    class MyIterator {
        private:
        KEY* refkey;
        VALUE* refval;
        int current_index;

        public:
        struct ReturnData {
            KEY key;
            VALUE value;
            int index;
        };
        MyIterator(KEY*c, VALUE*v, int idx): refkey(c), refval(v), current_index(idx) {}

        bool operator!=(const MyIterator& it) {
            return current_index != it.current_index;
        }

        MyIterator& operator++() {
            current_index++;
            return *this;
        }

        ReturnData operator*() {
            return ReturnData{refkey[current_index], refval[current_index], current_index};
        }
    };
    MAP() {
        index = 0;
    }
    MyIterator begin() {
        return MyIterator(cheie, valoare, 0);
    }
    MyIterator end() {
        return MyIterator(cheie, valoare, index);
    }
    VALUE& operator[](const KEY& k) {
        for (int i = 0; i < index; i++) {
            if (cheie[i]==k) {
                return valoare[i];
            }
        }
        cheie[index] = k;
        index++;
        return valoare[index-1];
    }

    void Set(const KEY& k, const VALUE& v) {
        for (int i = 0; i < index; i++) {
            if (cheie[i]==k) {
                valoare[i] = v;
                return;
            }
        }
        if (index<100) {
            cheie[index] = k;
            valoare[index]=v;
            index++;
        }
    }
    bool Get(const KEY& k, VALUE& v) {
        for (int i = 0; i < index; i++) {
            if (cheie[i]==k) {
                v = cheie[i];
                return true;
            }
        }
        return false;
    }

    int count() {
        return index;
    }

    void Clear() {
        index = 0;
    }

    bool contains(const KEY& k) {
        for (int i = 0; i < index; i++) {
            if (cheie[i]==k) {
                for (int j = i; j < index-1; j++) {
                    cheie[j] = cheie[j+1];
                    valoare[j] = valoare[j+1];
                }
                index--;
                return true;
            }
        }
        return false;
    }

    bool Includes (const MAP<KEY, VALUE>& m ) {
        for (int i = 0; i <m.index; i++) {
            bool found = false;
            for (int j = 0; j < index; j++) {
                if (cheie[j]==m.cheie[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    MAP<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key:%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key:%d, Value=%s\n", index, key, value);
    }

    return 0;
}

