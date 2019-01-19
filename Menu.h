//Plik zawiera klasê nadrzêdn¹ - Menu.

class Menu {
	protected:
		
		ItemList* il; //Menu zawiera listê "przedmiotów", a w³aœciwie opcji.
		string menuText; //Tekst menu.
		bool isRunning; //Czy menu jest aktywne?
		
		virtual void execute() = 0; //Wykonanie opcji menu. Dla ka¿dego menu potomnego ta funkcja bêdzie siê ró¿niæ, dlatego jest wirtualna.
		
		void refreshScreen() { //Metoda odpowiedzialna za wyœwietlanie i odœwie¿anie wygl¹du menu.
			system("cls");
			cout << " " << menuText << endl << endl; //Wypisanie tekstu menu, podanego jako parametr konstruktora.
			
			/* Wypisanie wszystkich pozycji w menu i zaznaczenie aktualnie aktywnego elementu (cil) za pomoc¹ gwiazdki.
				Lista najpierw nale¿y zapamiêtaæ bie¿¹cy element w osobnej zmiennej.
				Nastêpnie przejœæ na pocz¹tek listy i zacz¹æ j¹ wypisywaæ od pocz¹tku w pêtli (z u¿yciem kolejnej zmiennej pomocniczej - temp).
				Jeœli w danym przebiegu dany element odpowiada elementowi bie¿¹cemu (cil), to piszemy gwiazdkê.
				Jeœli nie odpowiada, to spacje.
				Wypisujemy tak ca³¹ listê, a nastêpnie cofamy zmiany (il = cil.*/
			
			ItemList* cil = il; //Current ItemList - obecna pozycja na liscie
			items->seekBegin(il);
			ItemList* temp = il;
			do {
				if(il == cil) cout << " * " << il->item->name << endl;
				else cout << "   "  << il->item->name << endl;
				items->nextItem(il);
			} while(il != temp);
			
			il = cil;
			
			cout << endl;
		}
			
	public:
		
		Menu(ItemList* & il, string & menuText) {
			this->il = il;
			this->menuText = menuText;
			this->isRunning = true;
			
			refreshScreen(); //Wyœwietlanie Menu na ekranie.
		}
		
		//Metoda umo¿liwiaj¹ca wybór opcji w menu. Dzia³a w nieskoñczonej pêtli, która mo¿e jednak zostaæ przerwana. Domyœlnie
		//ustawiona jest w nastêpuj¹cy sposób: S - go down, W - go up, k - action
		//Lista opcji wyœwietlana jest od góry do do³u (na górze pierwszy element na liœcie, poni¿ej nastêpne), dlatego nastêpne elementy
		//na liœcie znajduj¹ siê poni¿ej (klawisz S). Analogicznie poprzednie elementy (klawisz W).
		void changeOptions() {
			char c;
			while(isRunning) {
				c = _getch(); //Czekaj na podanie znaku.
		
				switch(c) {  //Za ka¿d¹ zmian¹ opcji, odœwie¿a siê ekran.
					case 's': items->nextItem(il); refreshScreen(); break; //scroll DOWN
					case 'w': items->prevItem(il); refreshScreen(); break; //scroll UP
					case 'k': execute(); refreshScreen(); break; //Podejmij akcjê (execute), a po zakoñczeniu akcji, odœwie¿ ekran.
				}
			}
		}
		
		//Metoda umo¿liwiaj¹ca ponown¹ aktywacjê danego menu.
		void makeRunning() {
			refreshScreen();
			isRunning = true;
		}
};
