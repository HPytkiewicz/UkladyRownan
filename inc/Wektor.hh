#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


class Wektor {
  double tab[ROZMIAR];
  
  public:
  Wektor();
  Wektor(double xx, double yy, double zz);
  Wektor(double *tab);
  Wektor(const Wektor & Wektor2);

  const double & operator[] (int index) const;
  double & operator[] (int index);

  const Wektor operator + (Wektor const &wektor) const;
  const Wektor operator - (Wektor const &wektor) const;
  double operator * (Wektor const &wektor) const;
  const Wektor operator * (double const &a) const;

  double dlugosc() const;

  bool operator == (const Wektor &Wektor2) const;
  bool operator != (const Wektor &Wektor2) const;
  const Wektor Swap(int Wektor1, int Wektor2) const;
};

Wektor operator * (double a, const Wektor &Wektor2);


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
