#ifndef LANGAI_H
#define LANGAI_H
#include <windows.h>
#include <iostream>
#include <iomanip>

namespace lang {
	/***NAUJA KLASE***/
	class Indikatorius
	{
	private:
		short f_t_spalva, vietaX, vietaY, ilgis;  //parametrai reikalingi sukurti kitos spalvos linija
		COORD ind_koord;

	public:
		Indikatorius();    //tiesiog inicializuojami private parametrai
		void ind_spalvos(); //nustato spalva
		void fill_print_ind(); // isveda indikatoriaus zinute i isrenkta vieta
		void pasirinkimas();
	};
	/***NAUJA KLASE***/
	class Langas
	{
	private:
		short xkoord, ykoord, koordtop;
		COORD koord1;
		short spalva;
	public:
		Langas(); //short parametro variantai: 0- be remelio, 1- 1 linija, 2- 2 linijas

		void Langas_parametrai();
		void set_change_spalva(short); //gaunas spalva kaip shorta ir iskart ja keicia
		void piesti_langa(); //piesa langa 
		void piesti_remeli(short); // pesa remeli, 0-be rem, 1-vieng, 2- dvygub
	};
	/***NAUJA KLASE***/
	class Tekstas : public Langas { // Tekstas pavelda is Langas
	private:
		short textkoordX, textkoordY, rinktas_spalva;
		COORD textK; // kur pradet rasyt teksta
	public:
		Tekstas();
		void Tekstas_parametrai(short); //kur bus rasomas ir kokia spalva textas
		void pildom_teksta();     // isveda pasirinkimo teksta i consoles langa
		void chosen_tekstas(short); //pabrezia koks punktas dabar isrinktas
	};
	/***NAUJA KLASE***/
	class Menu : public Tekstas {
	private:
		short choice, rem, spalv;
		COORD pasirinkimas_ko; // kur bus matomas pasirinkimas
	public:
		Menu();
		void setmenu(short);
		void menu_draw_lang();
		void menu_draw_rem();
		void menu_type_text();
		void menu_reset();
	};



}  // namespace lang ends
#endif		