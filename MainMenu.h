//Klasa odpowiedzialna za menu g�owne.

class MainMenu : public Menu {
	private:
		
		InventoryMenu* inventoryMenu;
		
		void execute() {
			switch(il->item->id) { //Wykonujemy opcj� po identyfikatorze danego "przedmiotu" (opcji).
				case 0: goInventory(); break;
				case 1: isRunning = false; break; //Przerywamy wykonywanie programu.
			}
		}
		
		void goInventory() {
			
			isRunning = false;
			
			if(inventoryMenu == NULL) {
				ItemList* itemsToDrop = NULL;
				ItemList* itemsToPick = NULL;
				
				//Itemy, kt�re mo�na wyrzuci�.
				
				Item* item = new Item;
				item->name = "Long Sword [ Required Slots: 7 ]";
				item->id = 7;
				
				items->addItem(itemsToDrop,item);
				
				item = new Item;
				item->name = "Healing Potion [ Required Slots: 2 ]";
				item->id = 2;
				
				items->addItem(itemsToDrop,item);
				
				item = new Item;
				item->name = "Healing Potion [ Required Slots: 2 ]";
				item->id = 2;
				
				items->addItem(itemsToDrop,item);
				
				item = new Item;
				item->name = "Healing Potion [ Required Slots: 2 ]";
				item->id = 2;
				
				items->addItem(itemsToDrop,item);
				
				item = new Item;
				item->name = "Healing Potion [ Required Slots: 2 ]";
				item->id = 2;
				
				items->addItem(itemsToDrop,item);	
						
				item = new Item;
				item->name = "Don't drop anything else and pick something";
				item->id = 0;
				
				items->addItem(itemsToDrop,item);
				
				item = new Item;
				item->name = "Don't drop anything else and return to Main Menu";
				item->id = 1;
				
				items->addItem(itemsToDrop,item);
				
				items->seekBegin(itemsToDrop);
				
				//Itemy, kt�re mo�na podnie��.
				item = new Item;
				item->name = "Bow [ Required Slots: 8 ]";
				item->id = 8;
				
				items->addItem(itemsToPick,item);
								
				item = new Item;
				item->name = "Don't pick anything else and drop something";
				item->id = 0;
				
				items->addItem(itemsToPick,item);
				
				item = new Item;
				item->name = "Don't pick anything else and return to Main Menu";
				item->id = 1;
				
				items->addItem(itemsToPick,item);
				
				items->seekBegin(itemsToPick);
				
				//Tworzenie menu ekwipunku
				inventoryMenu = new InventoryMenu(itemsToDrop,itemsToPick,"Pick...","No items...");
				
				inventoryMenu->changeOptions();
				
			} else {
				inventoryMenu->makeRunning();
				inventoryMenu->changeOptions();
			}
			
			isRunning = true;
		}
	
	public:
		
		MainMenu(ItemList* il, string menuText) : Menu(il,menuText) {
			inventoryMenu = NULL;
		}
		
		MainMenu(ItemList* il, string menuText, string emptyMenuText) : Menu(il,menuText,emptyMenuText) {
			inventoryMenu = NULL;
		}
		
};
