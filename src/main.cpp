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
  UkladRownanLiniowych UklRown; // zmienna do przechowywania Ukladu rownan 
  Wektor wynik; // zmienna do przechowywania wyniku
  string nazwa; // zmienna do przechowywania nazwy pliku z ktorego czytamy
  
  ifstream myfile; // strumien do czytania danych z pliku

  /*************************Otwieranie pliku*****************************/
  std::cout << "Podaj nazwe pliku ktory chcesz otworzyc: " << std::endl;
  std::cin >> nazwa;
  myfile.open(nazwa);
  if(!myfile.is_open()){
    std::cerr << ERRORNAME << endl;
    exit(0);
  }
  
  myfile >> UklRown; // Wczytanie danych z pliku
  if(myfile.eof()){
    std::cerr << ERROREOF << endl;
    exit(0);	  
  }
  myfile.close();
  /*************************Zamkniecie pliku*****************************/

  
   if(!std::cin.good()){
     std::cerr<<ERRORLOAD<<std::endl;
     exit(0);
   }

   std::cout << "Schematyczne przedstawienie ukladu rownan: " << std::endl;
   std::cout << UklRown; // wyswietlenie ukladu rownan

   
  std::cout << "Macierz transponowana ukladu rownan A^T: " << std::endl;
  std::cout<< UklRown.pobierzMacierz().transponuj() <<std::endl;

  std::cout << "Wektor wyrazow wolnych b: " << std::endl;
  std::cout << UklRown.pobierzWektor() << std::endl;

  std::cout << "Metoda Cramera: " << std::endl << std::endl;  // rozwiazanie metoda cramera
  
  std::cout << "Rozwiazanie x = (x1, x2, x3): " << std::endl;
  wynik = UklRown.oblicz(cramer);
  std::cout << std::endl << wynik << std::endl << std::endl;

  Wektor blad = UklRown.pobierzMacierz()*wynik - UklRown.pobierzWektor();
  std::cout << "Wektor bledu: Ax - b =  " << UklRown.pobierzMacierz()*wynik - UklRown.pobierzWektor() << std::endl;
  std::cout << "Dlugosc wektoru bledu: |Ax - b| = " << blad.dlugosc() << std::endl;

  std::cout<< std::endl << "Metoda macierzy odwrotnej: " << std::endl << std::endl;  // rozwiazanie metoda macierzy odwrotnej
    
  wynik = UklRown.oblicz(odwrotna);
  std::cout << std::endl << wynik << std::endl << std::endl;

  blad = UklRown.pobierzMacierz()*wynik - UklRown.pobierzWektor();
  std::cout << "Wektor bledu: Ax - b =  " << UklRown.pobierzMacierz()*wynik - UklRown.pobierzWektor() << std::endl;
  std::cout << "Dlugosc wektoru bledu: |Ax - b| = " << blad.dlugosc() << std::endl;

}
