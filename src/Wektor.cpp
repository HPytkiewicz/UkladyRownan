#include "Wektor.hh"
#include <cmath>
#include <iomanip>

// Inicjalizacja pustego wektora
Wektor::Wektor(){
  for(int i=0; i<ROZMIAR; i++)
    (*this)[i]=0;
}

// Inicjalizacja wektora liczbami
Wektor::Wektor(double x, double y, double z){
  (*this)[0]=x;
  (*this)[1]=y;
  (*this)[2]=z;
}

// Inicjalizacja wektora tablica
Wektor::Wektor(double *tab){
  for(int i=0;i<ROZMIAR;i++)
    (*this)[i]=tab[i];
}

// Inicjalizacja wekotra innym wektorem
Wektor::Wektor(const Wektor &Wektor2){
  for(int i=0;i<ROZMIAR;i++)
    (*this)[i]=Wektor2[i];
}

// Odwolanie sie do indexu wektora
const double & Wektor::operator[] (int index) const{
  
  if(index <0 || index >= ROZMIAR){
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}

// Odwolanie sie do indexu wektora
double & Wektor::operator[] (int index){
  if(index < 0 || index >= ROZMIAR){
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}

// Dodanie wektorow
Wektor Wektor::operator + (Wektor const &wektor) const{
  Wektor wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i] + wektor[i];
  return wynik;
}

// Odejmowanie wektorow
Wektor Wektor::operator - (Wektor const &wektor) const{
  Wektor wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i] - wektor[i];
  return wynik;
}

// Mnozenie wektorow
double Wektor::operator * (Wektor const &wektor) const{
  double wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik+=(*this)[i] * wektor[i];
  return wynik;
}

// Mnozenie wektora i liczby rzeczywistej
Wektor Wektor::operator * (double const &a) const{
  Wektor wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i]*a;
  return wynik;
}

// Dzielenie wektora i liczby rzeczywistej
Wektor Wektor::operator / (double const &a) const{
  Wektor wynik;
  if(a!=0){
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i]/a;
  return wynik;
  }else
    exit(1);
}

// Zwraca dlugosc wektora
double Wektor::dlugosc() const{
  double wynik;
  for(int i=0;i<ROZMIAR; i++){
    wynik+=(*this)[i]*(*this)[i];
  }
  return sqrt(wynik);
}

// Porownanie wektorow (czy sa rowne)
bool Wektor::operator == (const Wektor &Wektor2) const{

  for(int i=0; i<ROZMIAR;i++){
    if(abs((*this)[i]-Wektor2[i])>0.0001)
      return false;
  }
  return true;
}

// Porownanie wektorow (czy nie sa rowne)
bool Wektor::operator != (const Wektor &Wektor2) const{


  return !((*this)==Wektor2);
}

// Mnozenie liczby rzeczywistej razy wektor (odwrotna kolejnosc)
Wektor operator*(double a, const Wektor & Wektor2){

  return Wektor2*a;
}

// Wypisanie wektora
std::ostream& operator << (std::ostream &strm, const Wektor &wektor){

  for(int i=0;i<ROZMIAR; i++)
    strm << std::setw(SKIP) << wektor[i];
  return strm;
}

// Wczytanie wektora
std::istream& operator >> (std::istream &strm, Wektor &wektor){

  for(int i=0;i<ROZMIAR;i++){
    double pomoc;
    strm>>pomoc;
    wektor[i]=pomoc;
  }
  return strm;
}
