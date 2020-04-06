#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>

class Macierz {
  Wektor tab[ROZMIAR];
  double dopelnienie(int x, int y) const;
 public:
  Macierz();
  Macierz(Wektor wektor1,Wektor wektor2,Wektor wektor3);
  Macierz(const Macierz &macierz2);

  const Wektor  & operator[] (int index) const;
  Wektor & operator[] (int index);

  const Macierz operator +(const Macierz & macierz) const;
  const Macierz operator -(const Macierz & macierz) const;
  const Macierz operator *(const Macierz & macierz) const;

  const Macierz operator *(double a) const;
  const Wektor operator *(const Wektor & Wektor) const;

  bool operator == (const Macierz & Wektor2) const;
  bool operator != (const Macierz & Wektor2) const;

  const Macierz transponuj() const;
  const Macierz odwroc() const;
  
};


const Macierz operator * (double a, const Macierz macierz);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
