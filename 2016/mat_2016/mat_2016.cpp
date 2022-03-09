// mat_2016.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*Podstawieniowy szyfr Cezara z przesunięciem(kluczem) k polega na zastąpieniu każdego 
znaku jawnego znakiem leżącym w alfabecie o k pozycji w prawo od zastępowanego znaku.
Przykład: znak ‘B’ po zakodowaniu kluczem k = 3 zastąpiony zostanie znakiem ‘E’.

… A B C D E F …    1 2  3

Przy szyfrowaniu znaku należy postępować w sposób cykliczny, 
to znaczy, jeżeli znak nie posiada w alfabecie następnika przesuniętego o k pozycji,
to alfabet „zawija się" i za literą Z następuje znów litera A. 
Przykład: jawny znak ‘X’ po zakodowaniu kluczem k=3 zastąpiony zostanie znakiem ‘A’,
znak ‘Y’ – znakiem ‘B’, natomiast ‘Z’ – znakiem ‘C’. 

… W X Y Z A B C D …

W tym zadaniu rozpatrujemy tylko słowa zbudowane z wielkich liter
alfabetu angielskiego(o kodach ASCII odpowiednio od 65 do 90), 
o długościach nie większych niż 30 znaków*/


void zadPierwsze();
void zadDrugie();
void zadTrzecie();

int main()
{
    //zadPierwsze();
    //zadDrugie();
    zadTrzecie();
    system("PAUSE");
}




//W pliku dane_6_1.txt znajduje się 100 słów.Słowa umieszczono w osobnych wierszach.
//
//Fragment pliku dane_6_1.txt: INTERPRETOWANIE ROZWESELANIE KONSERWOWANIE Napisz program, 
//który zaszyfruje s łowa z pliku dane_6_1.txt z użyciem klucza  k = 107. Wynik zapisz do pliku wyniki_6_1.txt, 
//każde słowo w osobnym wierszu, w porządku odpowiadającym kolejności słów z pliku z danymi.
//Uwaga : Dla pierwszego słowa z pliku dane_6_1.txt(INTERPRETOWANIE) wynikiem jest słowo LQWHUSUHWRZDQLH.

void zadPierwsze()
{
   
// zmienna na każdą linie z pliku
    string linia = "", nowa_linia;
    //uchwyt na plik z danymi i wynikowy oddzielnie gdyż zapisujemy każdą linię po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("dane_6_1.txt", ios::in);
    // plik.open(ścieżka do pliku+nazwa pliku, ios::in | ios::out | ios::app)
    //65-90 czyli 
    //107mod26 = 3
    int k = 3, dlugosc=0;
    int litera = 0;


    // sprawdzamy czy plik istnieje, został poprawnie otworzony
    if (plik.good() == true)
    {
        cout << "plik jest\n";
        wynik.open("wynik_6_1.txt", ios::out );
        while (getline(plik, linia))
        {// pobieramy z zmiennej plik pierwszą linie i wstawiamy do zmiennej linia
            // liczniki
           
            nowa_linia = "";
         //   cout << linia<<endl;
          //  linia = "XYZ";
            dlugosc = linia.size() - 1;
         //   cout << dlugosc <<" Dlugosc "<<endl;
            for (int i = 0; i <= dlugosc; i++)
            {
                litera=(int)linia[i];
                //BCYKUNCM  k=2
                //B
                // programie weź literę B i podaj mi jej wartość dziesiętną
                // litera=(int)linia[i]
                // litera=(int)linia[1]
                // litera=(int)'B'
                //66=(int)'B'
               // cout << litera << " " << (char)litera << " "; 
                
                if (litera + 3 <= 90)
                {
                    litera = litera + 3;
                    nowa_linia = nowa_linia + (char)litera;
                }
                else
                {
                    // większe od 90

                    litera = (litera + 3) - 90 + 64;
                    nowa_linia = nowa_linia + (char)litera;
                    //
                }
             //   cout << litera << " " << (char)litera << endl;
            }
            cout << nowa_linia << endl;
            wynik << nowa_linia << endl;
           
            //break;
        }

       
        wynik.close();
        plik.close();


       
   
    }
    else
    {
        cout << "pliku brak\n";
    }

}
//
//W pliku dane_6_2.txt zapisano 3 000 szyfrogramów i odpowiadające im klucze
//szyfrujące.W każdym wierszu znajduje się jeden szyfrogram(zaszyfrowane słowo)
//i po pojedynczym znaku odstępu odpowiadający mu klucz(maksymalnie czterocyfrowa
//    liczba).
//    Fragment pliku dane_6_2.txt:
//BCYKUNCM 1718
//YFOGNSKGYW 7580
//WARDA 9334
//
//Napisz program, który odszyfruje słowa zaszyfrowane podanymi kluczami.Wynik zapisz
//w pliku wyniki_6_2.txt: każde odszyfrowane słowo w osobnym wierszu, w porządku
//odpowiadającym kolejności szyfrogramów z pliku z danymi.
//Uwaga :
//    Dla pierwszego szyfrogramu z pliku dane_6_2.txt(BCYKUNCM) wynikiem jest słowo
//    ZAWISLAK.



void zadDrugie()
{

    // zmienna na każdą linie z pliku
    string  slowo="",nowa_linia;
    //uchwyt na plik z danymi i wynikowy oddzielnie gdyż zapisujemy każdą linię po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("dane_6_2.txt", ios::in);
    // plik.open(ścieżka do pliku+nazwa pliku, ios::in | ios::out | ios::app)
    //65-90 czyli 
    //klucz mod 26 
    int k = 0, dlugosc = 0;
    int litera = 0, klucz=0;


    // sprawdzamy czy plik istnieje, został poprawnie otworzony
    if (plik.good() == true)
    {
        cout << "plik jest\n";
        wynik.open("wynik_6_2.txt", ios::out);
       for(int i=0; i<3000; i++)
        {// pobieramy z zmiennej plik pierwszą linie i wstawiamy do zmiennej linia
            // liczniki
         //  getline(plik, nowa_linia);
         //  cout << nowa_linia << endl;
     

            nowa_linia = "";
            plik >> slowo;
            plik >> klucz;

            
            k = klucz %= 26;
            
            for (int i = 0; i <= slowo.size()-1; i++)
            {
                litera = (int)slowo[i];
                // cout << litera << " " << (char)litera << " "; 
                if (litera - k >= 65)
                {
                    litera = litera -k;
                    nowa_linia = nowa_linia + (char)litera;
                }
                else
                {
                    // mniejsze od 65

                    litera = (litera - k) + 90 - 64;
                    nowa_linia = nowa_linia + (char)litera;
                }
                  // cout << litera << " " << (char)litera << endl;
            }
           // cout << slowo << "  a" << klucz << "a " << nowa_linia<< endl;
         //   cout << nowa_linia << endl;
            wynik << nowa_linia << endl;
          //  break;
        }


        wynik.close();
        plik.close();




    }
    else
    {
        cout << "pliku brak\n";
    }

}


//W pliku dane_6_3.txt zapisano 3 000 par słów, po jednej parze w wierszu, oddzielonych
//pojedynczym znakiem odstępu.Drugie słowo w każdej parze jest szyfrogramem pierwszego
//z nieznanym kluczem.
//Niektóre szyfrogramy są błędne, co oznacza, że niektóre litery w słowie zakodowano
//z różnymi przesunięciami.Słowo ma zawsze tę samą długość co odpowiadający
//mu szyfrogram.
//Fragment pliku dane_6_3.txt:
//ZAWISLAK EFBNXQFP
//KRASZEWSKI XENFMRJFXV
//Napisz program, który wyszuka i wypisze te słowa z pliku dane_6_3.txt, które błędnie
//zaszyfrowano.Wynik zapisz w pliku wyniki_6_3.txt : każde słowo w osobnym wierszu,
//w porządku odpowiadającym kolejności tych słów z pliku z danymi.



void zadTrzecie()
{
    // zmienna na każdą linie z pliku
    string  slowo1 = "", slowo2 = "";

    //uchwyt na plik z danymi i wynikowy oddzielnie gdyż zapisujemy każdą linię po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("dane_6_3.txt", ios::in);

    int  k1 = 0, roznica = 0, roznicatmp = 0, litera1 = 0, litera2 = 0;
    int identyczne = 0;
    // sprawdzamy czy plik istnieje, został poprawnie otworzony
    if (plik.good() == true)
    {
        cout << "plik jest\n";
        wynik.open("wynik_6_3.txt", ios::out);
        for (int i = 0; i < 3000; i++)
        {
         


            plik >> slowo1; //pierwsze słowo poprawne
            plik >> slowo2; // jest zaszyfrowane
            k1 = slowo1.size()-1;
            
            //cout << slowo1 << "  " << slowo2 << "  " << k1 << " " << k2<< endl;
          
            for (int j = 0; j <= k1; j++)
            {
                litera1 = (int)slowo1[j];
                litera2 = (int)slowo2[j];
                roznicatmp = litera2 - litera1;
                if (roznicatmp<0)
                {
                    roznicatmp += 26;
                }
              //  cout << roznicatmp << " ";
                if (j == 0)
                {
                    identyczne = 1;
                    roznica=roznicatmp;
                }
                if (roznica != roznicatmp)
                {
                    identyczne = 0;
                }


            }
            if (identyczne==0)
            {
                cout << slowo1 << endl;
                wynik << slowo1 << endl;
            }
         //   cout << endl;
            
        }
        wynik.close();
        plik.close();


    }
    else
    {
        cout << "pliku brak\n";
    }
}
