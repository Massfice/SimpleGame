//Klasa odpowiedzialna za zarz�dzanie ekwipunkiem (menu ekwipunku).

class InventoryMenu : public Menu {
	
	private:
		ItemList* itemsToDrop;
		ItemList* itemsToPick;
		bool mode; // true dla trybu podnoszenia przedmiot�w, false dla trybu wyrzucania przedmiot�w
		int aSlots; //available slots - dost�pne miejsce w ekwipunku
		string defMenuText; //Standardowy tekst menu.
		
		void execute() {
			switch(il->item->id) { //Wykonujemy opcj� po identyfikatorze danego "przedmiotu" (opcji).
				case 0: swap(); break; //Zmieniamy tryb dzia�ania menu: wyrzucanie/podnoszenie.
				case 1: isRunning = false; items->seekBegin(il); break; //Przerywamy wykonywanie p�tli i powracamy do poprzedniego menu.
				default: dropPick(); break; //Wyrzucamy lub podnosimy przedmiot (w zale�no�ci od trybu).
			}
		}
		
		//Metoda inicjuj�ca menu
		void initMenu(ItemList* & itemsToDrop, ItemList* & itemsToPick) {
			mode = false;
			aSlots = 20; //Maksymalnie w ekwipunku mo�na mie� przedmioty o maksymalnej ilo�ci slot�w: 20.
			this->itemsToDrop = itemsToDrop;
			this->itemsToPick = itemsToPick;
			refreshScreen();			
		}
		
		//Metoda zmieniaj�ca tryb dzia�ania ekwipunku. Mo�na albo wyrzuci� przedmioty na ziemi�, albo je podnie�� (dwie r�ne listy).
		void swap() {
			if(mode) {
				defMenuText = "Drop...";
				il = itemsToDrop;
				items->seekBegin(il);
				refreshScreen();
			} else {
				defMenuText = "Pick...";
				il = itemsToPick;
				items->seekBegin(il);
				refreshScreen();
			}
			
			mode = !mode;
		}
		
		//Metoda pozwalaj�ca na wyrzucanie/podnoszenie przedmiot�w.
		void dropPick() {
			if(mode) { //Podnoszenie przedmiot�w.
				if(il->item->id <= aSlots) { //Maksymalnie w ekwipunku mo�na mie� przedmioty o maksymalnej ilo�ci slot�w: 20.
					items->addItem(itemsToDrop,il->item); //Dodajemy przedmiot do listy przedmiot�w, kt�re mo�na wyrzuci�.
					items->remItem(il); //Usuwamy przedmiot z listy przedmiot�w mo�liwych do podniesienia.
					itemsToPick = il;	
				} else {
					system("cls");
					cout << endl;
					cout << " Not enought available slots... Sorry. You cannot pick this item." << endl << endl;
					cout << " ";
					system("pause");
				}
			} else { //Wyrzucanie przedmiot�w.
				items->addItem(itemsToPick,il->item); //Dodajemy przedmiot do listy przedmiot�w, kt�re mo�na podnie��.
				items->remItem(il); //Usuwamy przedmiot z listy przedmiot�w mo�liwych do wyrzucenia.
				itemsToDrop = il;
			}
			
			refreshScreen();
		}
		
		//Metoda wy�wietlaj�ca ilo�� dost�pnych slot�w: (Format: X / Y, gdzie X to zaj�te miejsce, a Y maksymalne dost�pne)
		void refreshScreen() { //showSlots
			menuText = defMenuText;
			
			if(il != NULL) {
				
				aSlots = 20; //Maksymalnie w ekwipunku mo�na mie� przedmioty o maksymalnej ilo�ci slot�w: 20.
			
				ItemList* temp = itemsToDrop;
				do {
					if(itemsToDrop->item->id != 1) aSlots = aSlots - itemsToDrop->item->id;
					items->nextItem(itemsToDrop);
				} while(itemsToDrop != temp);
				
				ostringstream os;
				os << aSlots;
				
				string buff = os.str();
				
				menuText.append("                                        [ Available Slots: " );
				menuText.append(buff);
				menuText.append(" / 20 ]");
				
				Menu::refreshScreen();
			}
		}
		
	
	public:
		InventoryMenu(ItemList* & itemsToDrop, ItemList* & itemsToPick, string menuText) : Menu(itemsToDrop,menuText) {
			defMenuText = menuText;
			emptyMenuText = "";
			initMenu(itemsToDrop,itemsToPick);
		}
		
		InventoryMenu(ItemList* & itemsToDrop, ItemList* & itemsToPick, string menuText, string emptyMenuText) : Menu(itemsToDrop,menuText,
		emptyMenuText) {
			defMenuText = menuText;
			this->emptyMenuText = emptyMenuText;
			initMenu(itemsToDrop,itemsToPick);
		}
};
