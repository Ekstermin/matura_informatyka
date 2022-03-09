// 2018.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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

//Naukowcy zauważyli, że po złączeniu dziesiątych liter co czterdziestego słowa(zaczynając od
//    słowa czterdziestego) otrzymamy pewne przesłanie.Wypisz to przesłanie.
//    Uwaga: Każde co czterdzieste słowo ma co najmniej 10 znaków.
//    Dla danych z pliku przyklad.txt wynikiem jest :
//NIECHCIMATURAPROSTABEDZIE

void zadPierwsze()
{


    //uchwyt na plik z danymi i wynikowy oddzielnie gdyż zapisujemy każdą linię po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("sygnaly.txt", ios::in);
    //plik.open("przyklad.txt", ios::in);

    if (plik.good() == true)
    {
        cout << "plik jest" << endl;
        // linia na pobraną linię, tmp - na sklejone słowo
        string linia = "", tmp = "";

        for (int i = 1; i <= 1000; i++)
        {

            plik >> linia;
            //jeżeli i modulo 40 da reszty zero, znaczy że 'i' jest podzielne przez zero
            if (i % 40 == 0)
            {
                tmp = tmp + linia[9];
            }
            
        }
        cout << tmp << endl;

        wynik.open("wynik4.txt", ios::out);
        
        wynik << "4.1 " << tmp  << endl;
        wynik.close();
        plik.close();

    }
    else
    {
        cout << "pliku brak\n";
    }

}


//Znajdź słowo, w którym występuje największa liczba różnych liter.Wypisz to słowo i liczbę
//występujących w nim różnych liter.Jeśli słów o największej liczbie różnych liter jest więcej
//niż jedno, wypisz pierwsze z nich pojawiające się w pliku z danymi.
//Dla danych z pliku przyklad.txt wynikiem jest :
//AKLMNOPRSTWZA 12

void zadDrugie()
{


    //uchwyt na plik z danymi i wynikowy oddzielnie gdyż zapisujemy każdą linię po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("sygnaly.txt", ios::in);
    //plik.open("przyklad.txt", ios::in);

    if (plik.good() == true)
    {
        cout << "plik jest" << endl;
        //linia - na dane z pliku
        // linia2 - przechowuje wynik
        //tmp- na tymczasowe dane, 
        string linia = "", linia2 = "", tmp = "";
        //licznik- zlicza różne litery, 
        //licznik2- licznik wynikowy
        //dlugosc_l -długść lini
        //flaga - do oznaczania czy litery są takie same
        int licznik = 1, licznik2 = 0, dlugosc_l = 0, flaga = 0, l = 0;
        //literka - schowek na kolejne/następne litery
        char  litera = ' ';
        for (int i = 0; i < 1000; i++)
        {
            tmp = "";
            plik >> linia;
            dlugosc_l = linia.size();
            
            for (int j = 0; j < dlugosc_l-1; j++)
            {
                    l = j + 1;
                    tmp = tmp + linia[j];
                    litera = linia[l]; // TUUUUUUUUUUUU
                    for (int k = 0; k < tmp.size(); k++)
                    {
                        //AKLM NOPRSTWZA
                        //A 1
                        //AK 
                        if (litera == tmp[k])
                        {
                            flaga = 1;
                            break;
                        }
                    }
                    if (flaga == 0)
                    {
                        licznik++;
                        
                    }

                

                    flaga = 0;
            }
            if (licznik > licznik2)
            {
                licznik2 = licznik;
                linia2 = linia; 
            }
            licznik = 1;
        }
        cout <<linia2 << " - " << licznik2 << endl;

        wynik.open("wynik4.txt", ios::app);

        wynik << "4.2 " << linia2 << " - " << licznik2 << endl;
        wynik.close();
        plik.close();

    }
    else
    {
        cout << "pliku brak\n";
    }

}

//W tym zadaniu rozważmy odległość liter w alfabecie – np.litery A i B są od siebie oddalone
//o 1, A i E o 4, F i D o 2, a każda litera od siebie samej jest oddalona o 0. Wypisz wszystkie
//słowa, w których każde dwie litery oddalone są od siebie w alfabecie co najwyżej o 10. Słowa
//wypisz w kolejności występowania w pliku sygnaly.txt, po jednym w wierszu.
//Na przykład CGECF jest takim słowem, ale ABEZA nie jest(odległość A – Z wynosi 25).


void zadTrzecie()
{


    //uchwyt na plik z danymi i wynikowy oddzielnie gdyż zapisujemy każdą linię po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("sygnaly.txt", ios::in);
    //plik.open("przyklad.txt", ios::in);

    if (plik.good() == true)
    {
        cout << "plik jest" << endl;
        wynik.open("wynik4.txt", ios::app);
        
        string linia = "";
        int  litera = 0, litera2=0, flaga=1, roznica=0,licznik=0;
        size_t dlugosc = 0;
        for (int i = 0; i < 1000; i++)
        {
            flaga = 1;
            plik >> linia;
            dlugosc = linia.size();
            for (int j = 0; j < dlugosc; j++)
            {
                litera = linia[j];
                for (int k = 0; k < dlugosc; k++)
                {
                    litera2 = linia[k];
                    roznica = litera - litera2;
                    if (roznica < 0)
                    {
                        roznica = roznica * -1;
                    }
                    //abs();
                    if (roznica >10)
                    {
                        flaga = 0;
                        break;
                    }
                }
                if (flaga == 0) break;
            }
            if (flaga == 1)
            {
                licznik++;
                cout <<licznik<<"  "<< linia << endl;
                wynik << "4.3 " << linia << endl;
                
            }
        }
        

        /*wynik.open("wynik4.txt", ios::app);

        wynik << "4.2 " << linia2 << " - " << licznik2 << endl;
        wynik.close();*/
        plik.close();
        wynik.close();

    }
    else
    {
        cout << "pliku brak\n";
    }

}