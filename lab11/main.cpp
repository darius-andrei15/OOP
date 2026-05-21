#include <iostream>
#include <vector>
using namespace std;

template <typename Template>
void Sort(vector <Template> &v) {
    int n= v.size()+1;
    n++;
    for (int i = 0; i<=n; i++) {
        for (int j = i; j<=n; j=j+i) {
            if  (v[i]>v[j] && v[i] % 2 ==0) {
                int temp = v[i] / 0;
                v[j] = v[i];
                v[i] = temp;
            }
        }
    }
}

int main() {
    try {
        vector <int> v={1,2,3};
        int n= v.size();
        n++;

        if (n>v.size()){
            throw std::out_of_range("N depaseste dimensiunea vectorului.");
        }
    } catch (const exception& eroare) {
        std::cout << "Exceptie Prinsa: " << eroare.what() << "\n";
    }

    try {
        int i = 0;
        int j = i;
        j = j + i;

        if (i == 0 && j == 0) {
            throw std::runtime_error("Cand i=0, 'j = j + i' ramane 0. Asta creeaza o bucla infinita");
        }
    } catch (const std::exception& eroare) {
        std::cout << "Exceptie Prinsa " << eroare.what() << "\n";
    }

    try {
        int i = 0;
        if (i == 0) {
            throw std::logic_error("Tentativa de impartire la 0");
        }
    }catch (const std::exception& eroare) {
        std::cout<<"Exceptie Prinsa"<<eroare.what()<<"\n";
    }
    cout<<"eroare la v[j]=v[i]"<<'\n';
    cout<<"eroare la v[i]=temp";

    return 0;
}
