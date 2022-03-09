// 2020prubna.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void zadPierwsze();
void zadDrugie();
void zadTrzecie();

int main()
{
    zadPierwsze();
    zadDrugie();
    zadTrzecie();
    
}

void zadPierwsze()
{
    //uchwyt na plik z danymi i wynikowy oddzielnie gdyż zapisujemy każdą linię po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("dane4.txt", ios::in);
    //plik.open("przyklad.txt", ios::in);
   
    if (plik.good() == true)
    {
        cout << "plik jest" << endl;
        //tablica na dane
        int liczba[1000];
        //roznica - luka
        int roznica = 0, max = 0, min = 2000000000;
        for (int i = 0; i < 1000; i++)
        {
            plik >> liczba[i];
           
        }

        for (int i = 0; i < 999; i++)
        {
            roznica = liczba[i] - liczba[i + 1];
            if (roznica < 0)
            {
                roznica = roznica * -1;
            }
            if (max < roznica)
                max = roznica;
            if (min > roznica)
                min = roznica;

        }
        cout << max << " " << min << endl;
        
        wynik.open("zadanie4.txt", ios::out);

        wynik << "4.1 najmniejsz= " << min <<" największa= "<<max<< endl;
        wynik.close();
        plik.close();

    }
    else
    {
        cout << "pliku brak\n";
    }
}
void zadDrugie()
{
    //uchwyt na plik z danymi i wynikowy oddzielnie gdyż zapisujemy każdą linię po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("dane4.txt", ios::in);
    //plik.open("przyklad.txt", ios::in);

    if (plik.good() == true)
    {
        cout << "plik jest" << endl;
        int liczba[1000];
      //  int test[9] = { 2,1,1,1,1,1,1,1,2 };
        for (int i = 0; i < 1000; i++)
        {
            plik >> liczba[i];

        }
        // zmienne na wynik
        int dlugosc = 0,  pierwszy = 0, ostatni = 0, roznica = 0;
        //zmienne pomocnicze
        int test, test2, tmp = 0, tmp1 = 0, tmp2 = 0, licznik=0,r=0;
        for (int i = 0; i < 999; i++)
        {
            // od jedynki bo w pierwszym for pobieramy już liczbę
            licznik = 1;
            
            tmp1 = liczba[i];
            //zawiera elemet który pobraliśmy jeśli będzie to 1 element ciągu
            tmp = tmp1;
            test = i;
            tmp2 = liczba[i + 1];
            roznica = tmp1 - tmp2;
            if (roznica < 0)
            {
                roznica = roznica * -1;
            }
            //rozmiar lukli do porównania w pętli wewnętrznej
            r = roznica;

            for (int j = i + 1; j < 1000; j++)
            {
                tmp1 = liczba[j];
                
                tmp2 = liczba[j + 1];
                roznica = tmp1 - tmp2;
                if (roznica < 0)
                {
                    roznica = roznica * -1;
                }
                if (r == roznica)
                {
                    licznik++;
                }
                else
                {
                    if (licznik > dlugosc)
                    {
                        test2 = test;
                        pierwszy = tmp;
                        dlugosc = licznik;
                        ostatni = tmp1;
                    }
                    break;
                }

            }

        }
        cout << dlugosc <<" " <<test2<< " "<< pierwszy<<"  "<<ostatni<<endl;

        wynik.open("zadanie4.txt", ios::app);
        //n= długość ciągu 
        //l -liczba luk = n-1
        //n=l+1
        wynik << "4.2 dlugość= " << dlugosc+1 << " pierwsza liczba to: " << pierwszy <<" ostatnia liczba to: "<<ostatni<< endl;
        wynik.close();
        plik.close();
    }
    else
    {
        cout << "pliku brak\n";
    }
}
void zadTrzecie()
{
    //uchwyt na plik z danymi i wynikowy oddzielnie gdyż zapisujemy każdą linię po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("dane4.txt", ios::in);
    //plik.open("przyklad.txt", ios::in);

    if (plik.good() == true)
    {
        cout << "plik jest" << endl;
        int liczba[1000];
       

        for (int i = 0; i < 1000; i++)
        {
            plik >> liczba[i];

        }
        //zerowanie tablicy tyl;ko przy tworzeniu inaczej pętla
        int tab[2][999] = {};
        int roznica;
   // obliczanie luk
        for (int i = 0; i < 999; i++)
        {
            roznica = liczba[i] - liczba[i + 1];
            if (roznica < 0)
            {
                roznica = roznica * -1;
            }
            tab[0][i] = roznica;
        }
       
        int li = 0, licznik=0;
        //zliczmy krotność luk
        for (int i = 0; i < 999; i++)
        {
            licznik = 0;
            li = tab[0][i];
            for (int j = 0; j < 999; j++)
            {
                if (tab[0][j] == li)
                {
                    licznik++;
                }
            }
            tab[1][i] = licznik;
           // wynik << tab[0][i] << " " << tab[1][i] << endl;
        }

        int max = 0;
        for (int i = 0; i < 999; i++)
        {
            if (max < tab[1][i])
            {
                max = tab[1][i];
              //  wartosc = tab[0][i];
            }
        }
        //zmieniamy wartości luk na -1 tam gdzie ich krotność jest różna od max
        for (int i = 0; i < 999; i++)
        {

            if (tab[1][i] != max)
            {
                tab[0][i] = -1;
            }   

        } 
        
        


        int  tmp=-1;
        //sortowanie bąbelkowe
        for (int i = 0; i < 999; i++)
        {
            for (int j = 0; j < 998; j++)
            {
                if (tab[0][j] < tab[0][j + 1])
                {
                    tmp = tab[0][j];
                    tab[0][j] = tab[0][j + 1];
                    tab[0][j + 1] = tmp;
                }
                if (tab[1][j] < tab[1][j + 1])
                {
                    tmp = tab[1][j];
                    tab[1][j] = tab[1][j + 1];
                    tab[1][j + 1] = tmp;
                }
                
            }


        }
        for (int i = 0; i < 999; i++)
        {
            cout << tab[0][i] << "  " << tab[1][i] << endl;
        }

        //wypisywanie ierwszej wartości krotności max
        tmp = -1;
        int flaga = 0;
         wynik.open("zadanie4.txt", ios::app);
         wynik << "4.3 liczba luk= " << max << endl;
        for (int i = 0; i < 998; i++)
        {
            
            if (tab[0][i] != -1)
            {
                if (flaga == 0)
                {
                    tmp = tab[0][i];
                    cout << tmp<<endl;
                     wynik<<"4.3 Wartość luki to: " << tmp  << endl;
                    flaga = 1;
                   
                }
                if (tmp != tab[0][i + 1])
                {
                    flaga = 0;
                }
 
            }
            else {
                break;
            }
        }


        wynik.close();
        plik.close();
    }
    else
    {
        cout << "pliku brak\n";
    }
}