//Klasa odpowiedzialna za zarz�dzanie ekwipunkiem (menu ekwipunku).

class InventoryMenu : public Menu {
	
	private:
		ItemList* itemsToDrop;
		ItemList* itemsToPick;
		bool mode; // true dla trybu podnoszenia przedmiot�w, false dla trybu wyrzucania przedmiot�w
		
		void execute() {
			switch(il->item->id) { //Wykonujemy opcj� po identyfikatorze danego "przedmiotu" (opcji).
				case 0: swap(); refreshScreen(); break; //Zmieniamy tryb dzia�ania menu: wyrzucanie/podnoszenie.
				case 1: isRunning = false; break; //Przerywamy wykonywanie p�tli i powracamy do poprzedniego menu.
				default: dropPick(); refreshScreen(); break; //Wyrzucamy lub podnosimy przedmiot (w zale�no�ci od trybu).
			}
		}
		
		//Metoda zmieniaj�ca tryb dzia�ania ekwipunku. Mo�na albo wyrzuci� przedmioty na ziemi�, albo je podnie�� (dwie r�ne listy).
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
		
		//Metoda pozwalaj�ca na wyrzucanie/podnoszenie przedmiot�w.
		void dropPick() {
			if(mode) { //Podnoszenie przedmiot�w.
				items->addItem(itemsToDrop,itemsToPick->item); //Dodajemy przedmiot do listy przedmiot�w, kt�re mo�na wyrzuci�.
				items->remItem(itemsToPick); //Usuwamy przedmiot z listy przedmiot�w mo�liwych do podniesienia.
			} else { //Wyrzucanie przedmiot�w.
				items->addItem(itemsToPick,itemsToDrop->item); //Dodajemy przedmiot do listy przedmiot�w, kt�re mo�na podnie��.
				items->remItem(itemsToDrop); //Usuwamy przedmiot z listy przedmiot�w mo�liwych do wyrzucenia.
			}
		}
	
	public:
		InventoryMenu(ItemList* & itemsToDrop, ItemList* & itemsToPick, string menuText) : Menu(itemsToPick,menuText) {
			this->itemsToDrop = itemsToDrop;
			this->itemsToPick = itemsToPick;
			mode = true;
		}
};
