#include "Wektor.hh"
#include <cmath>
#include <iomanip>

Wektor::Wektor(){
  for(int i=0; i<ROZMIAR; i++)
    (*this)[i]=0;
}

Wektor::Wektor(double xx, double yy, double zz){
  (*this)[0]=xx;
  (*this)[1]=yy;
  (*this)[2]=zz;
}

Wektor::Wektor(double *tab){
  for(int i=0;i<ROZMIAR;i++)
    (*this)[i]=tab[i];
}

Wektor::Wektor(const Wektor &Wektor2){
  for(int i=0;i<ROZMIAR;i++)
    (*this)[i]=Wektor2[i];
}


const Wektor Wektor::operator + (Wektor const &wektor) const{
  Wektor wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i] + wektor[i];
  return wynik;
}

const Wektor Wektor::operator - (Wektor const &wektor) const{
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

const Wektor Wektor::operator * (double const &a) const{
  Wektor wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i]*a;
  return wynik;
}

double Wektor::dlugosc() const{

  return sqrt(pow((*this)[0],2)+pow((*this)[1],2)+pow((*this)[2],2));
}

bool Wektor::operator == (const Wektor &Wektor2) const{

  for(int i=0; i<ROZMIAR;i++){
    if((*this)[i]!=Wektor2[i])
      return false;
  }
  return true;
}

bool Wektor::operator != (const Wektor &Wektor2) const{


  return !((*this)==Wektor2);
}

const Wektor Wektor::Swap (int Wektor1, int Wektor2) const{
  Wektor pomoc(*this);
  
 if (Wektor1 < 0 || Wektor1 >= ROZMIAR || Wektor2 < 0 || Wektor2 >= ROZMIAR)
  {
    std::cerr << "poza zakresem" << std::endl;
    exit(1);
  }
 
  double temp(pomoc[Wektor1]);
  pomoc[Wektor1] = pomoc[Wektor2];
  pomoc[Wektor2] = temp;
  return pomoc; 
}

Wektor operator*(double a, const Wektor & Wektor2){

  return Wektor2*a;
}
/*
std::ostream& operator << (std::ostream &strm, const Wektor &wektor){

  for(int i=0;i<ROZMIAR; i++)
    strm << std::setw(SKIP) << wektor[i];
  return strm;
}
*/
std::istream& operator >> (std::istream &strm, Wektor &wektor){

  for(int i=0;i<ROZMIAR;i++){
    double pomoc;
    strm>>pomoc;
    wektor[i]=pomoc;
  }
  return strm;
}
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
