#include "Macierz.hh"

#include <iomanip>
#include <iostream>

Macierz::Macierz(){
 for (int j = 0; j < ROZMIAR; j++)
    for (int i = 0; i < ROZMIAR; i++)
       this->tab[i][j] = 0;
}

Macierz::Macierz(const Macierz & macierz2)
{
  for (int i=0; i<ROZMIAR; i++)
  (*this)[i] = macierz2[i];
}

Macierz::Macierz(Wektor wektor1, Wektor wektor2, Wektor wektor3)
{
  (*this)[0] = wektor1;
  (*this)[1] = wektor2;
  (*this)[2] = wektor3;
}

const Wektor  & Macierz::operator[] (int index) const
{
  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}

Wektor & Macierz::operator[] (int index)
{
  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}


Macierz Macierz::operator +(const Macierz & macierz2) const{
  Macierz pomoc;
  for(int i =0; i< ROZMIAR; i++)
    pomoc[i]=(*this)[i] + macierz2[i];
  return pomoc;
}

Macierz Macierz::operator -(const Macierz & macierz2) const
{
  Macierz pomoc;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    pomoc[i] = (*this)[i] - macierz2[i];
  }
  return pomoc;
}

Macierz Macierz::operator *(double a) const 
{
  Macierz pomoc;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    pomoc[i] = (*this)[i] * a;
  }
  return pomoc;
}

bool Macierz::operator == (const Macierz & macierz2) const
{
  for (int i = 0; i < ROZMIAR; i++)    
  {
    if ((*this)[i] != macierz2[i])
      return false;
  }
  return true;
}

bool Macierz::operator != (const Macierz & macierz2) const
{
  return !(*this==macierz2);
}
  
Macierz Macierz::transponuj() const
{
  Macierz wynikowa;
  for (int j = 0; j < ROZMIAR; j++)
    for (int i = 0; i < ROZMIAR; i++)
        wynikowa[j][i]= (*this)[i][j];
  
  return wynikowa;
}

 Wektor Macierz::operator *(const Wektor & Wektor) const
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

Macierz operator *(double a, const Macierz macierz)
{
  return macierz*a;
}

//************Funkcje: in/out************//
std::istream& operator >> (std::istream &strm, Macierz &macierz)
{
  for (int i = 0; i < ROZMIAR; i++)
  { 
    strm>>macierz[i];
  }
  return strm;
}


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
