#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


class Wektor {
  double tab[ROZMIAR];
  
  public:
  Wektor();
  Wektor(double x, double y, double z);
  Wektor(double *tab);
  Wektor(const Wektor & Wektor2);

  const double & operator[] (int index) const;
  double & operator[] (int index);

  Wektor operator + (Wektor const &wektor) const;
  Wektor operator - (Wektor const &wektor) const;
  double operator * (Wektor const &wektor) const;
  Wektor operator * (double const &a) const;
  Wektor operator / (double const &a) const;

  double dlugosc() const;

  bool operator == (const Wektor &Wektor2) const;
  bool operator != (const Wektor &Wektor2) const;
};

Wektor operator * (double a, const Wektor &Wektor2);

std::istream& operator >> (std::istream &strm, Wektor &wektor);

std::ostream& operator << (std::ostream &strm, const Wektor &wektor);

#endif
