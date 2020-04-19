#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "rozmiar.h"
#include <iomanip>
#include <fstream>


using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  UkladRownanLiniowych   UklRown;
  Wektor wynik;
  string nazwa;

  
  ifstream myfile;
  std::cout << "Podaj nazwe pliku ktory chcesz otworzyc: " << std::endl;
  std::cin >> nazwa;
  myfile.open(nazwa);
  if(!myfile.is_open()){
    std::cerr << "Niepoprawna nazwa pliku. " << endl;
    exit(0);
  }
  
  myfile >> UklRown;
  if(myfile.eof()){
    std::cerr << "Error: Koniec pliku! " << endl;
    exit(0);	  
  }
  myfile.close();
  
   if(!std::cin.good()){
     std::cerr<<ERRORLOAD<<std::endl;
     exit(0);
   }

   std::cout << "Schematyczne przedstawienie ukladu rownan: " << std::endl;
   std::cout << UklRown;

   
  std::cout << "Macierz transponowana ukladu rownan A^T: " << std::endl;
  std::cout<< UklRown.pobierzMacierz().transponuj() <<std::endl;

  std::cout << "Wektor wyrazow wolnych b: " << std::endl;
  std::cout << UklRown.pobierzWektor() << std::endl;

  std::cout << "Metoda Cramera: " << std::endl << std::endl;
  
  std::cout << "Rozwiazanie x = (x1, x2, x3): " << std::endl;
  wynik = UklRown.oblicz(cramer);
  std::cout << std::endl << wynik << std::endl << std::endl;

  Wektor blad = UklRown.pobierzMacierz()*wynik - UklRown.pobierzWektor();
  std::cout << "Wektor bledu: Ax - b =  " << UklRown.pobierzMacierz()*wynik - UklRown.pobierzWektor() << std::endl;
  std::cout << "Dlugosc wektoru bledu: |Ax - b| = " << blad.dlugosc() << std::endl;

  std::cout<< std::endl << "Metoda macierzy odwrotnej: " << std::endl << std::endl;
    
  wynik = UklRown.oblicz(odwrotna);
  std::cout << std::endl << wynik << std::endl << std::endl;

  blad = UklRown.pobierzMacierz()*wynik - UklRown.pobierzWektor();
  std::cout << "Wektor bledu: Ax - b =  " << UklRown.pobierzMacierz()*wynik - UklRown.pobierzWektor() << std::endl;
  std::cout << "Dlugosc wektoru bledu: |Ax - b| = " << blad.dlugosc() << std::endl;

  
  /*   UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej
   Wektor wynik;
   //   bool Errowynik;
   std::cout << std::endl;
   std::cin >> UklRown;
   if(!std::cin.good()){
     std::cerr<<ERRORLOAD<<std::endl;
     exit(0);
   }
   std::cout<< UklRown << std::endl;
   wynik = UklRown.oblicz(odwrotna);
   std::cout << std::endl << wynik << std::endl;
  */
}
