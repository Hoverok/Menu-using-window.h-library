//the purpose of this project was to create a c++ namespace for a basic menu
//namespace lang contains 4 classes
//class Indikatorius is responsible for the line above the menu
//class Langas is responsible for drawing the menu window and its frame
//class Tekstas is a derived from Langas, it's responsible for displaying text in the menu window
//class Menu is derived from Tekstas, it's responsible for reading user input and calling functions from its base class depending on the input
#include <iostream>
#include <windows.h>  
#include <bitset>     
#include <iomanip>
#include <string>
#include "Langai.h"

using namespace std;

int main() {
	int menu_choice;

	lang::Indikatorius indik; //sukuriamas objektas indik classes indikatorius
	indik.ind_spalvos(); // nustato indikatoriaus spalva
	indik.fill_print_ind(); // isveda indikatoriaus pranesima i console
	indik.pasirinkimas();  // "Pasirinkimas" outside of lango



	lang::Menu MenuObj;         // construktorius isvesti kur nors zemyn MENU:_
	while (cin >> menu_choice) {
		MenuObj.setmenu(menu_choice);  // skaito parametra
		MenuObj.menu_draw_lang();  // resetina parametrus ir piesa langa
		MenuObj.menu_draw_rem(); //piesa remeli
		MenuObj.menu_type_text(); //isveda teksta
		MenuObj.menu_reset();  //resetina pasirinkimo kursoriu
		cin.ignore();
	}
}