#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cctype>

using namespace std;

class Comparator {
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b)  {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int main() {
    ifstream fisier("phrase.txt");
    if (!fisier.is_open()) {
        cout << "Eroare la deschiderea fisierului!" << endl;
        return 1;
    }

    string text;
    getline(fisier, text);
    fisier.close();

    map<string, int> dictionar;
    string separatoare = " ,?!.";

    size_t start = text.find_first_not_of(separatoare);

    while (start != string::npos) {
        size_t end = text.find_first_of(separatoare, start);
        string cuvant = text.substr(start, end - start);

        for (char &c : cuvant) {
            c = tolower(c);
        }

        dictionar[cuvant]++;
        start = text.find_first_not_of(separatoare, end);
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, Comparator> coada;

    for (auto it = dictionar.begin(); it != dictionar.end(); ++it) {
        coada.push(*it);
    }

    while (!coada.empty()) {
        pair<string, int> element = coada.top();
        cout << element.first << " => " << element.second << endl;
        coada.pop();
    }

    return 0;
}
