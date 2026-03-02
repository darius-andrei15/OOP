#include<iostream>
#include<string.h>
#include "Movie.h"

void Movie::SetName(const char *NumeFilm)
{
    strncpy(this->film , NumeFilm, sizeof(this->film));
    this->film[sizeof(this->film) - 1] = '\0';
}
const char* Movie::GetName()
{
    return this->film;
}

bool Movie::SetAn(int AnFilm)
{
    if (AnFilm>1000 && AnFilm<2026) {
        this->AnAparitie=AnFilm;
        return true;
    }
    return false;
}

int Movie::GetAn()
{
    return this->AnAparitie;
}

bool Movie::SetRating(double nota) {
    if (nota>=1 && nota<=10) {
        this->rating=nota;
        return true;
    }
    return false;
}
double Movie::GetRating() {
    return this->rating;
}

void Movie::SetDurata(int Durata) {
    this->MinuteFilm=Durata;
}

int Movie::GetDurata() {
    return MinuteFilm;
}

int Movie::Scadere() {
    return 2026-AnAparitie;
}

int ComparaNumeFilm(Movie &n1, Movie &n2) {
    int rezultat=strcmp(n1.GetName(), n2.GetName());
    if (rezultat==0)return 0;
    if (rezultat==1)return 1;
    return -1;
}

int ComparaAnLansare(Movie &n1, Movie &n2) {
    if (n1.GetAn()<n2.GetAn())return -1;
    if (n1.GetAn()>n2.GetAn())return 1;
    return 0;
}

int ComparareAniTrecuti(Movie &n1, Movie &n2) {
    if (n1.Scadere()<n2.Scadere())return -1;
    if (n1.Scadere()>n2.Scadere())return 1;
    return 0;
}
int ComparareRating(Movie &n1, Movie &n2) {
    if (n1.GetRating()<n2.GetRating())return -1;
    if (n1.GetRating()>n2.GetRating())return 1;
    return 0;
}

int ComparareDurata(Movie &n1, Movie &n2) {
    if (n1.GetDurata()<n2.GetDurata())return -1;
    if (n1.GetDurata()>n2.GetDurata())return 1;
    return 0;
}

void MovieSeries::Init(){
    this->count=0;
}

bool MovieSeries::Add(Movie *m) {
    if (this->count>=16)
        return false;
    this->movies[this->count]=m;
    this->count++;
    return true;
}

void MovieSeries::Print() {
    if (this->count==0)
        std::cout<<"Seria nu contine niciun film!"<<std::endl;

    for (int i=0;i<this->count;i++) {
        std::cout << "Nume: " << this->movies[i]->GetName()<< " | An: " << this->movies[i]->GetAn()<< " | IMDB: " << this->movies[i]->GetRating()<< " | Durata: " << this->movies[i]->GetDurata() << " min"<< " | Ani trecuti: " << this->movies[i]->Scadere()<< std::endl;
    }
}

void MovieSeries::Sortare() {
    for (int i = 0; i < this->count - 1; i++) {
        for (int j = i + 1; j < this->count; j++) {
            if (ComparareAniTrecuti(*(this->movies[i]), *(this->movies[j])) == -1) {
                Movie* temp = this->movies[i];
                this->movies[i] = this->movies[j];
                this->movies[j] = temp;
            }
        }
    }
}
