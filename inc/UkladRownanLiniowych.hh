#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"

enum SposobLiczenia {cramer, odwrotna};


class UkladRownanLiniowych {
  Macierz macierz;
  Wektor wektor;

  
  public:
  UkladRownanLiniowych(){};
  UkladRownanLiniowych(const Macierz & macierz2, const Wektor & wektor2);

  const Wektor & pobierzWektor() const;
  void ustawWektor(const Wektor & wektor2);
  const Macierz & pobierzMacierz() const;
  void ustawMacierz(const Macierz & macierz2);
  
  Wektor oblicz(SposobLiczenia sposob) const;
};




std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown);
                          


#endif
