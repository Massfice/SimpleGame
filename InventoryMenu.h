//Klasa odpowiedzialna za zarz¹dzanie ekwipunkiem (menu ekwipunku).

class InventoryMenu : public Menu {
	
	private:
		ItemList* itemsToDrop;
		ItemList* itemsToPick;
		bool mode; // true dla trybu podnoszenia przedmiotów, false dla trybu wyrzucania przedmiotów
		int aSlots; //available slots - dostêpne miejsce w ekwipunku
		string defMenuText; //Standardowy tekst menu.
		
		void execute() {
			switch(il->item->id) { //Wykonujemy opcjê po identyfikatorze danego "przedmiotu" (opcji).
				case 0: swap(); break; //Zmieniamy tryb dzia³ania menu: wyrzucanie/podnoszenie.
				case 1: isRunning = false; break; //Przerywamy wykonywanie pêtli i powracamy do poprzedniego menu.
				default: dropPick(); break; //Wyrzucamy lub podnosimy przedmiot (w zale¿noœci od trybu).
			}
		}
		
		//Metoda zmieniaj¹ca tryb dzia³ania ekwipunku. Mo¿na albo wyrzuciæ przedmioty na ziemiê, albo je podnieœæ (dwie ró¿ne listy).
		void swap() {
			if(mode) {
				defMenuText = "Drop...";
				il = itemsToDrop;
				showSlots();
			} else {
				defMenuText = "Pick...";
				il = itemsToPick;
				showSlots();
			}
			
			mode = !mode;
		}
		
		//Metoda pozwalaj¹ca na wyrzucanie/podnoszenie przedmiotów.
		void dropPick() {
			if(mode) { //Podnoszenie przedmiotów.
				if(il->item->id <= aSlots) { //Maksymalnie w ekwipunku mo¿na mieæ przedmioty o maksymalnej iloœci slotów: 20.
					items->addItem(itemsToDrop,il->item); //Dodajemy przedmiot do listy przedmiotów, które mo¿na wyrzuciæ.
					items->remItem(il); //Usuwamy przedmiot z listy przedmiotów mo¿liwych do podniesienia.
					itemsToPick = il;	
				} else {
					system("cls");
					cout << endl;
					cout << " Not enought available slots... Sorry. You cannot pick this item." << endl << endl;
					cout << " ";
					system("pause");
				}
			} else { //Wyrzucanie przedmiotów.
				items->addItem(itemsToPick,il->item); //Dodajemy przedmiot do listy przedmiotów, które mo¿na podnieœæ.
				items->remItem(il); //Usuwamy przedmiot z listy przedmiotów mo¿liwych do wyrzucenia.
				itemsToDrop = il;
			}
			
			showSlots();
		}
		
		//Metoda wyœwietlaj¹ca iloœæ dostêpnych slotów: (Format: X / Y, gdzie X to zajête miejsce, a Y maksymalne dostêpne)
		void showSlots() {
			menuText = defMenuText;
			
			if(il != NULL) {
				
				aSlots = 20; //Maksymalnie w ekwipunku mo¿na mieæ przedmioty o maksymalnej iloœci slotów: 20.
			
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
				refreshScreen();
			}
		}
		
	
	public:
		InventoryMenu(ItemList* & itemsToDrop, ItemList* & itemsToPick, string menuText) : Menu(itemsToPick,menuText) {
			this->itemsToDrop = itemsToDrop;
			this->itemsToPick = itemsToPick;
			defMenuText = menuText;
			aSlots = 20; //Maksymalnie w ekwipunku mo¿na mieæ przedmioty o maksymalnej iloœci slotów: 20.
			showSlots();
			mode = true;
		}
		
		InventoryMenu(ItemList* & itemsToDrop, ItemList* & itemsToPick, string menuText, string emptyMenuText) : Menu(itemsToPick,menuText,
		emptyMenuText) {
			this->itemsToDrop = itemsToDrop;
			this->itemsToPick = itemsToPick;
			defMenuText = menuText; //Maksymalnie w ekwipunku mo¿na mieæ przedmioty o maksymalnej iloœci slotów: 20.
			aSlots = 20;
			showSlots();
			mode = true;
		}
};
