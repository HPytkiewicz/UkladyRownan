#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


enum metodaWyznacznika {sarrus, laplace};

class Macierz {
  Wektor tab[ROZMIAR];
  double dopelnienie(int x, int y) const;
 public:
  Macierz();
  Macierz(Wektor wektor1,Wektor wektor2,Wektor wektor3);
  Macierz(const Macierz &macierz2);

  const Wektor  & operator[] (int index) const;
  Wektor & operator[] (int index);

  Macierz operator +(const Macierz & macierz) const;
  Macierz operator -(const Macierz & macierz) const;
  Macierz operator *(const Macierz & macierz) const;

  Macierz operator *(double a) const;
  Wektor operator *(const Wektor & wektor) const;

  bool operator == (const Macierz & Macierz2) const;
  bool operator != (const Macierz & Macierz2) const;

  Macierz transponuj() const;
  Macierz odwroc() const;


  double wyznacznik(metodaWyznacznika metoda = sarrus) const; 
};


Macierz operator * (double a, const Macierz macierz);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &strm, Macierz &macierz);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &strm, const Macierz &macierz);


#endif
