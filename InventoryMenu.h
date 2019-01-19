//Klasa odpowiedzialna za zarz¹dzanie ekwipunkiem (menu ekwipunku).

class InventoryMenu : public Menu {
	
	private:
		ItemList* itemsToDrop;
		ItemList* itemsToPick;
		bool mode; // true dla trybu podnoszenia przedmiotów, false dla trybu wyrzucania przedmiotów
		
		void execute() {
			switch(il->item->id) { //Wykonujemy opcjê po identyfikatorze danego "przedmiotu" (opcji).
				case 0: swap(); refreshScreen(); break; //Zmieniamy tryb dzia³ania menu: wyrzucanie/podnoszenie.
				case 1: isRunning = false; break; //Przerywamy wykonywanie pêtli i powracamy do poprzedniego menu.
				default: dropPick(); refreshScreen(); break; //Wyrzucamy lub podnosimy przedmiot (w zale¿noœci od trybu).
			}
		}
		
		//Metoda zmieniaj¹ca tryb dzia³ania ekwipunku. Mo¿na albo wyrzuciæ przedmioty na ziemiê, albo je podnieœæ (dwie ró¿ne listy).
		void swap() {
			if(mode) {
				menuText = "Drop...";
				changeListOptions(itemsToDrop);
			} else {
				menuText = "Pick...";
				changeListOptions(itemsToPick);
			}
			
			mode = !mode;
		}
		
		//Metoda pozwalaj¹ca na wyrzucanie/podnoszenie przedmiotów.
		void dropPick() {
			if(mode) { //Podnoszenie przedmiotów.
				items->addItem(itemsToDrop,itemsToPick->item); //Dodajemy przedmiot do listy przedmiotów, które mo¿na wyrzuciæ.
				items->remItem(itemsToPick); //Usuwamy przedmiot z listy przedmiotów mo¿liwych do podniesienia.
			} else { //Wyrzucanie przedmiotów.
				items->addItem(itemsToPick,itemsToDrop->item); //Dodajemy przedmiot do listy przedmiotów, które mo¿na podnieœæ.
				items->remItem(itemsToDrop); //Usuwamy przedmiot z listy przedmiotów mo¿liwych do wyrzucenia.
			}
		}
	
	public:
		InventoryMenu(ItemList* & itemsToDrop, ItemList* & itemsToPick, string menuText) : Menu(itemsToPick,menuText) {
			this->itemsToDrop = itemsToDrop;
			this->itemsToPick = itemsToPick;
			mode = true;
		}
};
