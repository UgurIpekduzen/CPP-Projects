// ConsoleApplication39.cpp : Defines the entry point for the console application.
//
#include "Header.h"
#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "iomanip"
#include "string"
#include <stdlib.h>
#include <locale>
#include <clocale>
using namespace std;

string SoruSec()
{
	srand(time(NULL));
	int sayi = (rand() % 1922) + 343;
	return to_string(sayi);
}

void main()
{
	//ifstream Sorular("question.csv");
	ifstream Sorular;
	Sorular.open("question.csv");
	string soruNumarasi;	string seviye;		int oyuncuSeviyesi = 1;	
	string soru;		char sik1;
	string sec1;		char sik2;				string soruTamamı;
	string sec2;		char sik3;
	string sec3;		char sik4;
	string sec4;		
	string ynt;
	string cvp;
	bool yanlisYaptiMi = false;

	setlocale(LC_ALL, "tr_TR.utf8"); // needed if C++ I/O goes through C I/O

	for (int sayac = 1; sayac <= 12; sayac++) //12 soru oldugu için her bir soru içinde yapılacak bir dongu kuruyorum
	{
		do {
			getline(Sorular, soruNumarasi, ',');
			getline(Sorular, seviye, ',');

			if (to_string(oyuncuSeviyesi) == seviye)
			{
			//Sorular >> soruNumarası >> seviye >> soru >> sec1 >> sec2 >> sec3 >> sec4 >> cvp;
			// cout << soruNumarası<<" "<< seviye <<" "<< soru <<endl<< " " << sec1<<" "<< sec2<<" "<< sec3<<" "<< sec4<<endl;
			//	getline(Sorular, soruNumarası, ',');
			//	getline(Sorular, seviye, ',');
			//	getline(Sorular, soru, ',');
			//	getline(Sorular, sec1, ',');
			//	getline(Sorular, sec2, ',');
			//  getline(Sorular, sec3, ',');
			//  getline(Sorular, sec4, ',');
			//	getline(Sorular, cvp, ',');
				getline(Sorular, soru, ',');
				getline(Sorular, sec1, ',');
				getline(Sorular, sec2, ',');
				getline(Sorular, sec3, ',');
				getline(Sorular, sec4, ',');
				cout << sayac << ") " << soru << endl << "A) " << sec1 << endl << "B) " << sec2 << endl << "C) " << sec3 << endl << "D) " << sec4 << endl;
			
			}
		} 
		while (to_string(oyuncuSeviyesi) != seviye);

		/*         // yazdırmak için gerek kalmıycak galiba cout ve degişkenlerle yazarım
		while (Sorular >> soruNumarası >> seviye >> soru >> sec1 >> sec2 >> sec3 >> sec4 >> cvp)
		{
			cout << soru << endl << "A) " << sec1 << endl << "B) " << sec2 << endl << "C) " << sec3 << endl << "D) " << sec4;
		}*/ 

		cout << "Cevabinizi giriniz: ";
		cin >> ynt;
		getline(Sorular, cvp, ',');
		if (cvp[0] == (char)toupper((int)ynt[0]))
		{
			oyuncuSeviyesi++;
			system("cls");
			//SonrakiSoru(oyuncuSeviyesi);
		}
		else
			break;//OyunuKaybettir()
	}

	system("cls");
	cout << "Oyun Bitti! Kaybettin len emq." << " Dogru yanitlanan soru sayisi: " << oyuncuSeviyesi << endl;
	
}


