#include <iostream>
#include "Movie.h"

int main() {
    Movie movie;
    movie.SetName("Transformers");
    std::cout <<"Numele filmului: "<< movie.GetName()<<std::endl;
    movie.SetAn(2012);
    std::cout <<"An aparitie: "<< movie.GetAn()<<std::endl;
    movie.SetRating(7.85);
    std::cout <<"Rating: "<< movie.GetRating()<<std::endl;
    movie.SetDurata(168);
    std::cout <<"Durata film: "<< movie.GetDurata()<<" minute"<<std::endl;
    std::cout<<"Au trecut "<<movie.Scadere()<<" ani de cand s-a lansat"<<std::endl;

    Movie movie2;
    movie2.SetName("Transformers 2");
    std::cout <<"Numele filmului: "<< movie2.GetName()<<std::endl;
    movie2.SetAn(2018);
    std::cout <<"An aparitie: "<< movie2.GetAn()<<std::endl;
    movie2.SetRating(7.85);
    std::cout <<"Rating: "<< movie2.GetRating()<<std::endl;
    movie2.SetDurata(168);
    std::cout <<"Durata film: "<< movie2.GetDurata()<<" minute"<<std::endl;
    std::cout<<"Au trecut "<<movie2.Scadere()<<" ani de cand s-a lansat"<<std::endl;

    int rezultatNume=ComparaNumeFilm(movie, movie2);
    if (rezultatNume==-1)
        std::cout<<"Transformers < Transformers 2"<<std::endl;
    if (rezultatNume==1)
        std::cout<<"Transformers > Transformers 2"<<std::endl;
    if (rezultatNume==0)
        std::cout<<"Transformers = Transformers 2"<<std::endl;

    int rezultatAn=ComparaAnLansare(movie, movie2);
    if (rezultatAn==-1)
        std::cout<<"Transformers < Transformers 2"<<std::endl;
    if (rezultatAn==1)
        std::cout<<"Transformers > Transformers 2"<<std::endl;
    if (rezultatAn==0)
        std::cout<<"Transformers = Transformers 2"<<std::endl;

    int rezultatRating=ComparareRating(movie, movie2);
    if (rezultatRating==-1)
        std::cout<<"Transformers < Transformers 2"<<std::endl;
    if (rezultatRating==1)
        std::cout<<"Transformers > Transformers 2"<<std::endl;
    if (rezultatRating==0)
        std::cout<<"Transformers = Transformers 2"<<std::endl;

    int rezultatDurata=ComparareDurata(movie, movie2);
    if (rezultatDurata==-1)
        std::cout<<"Transformers < Transformers 2"<<std::endl;
    if (rezultatDurata==1)
        std::cout<<"Transformers > Transformers 2"<<std::endl;
    if (rezultatDurata==0)
        std::cout<<"Transformers = Transformers 2"<<std::endl;

    int rezultatAniTrecuti=ComparareAniTrecuti(movie,movie2);
    if (rezultatAniTrecuti==-1)
        std::cout<<"Transformers < Transformers 2"<<std::endl;
    if (rezultatAniTrecuti==1)
        std::cout<<"Transformers > Transformers 2"<<std::endl;
    if (rezultatAniTrecuti==0)
        std::cout<<"Transformers = Transformers 2"<<std::endl;

    MovieSeries movieSeries;

    movieSeries.Init();

    movieSeries.Add(&movie);
    movieSeries.Add(&movie2);

    std::cout<<"Lista filme: ";
    movieSeries.Print();
    movieSeries.Sortare();
    std::cout<<"Lista sortata: ";
    movieSeries.Print();
    return 0;
}
