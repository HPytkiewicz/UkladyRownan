#include "UkladRownanLiniowych.hh"
#include <iomanip>

UkladRownanLiniowych::UkladRownanLiniowych(const Macierz & macierz2, const Wektor & wektor2)
{
  this->macierz=macierz2;
  this->wektor=wektor2;
}

const Wektor & UkladRownanLiniowych::pobierzWektor() const
{
  return wektor;
}

void UkladRownanLiniowych::ustawWektor(const Wektor & wektor2){
  this->wektor = wektor2;
}

const Macierz & UkladRownanLiniowych::pobierzMacierz() const
{
  return macierz;
}

void UkladRownanLiniowych::ustawMacierz(const Macierz & macierz2){
  this->macierz = macierz2;
}

Wektor UkladRownanLiniowych::oblicz(SposobLiczenia sposob) const{
  Macierz macierzpom(this->macierz);
  Wektor wynik;

  switch(sposob){
  case cramer:
    double wyznacznikPom;

    wyznacznikPom=macierzpom.wyznacznik(sarrus);

    for(int i=0;i<ROZMIAR; ++i){
      macierzpom[i]=wektor;
      wynik[i]=macierzpom.wyznacznik(sarrus);
      macierzpom[i]=macierz[i]; 
    }
    if(wyznacznikPom !=0){
      for(int i=0;i<ROZMIAR; ++i){
	wynik[i]=wynik[i]/wyznacznikPom;
      }
      return wynik;
    } else{
      std::cerr << ERRORNOANSWER << std::endl;
      exit(1);
    }

  case odwrotna:
    macierzpom=macierzpom.odwroc();
    wynik=macierzpom * wektor;
    return wynik;
  }
  std::cerr << ERROROUTOFENUM << std::endl;
  exit(0);
}

std::istream & operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown){
  Wektor pomocWektor;
  Macierz pomocMacierz;
  Strm >> pomocMacierz >> pomocWektor;

  UklRown.ustawMacierz(pomocMacierz);
  UklRown.ustawWektor(pomocWektor);
  return Strm;

}

std::ostream & operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown){

  Macierz pomocnicza(UklRown.pobierzMacierz().transponuj());
  
  for (int i = 0; i < ROZMIAR; i++){
      Strm <<  " |" << pomocnicza[i] << "| " << " |x_" << i+1 << "|"<< std::setw(2) << (i==1?'=':' ') << std::setw(2) << "|";
      Strm << std::setw(SKIP) << UklRown.pobierzWektor()[i] << "|" << std::endl;
  }
}
