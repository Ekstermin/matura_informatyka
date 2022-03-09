// 2019.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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
    plik.open("liczby.txt", ios::in);
    //plik.open("przyklad.txt", ios::in);

    if (plik.good() == true)
    {
        cout << "plik jest" << endl;
      
        //zmienna na liczby z pliku
        int liczba = 0, flaga=0, licznik = 0;
        int tab[11] = { 1,3,9,27,81,243,729,2187,6561,19683,59049 };

        for (int i = 0; i < 500; i++)
        {
           
            plik >> liczba;
           
            for (int j = 0; j < 11; j++)
            {
                if (liczba == tab[j])
                {
                    flaga = 1;
                    cout << liczba << endl;
                    break;
                }
            }
            if (flaga == 1)
            {
                licznik++;
                flaga = 0;
            }
        }
        cout << licznik << endl;

        wynik.open("wynik4.txt", ios::out);

        wynik << "4.1 " << licznik << endl;
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
    plik.open("liczby.txt", ios::in);
    //plik.open("przyklad.txt", ios::in);

    if (plik.good() == true)
    {
        cout << "plik jest" << endl;
        //int aa = 0;
        //zmienna na liczby z pliku
        int liczba = 0, liczba2 = 0,tmp=1 , flaga = 0, suma=0;
        int reszta=0;
     
        wynik.open("wynik4.txt", ios::app);

        for (int i = 1; i <= 500; i++)
        {
            tmp = 1, suma=0;
            plik >> liczba;
            liczba2 = liczba;
            while(liczba > 0)
            {
                // 
                reszta = liczba % 10;
                liczba = liczba / 10;

                for (int j = 1; j <= reszta; j++)
                {
                    
                    //4!= 1*2*3*4 = 24
                    //1!=1
                    //1+24=25 !=14
                    //145 - 1!+4!+5!
                    tmp = tmp * j;
                    
                }
                suma = suma + tmp;
                tmp = 1;
            }
            if (suma == liczba2)
            {
                cout <<"  "<< liczba2 << endl;
              //  cout << suma << endl;
                wynik << "4.2 " << liczba2 << endl;
               
            }
            
           // break;
        }


        

        
        wynik.close();
        plik.close();

    }
    else
    {
        cout << "pliku brak\n";
    }

}

//http://www.algorytm.edu.pl/algorytmy-maturalne/algorytm-eulkidesa.html
int NWD(int a, int b)
{
    int pom;

    while (b != 0)
    {
        pom = b;
        b = a % b;
        a = pom;
    }

    return a;
}

//int NWD(int a, int b)
//{
//    if (b != 0)
//        return NWD(b, a % b);
//
//    return a;
//}

void zadTrzecie()
{


    //uchwyt na plik z danymi i wynikowy oddzielnie gdyż zapisujemy każdą linię po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("liczby.txt", ios::in);
    //plik.open("przyklad.txt", ios::in);

    if (plik.good() == true)
    {
        cout << "plik jest" << endl;
        int tab[500];
        for (int i = 0; i < 500; i++)
        {
            plik >> tab[i];
        }
        // na wynik
        int dlmax = 1, dziel = 0, pierwsza2 = 0;
        //dla nwd
        int nwd = 0, tmpnwd = 0;
        //tymczasowe przy obliczaniu
        int dl = 0, pierwsza = 0;
        for (int i = 0; i < 499; i++)
        {
            //1 bo pierwszy zawsze będzie miał jeden
            dl = 1;
            //przypisujemy startowe wartości w każdej głównej pętli
            pierwsza = tab[i];
            tmpnwd = tab[i];
            //od o jeden większej pozycji
            for (int j = i+1; j < 500; j++)
            {
                //obliczmy nwd tab[1] i tab[2]
                nwd = NWD(tmpnwd, tab[j]);
                //założenia z zadania
                if (nwd > 1) 
                { 
                    //zależność NWD((a,b),c) więc przypisujemy nową wartość
                    tmpnwd = nwd; 
                    dl++; 
                }
                //jeśli nwd ==1 albo koniec pętli
                if (nwd == 1 || j == 499)
                {
                   // sprawdzamy długość i przerywamy
                    if (dl > dlmax)
                    {
                        dlmax = dl;
                        dziel = tmpnwd;
                        pierwsza2 = pierwsza;
                    }
                    break;
                }
                
            }
      

        }
        cout << pierwsza2 << "   " << dlmax << "   " << dziel << endl;
       
       


        wynik.open("wynik4.txt", ios::app);
        wynik << "4.3 Pierwsza " << pierwsza2 << "  dlugosc " << dlmax << "  dzielnik " << dziel << endl;

        wynik.close();
        plik.close();

    }
    else
    {
        cout << "pliku brak\n";
    }

}