/******************************************************************************
**				ÖĞRENCİ ADI.................:Serhat BİLAL
**				ÖĞRENCİ NUMARASI............:B191210309
**				DERS GRUBU..................:1A
******************************************************************************/

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <ctime>

using namespace std;

// yardımcı fonksiyon(Ekranda istediğimiz koordinatta karakter çıkarmak için)
void koordinatAta(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Tasarlanan sahne yapısı 
struct Sahne
{
	int yukseklik;
	int genislik;
	char karakterSahne;
};

//Tasarlanan LSekli yapısı 
struct LSekli
{
	int boyut;
	int x;
	int y;
	char karakterSekil;
};

void koordinatAta(int, int);
LSekli lSekliAsagiGotur(LSekli);
Sahne sahneOlustur();
void sahneCiz(Sahne);
LSekli lSekliOlustur();
void lSekliCiz(LSekli);


Sahne sahneOlustur()
{
	Sahne sahne;
	char karakterDizisi[5] = { '*','#','$','+','@' };

	// rastgele 0-4 arası değer
	int degerAta = rand() % 5;

	// rastgele 20-30 arası değer
	sahne.yukseklik = rand() % 11 + 20;

	// rastgele 30,40,50 değerlerinden biri
	sahne.genislik = (rand() % 3 + 3) * 10;

	sahne.karakterSahne = karakterDizisi[degerAta];
	return sahne;
}


void sahneCiz(Sahne sahne)
{
	// genişliği kadar karakter girilmesi için kullandığım döngü
	for (int i = 0; i < sahne.genislik; i++)
	{
		koordinatAta(i, 0);
		cout << sahne.karakterSahne;
		koordinatAta(i, sahne.yukseklik - 1);
		cout << sahne.karakterSahne;
	}

	// yüksekliği kadar karakter girilmesi için
	for (int i = 0; i < sahne.yukseklik; i++)
	{
		koordinatAta(0, i);
		cout << sahne.karakterSahne;
		koordinatAta(sahne.genislik - 1, i);
		cout << sahne.karakterSahne;
	}
}


LSekli lSekliOlustur()
{

	LSekli lsekli;
	char lsekilKarakterDizisi[5] = { '*','#','$','+','@' };

	// rastgele 0-4 arası değer
	int degerAta = rand() % 5;

	// rastgele 2-7 arası değer
	lsekli.boyut = rand() % 6 + 2;

	lsekli.y = 3;
	// rastgele 5-25 arası değer
	lsekli.x = rand() % 21 + 5;

	lsekli.karakterSekil = lsekilKarakterDizisi[degerAta];

	return lsekli;
}


void lSekliCiz(LSekli L)
{
	int boyut = 2 * L.boyut;

	for (int i = 0; i < 1 + boyut; i++)
	{
		koordinatAta(L.x, L.y + i);
		cout << L.karakterSekil;
		if (i < L.boyut) {
			koordinatAta(L.x + L.boyut - 1, L.y + i);
			cout << L.karakterSekil;
		}

		if (i < boyut && L.boyut < i)
		{
			koordinatAta(L.x + boyut - 1, L.y + i);
			cout << L.karakterSekil;
		}
	}

	// L nin karakteri yatay olarak giriliyor
	for (int i = 0; i < boyut; i++)
	{
		if (i < boyut / 2)
		{
			koordinatAta(L.x + i, L.y);
			cout << L.karakterSekil;
		}
		if (i < L.boyut + 1)
		{
			koordinatAta(L.x + L.boyut - 1 + i, L.y + L.boyut);
			cout << L.karakterSekil;
		}
		koordinatAta(L.x + i, L.y + boyut);
		cout << L.karakterSekil;
	}
}

// L alt satira indiriliyor.
LSekli lSekliAsagiGotur(LSekli L)
{
	L.y++;
	return L;
}



int main()
{

	srand(time(0));
	Sahne sahne = sahneOlustur();
	LSekli sekil = lSekliOlustur();

	// Döngü 
	while (true)
	{
		system("cls");
		sahneCiz(sahne);
		lSekliCiz(sekil);

		sekil = lSekliAsagiGotur(sekil);

		if (sahne.yukseklik == sekil.y + 1 + 2 * sekil.boyut)
		{
			sekil = lSekliOlustur();
		}
		Sleep(100);
	}
}




