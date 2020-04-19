#include "Wektor.hh"
#include <cmath>
#include <iomanip>

Wektor::Wektor(){
  for(int i=0; i<ROZMIAR; i++)
    (*this)[i]=0;
}

Wektor::Wektor(double x, double y, double z){
  (*this)[0]=x;
  (*this)[1]=y;
  (*this)[2]=z;
}

Wektor::Wektor(double *tab){
  for(int i=0;i<ROZMIAR;i++)
    (*this)[i]=tab[i];
}

Wektor::Wektor(const Wektor &Wektor2){
  for(int i=0;i<ROZMIAR;i++)
    (*this)[i]=Wektor2[i];
}

const double & Wektor::operator[] (int index) const{
  
  if(index <0 || index >= ROZMIAR){
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}

double & Wektor::operator[] (int index){
  if(index < 0 || index >= ROZMIAR){
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}

Wektor Wektor::operator + (Wektor const &wektor) const{
  Wektor wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i] + wektor[i];
  return wynik;
}

Wektor Wektor::operator - (Wektor const &wektor) const{
  Wektor wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i] - wektor[i];
  return wynik;
}

double Wektor::operator * (Wektor const &wektor) const{
  double wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik+=(*this)[i] * wektor[i];
  return wynik;
}

Wektor Wektor::operator * (double const &a) const{
  Wektor wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i]*a;
  return wynik;
}

Wektor Wektor::operator / (double const &a) const{
  Wektor wynik;
  if(a!=0){
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i]/a;
  return wynik;
  }else
    exit(1);
}


double Wektor::dlugosc() const{
  double wynik;
  for(int i=0;i<ROZMIAR; i++){
    wynik+=(*this)[i]*(*this)[i];
  }
  return sqrt(wynik);
}

bool Wektor::operator == (const Wektor &Wektor2) const{

  for(int i=0; i<ROZMIAR;i++){
    if(abs((*this)[i]-Wektor2[i])>0.0001)
      return false;
  }
  return true;
}

bool Wektor::operator != (const Wektor &Wektor2) const{


  return !((*this)==Wektor2);
}

Wektor Wektor::Swap (int Wektor1, int Wektor2) const{
  Wektor pomocniczy(*this);
  
 if (Wektor1 < 0 || Wektor1 >= ROZMIAR || Wektor2 < 0 || Wektor2 >= ROZMIAR)
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
 
  double temp(pomocniczy[Wektor1]);
  pomocniczy[Wektor1] = pomocniczy[Wektor2];
  pomocniczy[Wektor2] = temp;
  return pomocniczy; 
}

Wektor operator*(double a, const Wektor & Wektor2){

  return Wektor2*a;
}

std::ostream& operator << (std::ostream &strm, const Wektor &wektor){

  for(int i=0;i<ROZMIAR; i++)
    strm << std::setw(SKIP) << wektor[i];
  return strm;
}

std::istream& operator >> (std::istream &strm, Wektor &wektor){

  for(int i=0;i<ROZMIAR;i++){
    double pomoc;
    strm>>pomoc;
    wektor[i]=pomoc;
  }
  return strm;
}
