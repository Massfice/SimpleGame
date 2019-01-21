//Plik zawiera klas� nadrz�dn� - Menu.

class Menu {
	protected:
		
		ItemList* il; //Menu zawiera list� "przedmiot�w", a w�a�ciwie opcji.
		string menuText; //Tekst menu.
		string emptyMenuText; //Tekst, kt�ry zostanie wy�wietlony, je�li w Menu nie ma �adnych opcji.
		bool isRunning; //Czy menu jest aktywne?
		
		virtual void execute() = 0; //Wykonanie opcji menu. Dla ka�dego menu potomnego ta funkcja b�dzie si� r�ni�, dlatego jest wirtualna.
		
		void refreshScreen() { //Metoda odpowiedzialna za wy�wietlanie i od�wie�anie wygl�du menu.
			if(il != NULL) { //Robimy to jedynie wtedy, kiedy lista nie jest pusta.
				system("cls");
				cout << " " << menuText << endl << endl; //Wypisanie tekstu menu, podanego jako parametr konstruktora.
			
				/* Wypisanie wszystkich pozycji w menu i zaznaczenie aktualnie aktywnego elementu (cil) za pomoc� gwiazdki.
					Lista najpierw nale�y zapami�ta� bie��cy element w osobnej zmiennej.
					Nast�pnie przej�� na pocz�tek listy i zacz�� j� wypisywa� od pocz�tku w p�tli (z u�yciem kolejnej zmiennej pomocniczej - temp).
					Je�li w danym przebiegu dany element odpowiada elementowi bie��cemu (cil), to piszemy gwiazdk�.
					Je�li nie odpowiada, to spacje.
					Wypisujemy tak ca�� list�, a nast�pnie cofamy zmiany (il = cil.*/
			
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
			} else {
				system("cls");
				cout << " " << menuText << endl << endl;
				cout << emptyMenuText << endl;
				isRunning = false;
				system("pause");
			}
		}
			
	public:
		
		Menu(ItemList* & il, string menuText) {
			this->il = il;
			this->menuText = menuText;
			this->emptyMenuText = "";
			this->isRunning = true;
			
			refreshScreen(); //Wy�wietlanie Menu na ekranie.
		}
		
		Menu(ItemList* & il, string menuText, string emptyMenuText) {
			this->il = il;
			this->menuText = menuText;
			this->emptyMenuText = emptyMenuText;
			this->isRunning = true;
			
			refreshScreen(); //Wy�wietlanie Menu na ekranie.
		}
		
		//Metoda umo�liwiaj�ca wyb�r opcji w menu. Dzia�a w niesko�czonej p�tli, kt�ra mo�e jednak zosta� przerwana. Domy�lnie
		//ustawiona jest w nast�puj�cy spos�b: S - go down, W - go up, k - action
		//Lista opcji wy�wietlana jest od g�ry do do�u (na g�rze pierwszy element na li�cie, poni�ej nast�pne), dlatego nast�pne elementy
		//na li�cie znajduj� si� poni�ej (klawisz S). Analogicznie poprzednie elementy (klawisz W).
		void changeOptions() {
			char c;
			while(isRunning) {
				c = _getch(); //Czekaj na podanie znaku.
		
				switch(c) {  //Za ka�d� zmian� opcji, od�wie�a si� ekran.
					case 's': items->nextItem(il); refreshScreen(); break; //scroll DOWN
					case 'w': items->prevItem(il); refreshScreen(); break; //scroll UP
					case 'k': execute(); if(il != NULL) refreshScreen(); break; //Podejmij akcj� (execute), a po zako�czeniu akcji, od�wie� ekran.
				}
			}
			
		}
		
		//Metoda umo�liwiaj�ca ponown� aktywacj� danego menu.
		void makeRunning() {
			if(il != NULL) isRunning = true;
			refreshScreen();
		}
};
