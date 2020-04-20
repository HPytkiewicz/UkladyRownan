#include "Macierz.hh"

#include <iomanip>
#include <iostream>

// Inicjalizacja pustej macierzy
Macierz::Macierz(){
 for (int j = 0; j < ROZMIAR; j++)
    for (int i = 0; i < ROZMIAR; i++)
       this->tab[i][j] = 0;
}

// Inicjalizacja macierzy inna macierza
Macierz::Macierz(const Macierz & macierz2){
  for (int i=0; i<ROZMIAR; i++)
  (*this)[i] = macierz2[i];
}

// INicjazlizacja macierzy wektorami
Macierz::Macierz(Wektor wektor1, Wektor wektor2, Wektor wektor3){
  (*this)[0] = wektor1;
  (*this)[1] = wektor2;
  (*this)[2] = wektor3;
}

// Odwolanie sie do indexu macierzy
const Wektor  & Macierz::operator[] (int index) const{

  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}

// Odwolanie sie do indexu macierzy
Wektor & Macierz::operator[] (int index){

  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}

// Dodawanie macierzy
Macierz Macierz::operator +(const Macierz & macierz) const{
  Macierz pomocnicza;
  for(int i =0; i< ROZMIAR; i++)
    pomocnicza[i]=(*this)[i] + macierz[i];
  return pomocnicza;
}

// Odejmowanie macierzy
Macierz Macierz::operator -(const Macierz & macierz) const
{
  Macierz pomocnicza;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    pomocnicza[i] = (*this)[i] - macierz[i];
  }
  return pomocnicza;
}

// Mnozenie macierzy i liczby
Macierz Macierz::operator *(double a) const 
{
  Macierz pomocnicza;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    pomocnicza[i] = (*this)[i] * a;
  }
  return pomocnicza;
}

// Porownywanie macierzy (czy sa rowne)
bool Macierz::operator == (const Macierz & Macierz2) const
{
  for (int i = 0; i < ROZMIAR; i++)    
  {
    if ((*this)[i] != Macierz2[i])
      return false;
  }
  return true;
}

// Porownywanie macierzy (czy nie sa rowne)
bool Macierz::operator != (const Macierz & Macierz2) const
{
  return !(*this==Macierz2);
}

// Transopnuje macierz
Macierz Macierz::transponuj() const
{
  Macierz wynikowa;
  for (int j = 0; j < ROZMIAR; j++)
    for (int i = 0; i < ROZMIAR; i++)
        wynikowa[j][i]= (*this)[i][j];
  
  return wynikowa;
}

// Oblicza dopelnienie macierzy
double Macierz::dopelnienie(int x, int y) const{
  double pomoc;
  if(x< 0 || x >= ROZMIAR || y<0 || y >= ROZMIAR){
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  pomoc= (*this)[(x+1)%ROZMIAR][(y+1)%ROZMIAR] * (*this)[(x+2)%ROZMIAR][(y+2)%ROZMIAR] - (*this)[(x+2)%ROZMIAR][(y+1)%ROZMIAR] * (*this)[(x+1)%ROZMIAR][(y+2)%ROZMIAR];
  return pomoc;
}

// Oblicza macierz odwrotna
Macierz Macierz::odwroc() const{
  Macierz macierzpom;
  double wyznacznik=(*this).wyznacznik(sarrus);
  if(wyznacznik != 0){
    for(int j=0; j<ROZMIAR; j++)
      for(int i=0; i<ROZMIAR; i++)
	macierzpom[i][j]=(*this).dopelnienie(i,j) / wyznacznik;
  }else{
    exit(0);
  }
  return macierzpom.transponuj();
}

// Mnozenie macierzy i wektora
 Wektor Macierz::operator *(const Wektor & wektor) const
{
  Wektor wynik;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    for (int j = 0; j < ROZMIAR; j++)    
    {
      wynik[i] += (*this)[j][i] * wektor[j];
    }
  }
  return wynik;
}

// Mnozenie liczby rzeczywistej i macierzy (odwrotna kolejnosc)
Macierz operator *(double a, const Macierz macierz)
{
  return macierz*a;
}

// Obliczenie wyznacznika macierzy
double Macierz::wyznacznik(metodaWyznacznika metoda) const{

  double pomoc=0;
  switch (metoda){
  case sarrus:
    for(int i=0; i<ROZMIAR; i++)
      pomoc += (*this)[i % ROZMIAR][0] * (*this)[(i+1) % ROZMIAR][1] * (*this)[(i+2) % ROZMIAR][2];
    for(int i=0; i<ROZMIAR; i++)
      pomoc -= (*this)[i % ROZMIAR][0] * (*this)[(i+2) % ROZMIAR][1] * (*this)[(i+1) % ROZMIAR][2];
    return pomoc;
    
  case laplace:
    for(int i=0; i<ROZMIAR; i++)
      pomoc+= (*this)[i][0] * ((*this).dopelnienie(i,0));
    return pomoc;
  }
  std::cerr << ERRORNOENUM << std::endl;
  exit(0);
  
}

// Wczytanie macierzy
std::istream& operator >> (std::istream &strm, Macierz &macierz)
{
  for (int i = 0; i < ROZMIAR; i++)
  { 
    strm>>macierz[i];
  }
  return strm;
}

// Wypisanie macierzy
std::ostream& operator << (std::ostream &strm, const Macierz &macierz)
{
  for (int i = 0; i < ROZMIAR; i++)
  {
     for (int j = 0; j < ROZMIAR; j++)
     {
       strm << std::setw(SKIP) << macierz.transponuj()[i][j];
     }
   strm  << std::endl;
  }
  return strm;
}

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
