﻿// mat_2015.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
// ładowanie bibliotek - klas

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

//deklaracja przstrzeni nazw z jakiej kożystamy, bez tego musimy używać np. std::cout<<
using namespace std;

//deklaracja funkcji przed main albo cała funkcja 
void zadPierwsze();
void zadDrugie();
void zadTrzecie();
                                //przykładowa funkcja
                                //int suma(int a, int b)
                                //{
                                //    int suma;
                                //    return suma = a + b;
                                //  //  return a + b;
                                //}

int main()
{
                                // cout << suma(suma(6,4), 5) << endl;

   // wywołanie 3 funkcji w rozdzieleniu na zadania
   zadPierwsze();
 //  zadDrugie();
  // zadTrzecie();
   

   //zabezpiecza przed zamknięciem konsoli
    system("PAUSE");




}




void zadPierwsze()
{
        /*w pliku liczby.txt znajduje się 
        1000 
        liczb naturalnych zapisanych binarnie.
        każda liczba zapisana jest w osobnym wierszu.
        pierwsze pięć wierszy zawiera następujące liczby : 

        11010100111 
        11110111111011101 
        1010100111010100 
        1101111111111111111111010100101010101001 
        1010110011001101010011110101010101010111

        każda liczba binarna zawiera co najwyżej 250 cyfr binarnych, 
        co oznacza, że w wielu językach programowania wartości niektórych 
        z tych liczb nie da się zapamiętać w pojedynczej zmiennej typu 
        całkowitoliczbowego, np.w języku c++ w zmiennej typu int.
        http://www.algorytm.edu.pl/wstp-do-c/typy-zmiennych.html  - typy zmiennych
            +  // całkowite np 1 ; 1786
            +  // zmiennoprzecinkowe  2,5; 54,8
        // tekstowe
        napisz program, który da odpowiedzi do poniższych zadań.odpowiedzi zapisz 
        w pliku wynik4.txt, a każdą odpowiedź poprzedź numerem oznaczającym 
        odpowiednie zadanie.*/

        //ZAD 1

        /*Podaj, ile liczb z pliku liczby.txt ma w swoim zapisie binarnym więcej zer niż jedynek.
        Przykład: Dla zestawu liczb : 
        101011010011001100111 
        10001001 +
        1000000 +
        101010011100 
        100010 +
        wynikiem jest liczba 3 
        (3 podkreślone liczby mają w swoim zapisie więcej zer niż jedynek).*/

        // ODP 422 

    // zmienna na każdą linie z pliku
    string linia="";
    //uchwyt na plik
    fstream plik;
    // licznik na liczby z większą liczbą zer
    int licznik = 0;
    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("pliki\\liczby.txt", ios::in);
    // plik.open(ścieżka do pliku+nazwa pliku, ios::in | ios::out | ios::app)
    //sposoby na otwieranie plików
    //http://cpp0x.pl/kursy/Kurs-C++/Obsluga-plikow/305

    // sprawdzamy czy plik istnieje, został poprawnie otworzony
    if (plik.good() == true)
    {
        cout << "plik jest\n";
        //za pomocą pętli while pobieramy linia po lini
        while (getline(plik, linia))
        {// pobieramy z zmiennej plik pierwszą linie i wstawiamy do zmiennej linia
            // liczniki
             int jeden = 0, zero = 0;
            //cout << linia.length() << endl;
            
            //cout << linia.size() << endl;

            for (int i = 0; i < linia.size(); i++)
               // for (int i = 0; i <= linia.size(); i++)
                //tutaj zmieniłem z pętli for each i musiałem dodac tablice z linia[i]
            {
                cout << linia << "  " << linia[i] << " i "<< i <<endl;
                if (linia[i] == '1')
                {
                    jeden++;
                }
                else if (linia[i] == '0')
                {
                    zero++;
                }

            }
          //  cout << jeden << "   " << zero << endl;
            //break;
            if (zero > jeden)
            {
                licznik++;
            }
          
           
        }

        cout << licznik << endl;
        //zamykamy plik z liczbami
        plik.close();



    // sprawdzamy czy plik istnieje, został poprawnie otworzony
   
        //otwieramy plik wynikowy z opcją zapisu
        plik.open("pliki\\wynik4.txt", ios::out);
        plik << "4.1 " << licznik << endl;
        plik.close();
    }
    else
    {
        cout << "pliku brak\n";
    }

}


void zadDrugie()
{


    //500 – liczba liczb podzielnych przez 2. 
    //123 – liczba liczb podzielnych przez 8.

    // 8     4   2   1
    //2^3   2^2 2^1 2^0
    string linia;
    fstream plik;


    plik.open("pliki\\liczby.txt", ios::in);
    if (plik.good() == true)
    {
        int osiem = 0;
        int dwa = 0;
        // numer ostatniego elementu w zmiennej linia
        int ostatnia = 0;
        int wczesniej = 0;
        cout << "plik jest\n";
        while (getline(plik, linia))
        {            
            ostatnia = linia.length()-1;
            int wczesniej = ostatnia - 3;
           
            // pobier z zmiennej linia znak znajdujący się na pozycji ostatnia
            if (linia.at(ostatnia) == '0')
            {
                dwa++;
            
            }

            if (ostatnia >= 4)
            {
                if ( linia.at(ostatnia - 1) == '0' && linia.at(ostatnia - 2) == '0' && linia.at(ostatnia) == '0') 
                {
                    osiem++;
                    //cout << linia << "  " << wczesniej << endl;
                }
            }
            
        }
        cout << "dwa "<< dwa << "  osiem "<<osiem << endl;
        plik.close();
        //otwieramy plik wynikowy z opcją zapisu
        plik.open("pliki\\wynik4.txt", ios::app);
        plik << "4.2 " << "dwa " << dwa << "  osiem " << osiem << endl;
        plik.close();
    }
    else
    {
        cout << "pliku brak\n";
    }



}




void zadTrzecie()
{

  //859 – numer wiersza zawierającego minimalną liczbę. 
    //925 – numer wiersza zawierającego maksymalną liczbę. 

    fstream plik;
    plik.open("pliki\\liczby.txt", ios::in);


    if (plik.good() == true)
    {   // stringi zerujemy/ czyścimy ="" ; chary ='' ; int, double =0
        string linia = "", min = "", max = "";
        //zerowanie startowych numerów lini
        int nrMin = 0, nrMax = 0,i=0;
  
        cout << "plik jest\n";
        //for(int i=0; i<1000; i++)
        while (getline(plik, linia))
        {
            i++;
            if (i == 1)
                min = linia;
            if (linia.size() > max.size())
            {
                max = linia;
                nrMax = i;
            }
            else if (linia.size() == max.size())
            {

                //leksykonalnie
                //tabela ASCII
                if (linia > max)
                {
                    max = linia;
                    nrMax = i;
                }
            }
            //-----------------------------


            if (linia.size() < min.size())
            {
                min = linia;
                nrMin = i;
            }
            else if (linia.size() == min.size())
                if (linia < min)
                {
                    min = linia;
                    nrMin = i;
                }




        }
        cout << nrMax << "   "<< nrMin<< endl;
       
        plik.close();
        plik.open("pliki\\wynik4.txt", ios::app);
        plik << "4.3 " << "Minimalna " << nrMin << "  Maksymalna " << nrMax << endl;
        plik.close();
        
    }
    else
    {
        cout << "pliku brak\n";
  
    }



}