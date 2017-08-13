						//POP 2014-12-08 projekt 1 Biernat Pawel EIT  149152      Dev-C++ 5.4.0
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


const int	n_max=20;
int wiersz, kolumna;
char tablica[n_max][n_max];
int i,j;
char sciana;
char bohater;
char klocek;
char wolne_pole;
char wyjscie;
bool ukonczenie;
        
        
void znalezienie_pozycji_gracza()	// szukamy polozenia naszego bohatera w tablicy na poczatku gry i po kazdym ruchu
{

	bool stop=0;

	for(int wiersz=0; wiersz<20; ++wiersz)
		{
      	for(int kolumna=0; kolumna<20; ++kolumna)
        	{
    			if (tablica[wiersz][kolumna]=='&')
					{
						i=wiersz;        		//przypisujemy wspolrzedne do zmiennych ruchu
						j=kolumna;
						
						
						break;
						stop=1;
						};

        	}	
                if(stop==1){break;}
                
		}
}	 
        	       
void wyswietlanie_stanu_gry()
{								//aktualizacja stanu gry po kazdym ruchu
        	
	system("cls");
        
	for(int i=0; i<20; ++i)
    	{
    		for(int j=0; j<20; ++j)
        		{
             	cout<<tablica[i][j];
       			}
    	}	
            
}
        
void ladowanie_planszy()
{
	cout<<"Sterowanie: a-lewo, d-prawo, w-gora, s-dol, r-reset, m-menu. Aby wyjsc wybierz x."<< endl;
	cout<<"Wybierz poziom od 1 do 3: ";
	int numer;
	cin >> numer;
            						//wybieramy plansze i wczytujemy z pliku txt
	if(numer==1)
	{
		fstream plik("PLANSZA1.txt");
				
	
		for(int i=0; i<20; ++i)
		{
	    	for(int j=0; j<20; ++j)
	    	{
	        	tablica[i][j]=plik.get();
	
	    	}
		}
		znalezienie_pozycji_gracza();
		wyswietlanie_stanu_gry();
	
}

	else if(numer==2)
	{
		fstream plik("PLANSZA2.txt");
				
	
		for(int i=0; i<20; ++i)
		{
	    	for(int j=0; j<20; ++j)
	    	{
	        	tablica[i][j]=plik.get();
	
	    	}
		}
		znalezienie_pozycji_gracza();
		wyswietlanie_stanu_gry();
				
	}

	else if(numer==3)
	{
			
		fstream plik("PLANSZA3.txt");
				
	
		for(int i=0; i<20; ++i)
		{
		    for(int j=0; j<20; ++j)
	    	{
	        	tablica[i][j]=plik.get();
	
	    	}
		}
		znalezienie_pozycji_gracza();
		wyswietlanie_stanu_gry();
	}	
		else 
		{	
			cout<<"podales zla wartosc!"<<endl; 
			ladowanie_planszy();
		}
}	
                 
void ruch_dol()			//funkcja ruchu w dol
{
	znalezienie_pozycji_gracza();

	if(tablica[i+1][j] == wolne_pole)		// !!!adresy tablicy rosn¹ w dol!!!
	{
		tablica[i+1][j] = bohater;
		tablica[i][j] = wolne_pole;
	}

	else if(tablica[i+1][j] == klocek && tablica[i+2][j]==wolne_pole)
	{
		tablica[i+2][j]=klocek;
		tablica[i+1][j]=bohater;
		tablica[i][j]=wolne_pole;
	}

	else if(tablica[i+1][j] == wyjscie)
	{
		tablica[i+1][j] = bohater;
		tablica[i][j] = wolne_pole;
		ukonczenie = 1;
	}
	znalezienie_pozycji_gracza();
}
        
void ruch_gora()			//funkcja ruchu w gore
{
    znalezienie_pozycji_gracza();
           
	if(tablica[i-1][j]==wolne_pole)
	{
		tablica[i-1][j]=bohater;
		tablica[i][j]=wolne_pole;
	}
            
	else if(tablica[i-1][j]==klocek && tablica[i-2][j]==wolne_pole)
	{
		tablica[i-2][j]=klocek;
		tablica[i-1][j]=bohater;
		tablica[i][j]=wolne_pole;
	}
           
	else if(tablica[i-1][j]==wyjscie)
	{
		tablica[i-1][j]=bohater;
		tablica[i][j]=wolne_pole;
		ukonczenie=1;
	}
		znalezienie_pozycji_gracza();
}
        
void ruch_prawo()			// funkcja ruchu w prawo
{
          
	znalezienie_pozycji_gracza();
	if(tablica[i][j+1]==wolne_pole)
	{
		tablica[i][j+1]=bohater;
		tablica[i][j]=wolne_pole;
	}
            
	else if(tablica[i][j+1]==klocek && tablica[i][j+2]==wolne_pole)
	{
		tablica[i][j+2]=klocek;
		tablica[i][j+1]=bohater;
		tablica[i][j]=wolne_pole;
	}
    else if(tablica[i][j+1]==wyjscie)
	{	
		tablica[i][j+1]=bohater;
		tablica[i][j]=wolne_pole;
		ukonczenie=1;
	};
	znalezienie_pozycji_gracza();
}
       
void ruch_lewo()			// funkcja ruchu w lewo
{
	znalezienie_pozycji_gracza();
            
	if(tablica[i][j-1]==wolne_pole)
	{
		tablica[i][j-1]=bohater;
		tablica[i][j]=wolne_pole;	
	}
            
	else if(tablica[i][j-1]==klocek && tablica[i][j-2]==wolne_pole)
	{
		tablica[i][j-2]=klocek;
		tablica[i][j-1]=bohater;
		tablica[i][j]=wolne_pole;	
	}
    else if(tablica[i][j-1]==wyjscie)
	{
		tablica[i][j-1]=bohater;
		tablica[i][j]=wolne_pole;
		ukonczenie=1;
	};
	znalezienie_pozycji_gracza();
}
        
        
void reset()		//gdy nam cos nie wyjdzie, mozemy zaczac od nowa ;)
{
    system("cls");
    ladowanie_planszy();
}
        
    
void rozgrywka()				// najwazniejsza funkcja
{
	char key;
	while(ukonczenie==0)
	{
		cin>>key;
		switch(key)
		{
		    case 'w':
		    {
		        znalezienie_pozycji_gracza();
		        ruch_gora();
		        wyswietlanie_stanu_gry();
		        break;
		    }
		     case 's':
		    {
		        ruch_dol();
		        wyswietlanie_stanu_gry();
		        break;
		    }
		    case 'a':
		    {
		        ruch_lewo();
		        wyswietlanie_stanu_gry();
		        break;
		    }
		    case 'd':
		    {
		        ruch_prawo();
		        wyswietlanie_stanu_gry();
		        break;
		    }
		    case 'r':
		    {
		        reset();
		        break;
		    }
		    case 'x':
		    {
		        ukonczenie = true;
		        break;
		    }
		    case 'm':
		        cout<<"a-lewo, d-prawo, w-gora, s-dol, r-reset, m-menu"<< endl;
		        break;
		}
	}
}
       
void ustawienia()		//zalozenia poczatkowe gry
{
    ukonczenie = false;
    sciana='X';
    bohater='&';
    klocek='#';
    wolne_pole=' ';
    wyjscie='O';
}
/**************************************************************************************************************/
int main()
{
ustawienia();
ladowanie_planszy();
rozgrywka();
cerr << "Koniec gry";
return 0;
}
