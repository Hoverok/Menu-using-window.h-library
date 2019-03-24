#include <windows.h>
#include <iostream>
#include <iomanip>
#include "Langai.h"
using namespace std;
namespace lang {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	/*** INDIKATORIUS ***/
	Indikatorius::Indikatorius() // nesikeicia, todel paliksiu konskustruktoryje
	{
		f_t_spalva = 46;
		vietaX = 4;
		vietaY = 1;
		ind_koord = { vietaX,vietaY };
		ilgis = 32;
	}

	void Indikatorius::ind_spalvos() {   // set spalva indikatoriaus eilutei
		SetConsoleTextAttribute(console, f_t_spalva);
	}

	void Indikatorius::fill_print_ind() {
		SetConsoleCursorPosition(console, ind_koord); // isveda i ekrana pranesima apie indikatoriu
		cout << "Select a number option from menu";
	}

	void Indikatorius::pasirinkimas() { // uz lango ribu bus matyt koks punktas yra ivedamas
		SetConsoleTextAttribute(console, 15); //default spalva
		ind_koord = { 9,20 }; // kita eilute prasides 2 tarpais zemiau uz esama, X tas pats
		SetConsoleCursorPosition(console, ind_koord);
		cout << "Choice nr: ";
	}
	/*** INDIKATORIAUS PABAIGA ***/
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	/*** Langas, jo ir remelio briezymas***/
	Langas::Langas()  // 0- be remelio, 1- 1 linija remelis, 2- 2 liniju remelis
	{

	}



	void Langas::Langas_parametrai() {  // nesikeis bet reikia reset
		xkoord = 5;    // kiek tarpu is kaires iki lango
		ykoord = 0;    // kol kas neturi reiksmes programai
		koordtop = 3;  // kiek tarpu is virsaus iki lango
		koord1 = { xkoord,ykoord };

	}


	void Langas::set_change_spalva(short a) {  // kokia bus pagrindine lango spalva
		spalva = a;
		SetConsoleTextAttribute(console, spalva);
	}

	void Langas::piesti_langa() {

		xkoord = 30;   //kiek columns bus lange
		ykoord = 15;   //kiek rows bus lange

		for (int y = 0; y < ykoord; y++)  // ykoord rows
		{
			koord1.Y = koordtop + y;       //pradeda piesti nuo koordtop, ykoord kartu(rows)
			SetConsoleCursorPosition(console, koord1);
			cout << std::setw(xkoord) << ' ';  // kiekviena row fillina su xkoord kiekiu tarpu
		}
	}

	//Savybes- neturi outside kintamuju, viska inicializuoja savyje
	//skaiciu paaiskinimas: 30 ant 15 yra lenteles mastas
	void Langas::piesti_remeli(short b) { // kai b lygu 0-be rem, 1- vieng rem, 2- dvyg rem
		unsigned char tl, tr, bl, br, hor, diag;            //tl- top left kampas, br- bottom right, hor- horizantali linija
		switch (b) {
		case 0:     // be relemelio
			tl = ' ', tr = ' ', bl = ' ', br = ' ', hor = ' ', diag = ' ';     // visi tusti
			SetConsoleTextAttribute(console, 15); // default spalva
			break;
		case 1:     //vienguba linija
			tl = 218; tr = 191; bl = 192, br = 217, hor = 196, diag = 179;  // viengubos linijos ascii simb numeriai
			SetConsoleTextAttribute(console, 249); // remelis tures kita spalva
			break;
		case 2:
			tl = 201; tr = 187; bl = 200, br = 188, hor = 205, diag = 186;  // dvyguba linija
			SetConsoleTextAttribute(console, 249); // remelis tures kita spalva
			break;
		default:
			tl = '#'; tr = '#'; bl = '#', br = '#', hor = '#', diag = '#';  // netaisyklingas parametras
			break;
		}

		COORD tempkoord2;         // kad piesti 2 linijas iskart o ne po 1             
		COORD tempkoord = { 4,2 }; //top left kampas
		SetConsoleCursorPosition(console, tempkoord);
		cout << tl;

		tempkoord = { 5 + 30,2 }; //top right kampas
		SetConsoleCursorPosition(console, tempkoord);
		cout << tr;

		tempkoord = { 5 + 30, 3 + 15 }; //bottom right kampas
		SetConsoleCursorPosition(console, tempkoord);
		cout << br;

		tempkoord = { 4, 3 + 15 }; //bottom left kampas
		SetConsoleCursorPosition(console, tempkoord);
		cout << bl;

		//horizantalios linijos
		tempkoord = { 5,2 };   // top left kampas.X+1
		tempkoord2 = { 5,3 + 15 }; // bottom left kampas.X+1
		SetConsoleCursorPosition(console, tempkoord); // nuo top left iki top right horiz linija
		for (int i = 0; i < 30; i++) cout << hor;
		SetConsoleCursorPosition(console, tempkoord2); // nuo bottom left iki bottom right horiz linija
		for (int i = 0; i < 30; i++) cout << hor;

		//vertikalios linijos
		tempkoord = { 4,3 }; // top left kampas.Y+1
		tempkoord2 = { 5 + 30, 3 }; //top right kampas.Y+1
		for (int i = 0; i < 15; ++i) {
			tempkoord.Y = koordtop + i;   // koordtop- kiek tarpu iki lango
			tempkoord2.Y = koordtop + i;  // braizys iskart 2
			SetConsoleCursorPosition(console, tempkoord);  // braizom vert kaire linija
			cout << diag;
			SetConsoleCursorPosition(console, tempkoord2);  // braizom vert kaire linija
			cout << diag;
		}
	}
	/*** Langas pabaiga ***/
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	/*** Klase Tekstas ***/

	Tekstas::Tekstas()
	{

	}
	void Tekstas::Tekstas_parametrai(short spalva) {
		textkoordX = 6; // 6 tarpai is kair  
		textkoordY = 5; // 5 tarpai is virs
		textK = { textkoordX,textkoordY }; // ivedam pradines koordinates
		SetConsoleTextAttribute(console, spalva);
	}

	// currently active punktas bus kitos spalvos
	// siunciam is menu skaiciu
	void Tekstas::pildom_teksta() {   // isveda pasirinkimus i konsole

		SetConsoleCursorPosition(console, textK);
		cout << "1. Blue with no frame";
		textK.Y += 2; // kita eilute prasides 2 tarpais zemiau uz esama, X tas pats
		SetConsoleCursorPosition(console, textK);
		cout << "2. Blue with single frame";
		textK.Y += 2; // kita eilute prasides 2 tarpais zemiau uz esama, X tas pats
		SetConsoleCursorPosition(console, textK);
		cout << "3. Blue with double frame";
		textK.Y += 2; // kita eilute prasides 2 tarpais zemiau uz esama, X tas pats
		SetConsoleCursorPosition(console, textK);
		cout << "4. Red with no frame";
		textK.Y += 2; // kita eilute prasides 2 tarpais zemiau uz esama, X tas pats
		SetConsoleCursorPosition(console, textK);
		cout << "5. Red with single frame";
		textK.Y += 2; // kita eilute prasides 2 tarpais zemiau uz esama, X tas pats
		SetConsoleCursorPosition(console, textK);
		cout << "6. Red with double frame";

	}

	//principas - pakeicia spalva ir isveda i consoles langa TIK 1 pranesima (pakeisdama sena)
	void Tekstas::chosen_tekstas(short x) {
		SetConsoleTextAttribute(console, 95); //kokia spalva bus uzrasytas siuo metu pasirinktas punktas
		textK = { 6,5 }; //resetina 1 punkto koordinates

		SetConsoleCursorPosition(console, textK);
		if (x == 1) cout << "1. Blue with no frame";
		textK.Y += 2; // kita eilute prasides 2 tarpais zemiau uz esama, X tas pats
		SetConsoleCursorPosition(console, textK);
		if (x == 2) cout << "2. Blue with single frame";
		textK.Y += 2; // kita eilute prasides 2 tarpais zemiau uz esama, X tas pats
		SetConsoleCursorPosition(console, textK);
		if (x == 3) cout << "3. Blue with double frame";
		textK.Y += 2; // kita eilute prasides 2 tarpais zemiau uz esama, X tas pats
		SetConsoleCursorPosition(console, textK);
		if (x == 4) cout << "4. Red with no frame";
		textK.Y += 2; // kita eilute prasides 2 tarpais zemiau uz esama, X tas pats
		SetConsoleCursorPosition(console, textK);
		if (x == 5) cout << "5. Red with single frame";
		textK.Y += 2; // kita eilute prasides 2 tarpais zemiau uz esama, X tas pats
		SetConsoleCursorPosition(console, textK);
		if (x == 6) cout << "6. Red with double frame";
		SetConsoleTextAttribute(console, 15);  //reset spalva
	}

	/*** Tekstas pabaiga ***/
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	/*** Klase Menu ***/

	Menu::Menu()  //konstruktorius
	{    //noriu kad iskart rodytu 1 punkta (blue be rem)
		choice = 1; //pabreztas 1 pasirinkimas
		spalv = 159; // melyna spalva
		rem = 0;    // be remelio

		Langas_parametrai(); // resetina piesamo lango parametrus
		set_change_spalva(spalv);   //turi pakeisti lenteles spalva
		piesti_langa();    //piesa langa

		piesti_remeli(rem);    // siuncia koks remelis bus

		Tekstas_parametrai(spalv);      // resetina kur rasyt pirma linija
		pildom_teksta();           // raso teksta
		chosen_tekstas(choice);

		pasirinkimas_ko = { 22,20 };
		SetConsoleCursorPosition(console, pasirinkimas_ko);    // kur bus matomas skaicius kuri ives i menu

	}
	void Menu::setmenu(short x) {  // interpretuoja pasirinkima is menu
		choice = x;

		switch (choice) {    //nustatom spalva      
		case 1: case 2: case 3:
			spalv = 159;        //pirmi 3 punktai spalva melina
								//set_change_spalva(spalv);  // nustatom lango spalva
			break;
		case 4: case 5: case 6:
			spalv = 206;
			break;
		default:
			spalv = 15;
			break;
		}
		switch (choice) {  // koks remelis bus
		case 1: case 4:
			rem = 0;   //nera
			break;
		case 2: case 5:
			rem = 1;     // viengubas
			break;
		case 3: case 6:
			rem = 2;      // dvygubas
			break;
		default:
			rem = 3; // tokio ner
			break;
		}
	}

	void Menu::menu_draw_lang() { // resetina parametrus ir piesa langa
		Langas_parametrai(); // resetina piesamo lango parametrus
		set_change_spalva(spalv);   //turi pakeisti lenteles spalva
		piesti_langa();    //piesa langa
	}

	void Menu::menu_draw_rem() { //piesa remeli
		piesti_remeli(rem);    // siuncia koks remelis bus
	}

	void Menu::menu_type_text() {
		Tekstas_parametrai(spalv);      // resetina kur rasyt pirma linija
		pildom_teksta();           // raso teksta
		chosen_tekstas(choice);   //principas - pakeicia spalva ir isveda i consoles langa TIK 1 pranesima (pakeisdama sena)

	}
	void Menu::menu_reset() {
		SetConsoleTextAttribute(console, 15);  //reset spalva
		SetConsoleCursorPosition(console, pasirinkimas_ko);    // kur bus matomas skaicius kuri ives i menu
	}


}
