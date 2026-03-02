//
// Created by Darius on 3/2/2026.
//

#ifndef TEMA2EXTRA_MOVIE_H
#define TEMA2EXTRA_MOVIE_H


class Movie
{
    char film[256];
    int an[100];
    int AnAparitie;
    double rating;
    int MinuteFilm;

public:
    void SetName(const char*NumeFilm);
    const char* GetName();
    bool SetAn (int AnFilm);
    int GetAn();
    bool SetRating(double nota);
    double GetRating();
    void SetDurata(int Durata);
    int GetDurata();
    int Scadere();
};
int ComparaNumeFilm(Movie& n1, Movie& n2);
int ComparaAnLansare(Movie& n1, Movie& n2);
int ComparareRating(Movie& n1, Movie& n2);
int ComparareDurata(Movie& n1, Movie& n2);
int ComparareAniTrecuti(Movie& n1, Movie& n2);

class MovieSeries {
    Movie* movies[16];
    int count;

public:
    void Init();
    bool Add(Movie* m);
    void Print();
    void Sortare();
};


#endif //TEMA2EXTRA_MOVIE_H
