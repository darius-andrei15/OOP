#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum TipContact {
    PRIETEN,
    CUNOSTINTA,
    COLEG
};

class Contact {
protected:
    string nume;

public:
    Contact(string n) {
        nume = n;
    }

    virtual ~Contact() {}

    string getNume() {
        return nume;
    }

    virtual TipContact getTip() = 0;
    virtual void afisare() = 0;
};

class Prieten : public Contact {
private:
    string dataNasterii;
    string telefon;
    string adresa;

public:
    Prieten(string n, string data, string tel, string adr) : Contact(n) {
        dataNasterii = data;
        telefon = tel;
        adresa = adr;
    }

    TipContact getTip() override {
        return PRIETEN;
    }

    void afisare() override {
        cout << " Nume: " << nume << ", Tel: " << telefon
             << ", Nascut la: " << dataNasterii << ", Adresa: " << adresa << endl;
    }
};

class Cunostinta : public Contact {
private:
    string telefon;

public:
    Cunostinta(string n, string tel) : Contact(n) {
        telefon = tel;
    }

    TipContact getTip() override {
        return CUNOSTINTA;
    }

    void afisare() override {
        cout << " Nume: " << nume << ", Tel: " << telefon << endl;
    }
};

class Coleg : public Contact {
private:
    string telefon;
    string companie;
    string adresa;

public:
    Coleg(string n, string tel, string comp, string adr) : Contact(n) {
        telefon = tel;
        companie = comp;
        adresa = adr;
    }

    TipContact getTip() override {
        return COLEG;
    }

    void afisare() override {
        cout << " Nume: " << nume << ", Tel: " << telefon
             << ", Companie: " << companie << ", Adresa: " << adresa << endl;
    }
};

class Agenda {
private:
    vector<Contact*> listaContacte;

public:
    ~Agenda() {
        for (int i = 0; i < listaContacte.size(); i++) {
            delete listaContacte[i];
        }
    }

    void adaugaContact(Contact* c) {
        listaContacte.push_back(c);
    }

    Contact* cautaDupaNume(string numeCautat) {
        for (int i = 0; i < listaContacte.size(); i++) {
            if (listaContacte[i]->getNume() == numeCautat) {
                return listaContacte[i];
            }
        }
        return NULL;
    }

    vector<Contact*> listaDoarPrieteni() {
        vector<Contact*> doarPrieteni;
        for (int i = 0; i < listaContacte.size(); i++) {
            if (listaContacte[i]->getTip() == PRIETEN) {
                doarPrieteni.push_back(listaContacte[i]);
            }
        }
        return doarPrieteni;
    }

    void stergeContact(string numeCautat) {
        for (int i = 0; i < listaContacte.size(); i++) {
            if (listaContacte[i]->getNume() == numeCautat) {
                delete listaContacte[i];
                listaContacte.erase(listaContacte.begin() + i);
                cout << "Contactul a fost sters " << endl;
                return;
            }
        }
        cout << "Nu am gasit contactul" << endl;
    }

    void afiseazaTot() {
        cout << "\nAGENDA" << endl;
        for (int i = 0; i < listaContacte.size(); i++) {
            listaContacte[i]->afisare();
        }
    }
};

int main() {
    Agenda agendaMea;

    agendaMea.adaugaContact(new Prieten("Dan Popa", "10/10/1990", "0722111222", "Str. Lunga"));
    agendaMea.adaugaContact(new Cunostinta("Maria Dan", "0733444555"));
    agendaMea.adaugaContact(new Coleg("Alex Vasile", "0744999888", "Google", "Str. Scurta"));

    agendaMea.afiseazaTot();

    cout << "Caut pe Maria Dan" << endl;
    Contact* gasit = agendaMea.cautaDupaNume("Maria Dan");
    if (gasit != NULL) {
        gasit->afisare();
    } else {
        cout << "Nu exista!" << endl;
    }

    cout << "\nAfisez doar prietenii:" << endl;
    vector<Contact*> lista = agendaMea.listaDoarPrieteni();
    for (int i = 0; i < lista.size(); i++) {
        lista[i]->afisare();
    }

    cout << "\nSterg pe Alex Vasile" << endl;
    agendaMea.stergeContact("Alex Vasile");

    agendaMea.afiseazaTot();

    return 0;
}
