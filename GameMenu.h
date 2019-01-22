//Klasa odpowiedzialna za menu gry.

class GameMenu : public Menu {
	
	private:
		
		InventoryMenu* inventoryMenu;
		ItemList* itemsToPick; //Klasa ta pamiêta listê przedmiotów do podniesienia, poniewa¿ z poziomu tego menu mo¿na j¹ zmieniaæ,
								//w przeciwieñstwie do listy przedmiotów do wyrzucenia.
								
		
		void execute() {
			switch(il->item->id) { //Wykonujemy opcjê po identyfikatorze danego "przedmiotu" (opcji).
				case 0: goInventory(); break;
				case 1: goFight(); break;
				case 2: isRunning = false; break; //Powrót do Menu G³ównego.
			}
		}
								
		//Otwieramy menu ekwipunku.
		void goInventory() {
			
			isRunning = false;
			
			if(inventoryMenu == NULL) {
				ItemList* itemsToDrop = NULL;
				
				//Itemy, które mo¿na wyrzuciæ.	
				//Na pocz¹tku brak.		
				Item* item = new Item;
				item->name = "[ PICK SOMETHING! ]";
				item->id = 0;
				
				items->addItem(itemsToDrop,item);
				
				item = new Item;
				item->name = "[ BACK! ]";
				item->id = 1;
				
				items->addItem(itemsToDrop,item);
				
				items->seekBegin(itemsToDrop);
				
				//Tworzenie menu ekwipunku
				inventoryMenu = new InventoryMenu(itemsToDrop,itemsToPick,"Drop...");
				
				inventoryMenu->changeOptions();
				
			} else {
				inventoryMenu->makeRunning();
				inventoryMenu->setItemsToPick(itemsToPick);
				inventoryMenu->changeOptions();
			}
			
			itemsToPick = inventoryMenu->getItemsToPick();
			isRunning = true;
		}
		
		//Walczymy z orkiem:
		goFight() {
			
			isRunning = false;
			
			Fight* fight = new Fight();
			fight->getReward(itemsToPick);
			
			isRunning = true;
		}
		
		//Metoda tworz¹ca listê itemów do podniesienia
		void createItemsToPickList() {
			//Itemy, które mo¿na podnieœæ.
			
			Item* item = new Item;
			item->name = "Long Sword [ Required Slots: 7 ]";
			item->id = 7;
				
			items->addItem(itemsToPick,item);
				
			item = new Item;
			item->name = "Healing Potion [ Required Slots: 2 ]";
			item->id = 2;
				
			items->addItem(itemsToPick,item);
				
			item = new Item;
			item->name = "Mana Potion [ Required Slots: 2 ]";
			item->id = 2;
				
			items->addItem(itemsToPick,item);
				
			item = new Item;
			item->name = "Power Potion [ Required Slots: 2 ]";
			item->id = 2;
				
			items->addItem(itemsToPick,item);
				
			item = new Item;
			item->name = "Holy Potion [ Required Slots: 2 ]";
			item->id = 2;
				
			items->addItem(itemsToPick,item);
			item = new Item;
			item->name = "Bow [ Required Slots: 8 ]";
			item->id = 8;
				
			items->addItem(itemsToPick,item);
								
			item = new Item;
			item->name = "[ DROP SOMETHING! ]";
			item->id = 0;
				
			items->addItem(itemsToPick,item);
				
			item = new Item;
			item->name = "[ BACK! ]";
			item->id = 1;
				
			items->addItem(itemsToPick,item);
				
			items->seekBegin(itemsToPick);
		}
		
		public:
			
		GameMenu(ItemList* il, string menuText) : Menu(il,menuText) {
			this->inventoryMenu = NULL;
			this->itemsToPick = NULL;
			createItemsToPickList();
		}
		
		GameMenu(ItemList* il, string menuText, string emptyMenuText) : Menu(il,menuText,emptyMenuText) {
			this->inventoryMenu = NULL;
			this->itemsToPick = NULL;
			createItemsToPickList();
		}
};
