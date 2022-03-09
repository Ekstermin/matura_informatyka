#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


void zadPierwsze();
void zadDrugie();
void zadTrzecie();
void zadCzwarte();

int main(int argc, char** argv) {
	
										//tablice asocjacyjne
										//argv
										//klucz = wartosc
										//domy
										//
										//dom1=antka
										//dom2=tadka
										//domy[0] -> anrka
    zadPierwsze();
    zadDrugie();
    zadTrzecie();
    zadCzwarte();
//	system("PAUSE");
	return 0;
}


void zadPierwsze()
{
   

    //uchwyt na plik z danymi i wynikowy oddzielnie gdy¿ zapisujemy ka¿d¹ liniê po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("dane.txt", ios::in);

    if (plik.good() == true)
    {
    	int liczba=0, tmpmin=255, tmpmax=0;
        cout << "plik jest\n";
      // int tab[2][3]
    ///   {1, 2, 3}
	 ///  {4, 5, 6}
	   
       
       
       
        
		for(int i=0; i<200; i++)
		{
			for(int j=0; j<320; j++) // 200*320=64 000
			{
					//tab[0][0] - pierwszy obrót
				plik >> liczba;
				if(liczba>tmpmax) //tmpmax = 0 tab[0][0]=16 if(16>0)
					tmpmax=liczba;// tmpmax=16
				if(liczba<tmpmin)////tmpmin = 255 tab[0][0]=16 if (16<255)
					tmpmin=liczba;
			}
		}

 //oddzielny wynikowy
        wynik.open("wynik_6.txt", ios::out );
       cout<< tmpmax<<"  "<<tmpmin<<endl;
       wynik<<"6.1 Max " <<tmpmax<<" Min "<<tmpmin<<endl;
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
   

    //uchwyt na plik z danymi i wynikowy oddzielnie gdy¿ zapisujemy ka¿d¹ liniê po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("dane.txt", ios::in);

    if (plik.good() == true)
    {
    	int tab[200][320];
        cout << "plik jest"<<endl;
       
       //for(int i=0; i<200; i++)
		for(int i=0; i<=199; i++)
		{
			//for(int j=0; j<320; j++)
			for(int j=0; j<=319; j++)
			{//tab[wiersz][kolumna]
				plik >> tab[i][j];				
			}
		}
		
		plik.close();
		
		int k=0;
		int licznik=0;
		int symetria=1; //flaga - znacznik - kontrolka 
		
		for(int i=0; i<200; i++)
		{	
			symetria=1;
			for(int j=0; j<=159; j++)
			{
			//	k=320-1-j;
				if(tab[i][j] != tab[i][319-j])	
				{
					//cout<<tab[i][j]<< "   -   "<<tab[i][k]<<endl;
					symetria=0;
				}
			//	cout<<j<<endl;
			}
		//	break;
			if(symetria==0)	
			{
				licznik++;
			}
					
		}
		// and   1-  1 and 1 |      0 -  0 and 0 | 0 and 1| 1 and 0
		// or    0- 0 or 0   1- pozosta³e

	cout<< "usunac = "<< licznik<<endl;

        wynik.open("wynik_6.txt", ios::app );
        wynik<< "6.2 usunac = "<< licznik<<endl;
        wynik.close();
        

    }
    else
    {
        cout << "pliku brak\n";
    }

}



void zadTrzecie()
{
   

    //uchwyt na plik z danymi i wynikowy oddzielnie gdy¿ zapisujemy ka¿d¹ liniê po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    plik.open("dane.txt", ios::in);

    if (plik.good() == true)
    {
    	int tab[200][320];
        cout << "plik jest"<<endl;
       
       //for(int i=0; i<200; i++)
		for(int i=0; i<=199; i++)
		{
			//for(int j=0; j<320; j++)
			for(int j=0; j<=319; j++)
			{
				plik >> tab[i][j];				
			}
		}
		
		plik.close();

		int licznik=0, roznica=0, kontrast=0;
		for(int i=0; i<200; i++)
		{	
			for(int j=0; j<320; j++)
			{
				//flaga czy kontrastuje
				kontrast=0;
				
				//prawy
				if(j<319)
				{
				roznica=tab[i][j]-tab[i][j+1];
				if (roznica>128 or roznica<-128) //and &&
					kontrast=1;
				}
				
				//lewy
				if(j>0)
				{
				roznica=tab[i][j]-tab[i][j-1];
				if (roznica>128 or roznica<-128)
					kontrast=1;
				}
				
				//dol
				if(i<199)
				{
				roznica=tab[i][j]-tab[i+1][j];
				if (roznica>128 or roznica<-128)
					kontrast=1;
				}
				
				//gora
				if(i>0)
				{
				roznica=tab[i][j]-tab[i-1][j];
				if (roznica>128 or roznica<-128)
					kontrast=1;
				}
								
				if(kontrast==1)	licznik++;	
			}

		}
		
cout<< licznik;


        wynik.open("wynik_6.txt", ios::app );
        wynik<< "6.3 kontrastujacych pikseli jest = "<< licznik<<endl;
        wynik.close();
        

    }
    else
    {
        cout << "pliku brak\n";
    }

}



void zadCzwarte()
{
   

    //uchwyt na plik z danymi i wynikowy oddzielnie gdy¿ zapisujemy ka¿d¹ liniê po szyfrowaniu
    fstream plik, wynik;

    //otwieramy plik lub tworzymy do niego uchwyt
    //plik.open("przyklad.txt", ios::in);
	plik.open("dane.txt", ios::in);

    if (plik.good() == true)
    {
    	int tab[200][320];
        cout << "plik jest"<<endl;
       
       //for(int i=0; i<200; i++)
		for(int i=0; i<=199; i++)
		{
			//for(int j=0; j<320; j++)
			for(int j=0; j<=319; j++)
			{
				plik >> tab[i][j];				
			}
		}
		
		plik.close();
		// tmp = licznik dla lini; liczba = wartoœæ z tablicy; linia = aktualnie najd³ó¿sza linia
		int tmp=1, liczba=0, linia=1;
		for(int i=0; i<320; i++)
		{	
			for(int j=0; j<200; j++)
			{
				//inicjujemy jak zaczynamy ka¿d¹ kolumne
				if(j==0)
				{
					//tmp ustawiamy na jeden bo ka¿da liczba stwo¿y linie jedno elementow¹
					tmp=1;
					//pierwsza liczba z kolumny
					liczba= tab[j][i];
					
				}
				else
				{
					//porównuje sprawdza kolejn¹ liczbê czy jest taka sama jak ostatnia
					if (tab[j][i] == liczba)
					{
						//jeœli tak zwiêkszamy liucznik d³ugoœci lini
						tmp++;	
					}
					else
					{
						// sprawdzamy czy tymczasowy licznik jest wiêkszy od ostatniego wyniku jeœli tak przyp[isujemy nowy wynik
						if(tmp>linia) linia=tmp; // 2
						//zerójemy nowy licznik, przypisujemy now¹ wartoœæ dla liczby
						liczba =tab[j][i];
						tmp=1;
					}
				}
		
			}

		}
		cout<<linia;
		



        wynik.open("wynik_6.txt", ios::app );
        wynik<< "6.4 naj d³ linia = "<< linia<<endl;
        wynik.close();
        

    }
    else
    {
        cout << "pliku brak\n";
    }

}
