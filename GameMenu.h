//Klasa odpowiedzialna za menu gry.

class GameMenu : public Menu {
	
	private:
		
		InventoryMenu* inventoryMenu;
		FightMenu* fightMenu;
		ItemList* itemsToPick; //Klasa ta pamiêta listê przedmiotów do podniesienia, poniewa¿ z poziomu tego menu mo¿na j¹ zmieniaæ.
		ItemList* itemsToDrop; //Klasa ta pamiêta listê przedmiotów do wyrzucenia, poniewa¿ z poziomu tego menu mo¿na j¹ zmieniaæ.
								
		
		void execute() {
			switch(il->item->id) { //Wykonujemy opcjê po identyfikatorze danego "przedmiotu" (opcji).
				case 0: goInventory(); break;
				case 1: goFight(); break;
				case 2: isRunning = false; items->seekBegin(il); break; //Powrót do Menu G³ównego.
			}
		}
		
		//Metoda inicjuj¹ca menu
		void initMenu() {
			this->inventoryMenu = NULL;
			this->fightMenu = NULL;
			createItemsLists();			
		}
								
		//Otwieramy menu ekwipunku.
		void goInventory() {
			
			isRunning = false;
			
			if(inventoryMenu == NULL) {
				
				//Tworzenie menu ekwipunku
				inventoryMenu = new InventoryMenu(itemsToDrop,itemsToPick,"Drop...");
				
				inventoryMenu->changeOptions();
				
			} else {
				inventoryMenu->makeRunning();
				inventoryMenu->changeOptions();
			}
			
			isRunning = true;
			items->seekBegin(il);
		}
		
		//Walczymy:
		goFight() {
			
			isRunning = false;
			
			if(fightMenu == NULL) {
				
				ItemList* il2 = NULL;
				
				Item* item = new Item;
				item->id = 0;
				item->name = "[ ATTACK! ]";
				
				items->addItem(il2,item);
				
				item = new Item;
				item->id = 1;
				item->name = "[ BACK! ]";
				
				items->addItem(il2,item);
				
				//Tworzenie przeciwników: (w przysz³oœci mo¿na przeciwników generowaæ losowo - zamiast wpisywaæ rêcznie wrogów, mo¿naby 
				//wywo³aæ funkcjê, która ich generowo losuje i zwraca Enemy** enemies).
				
				Enemy** enemies = new Enemy*; //Tablica przeciwników.
				
				ItemList* enemyInventory0 = NULL; //Ekwipunek pierwszego wroga.
				ItemList* enemyInventory1 = NULL; //Ekpipunek drugiego wroga.
				ItemList* enemyInventory2 = NULL; //Ekwipunek trzeciego wroga.
				
				//Tworzenie pierwszego wroga:
				
				item = new Item;
				item->id = 3;
				item->name = "Dagger [ Required Slots: 3 ]";
				
				items->addItem(enemyInventory0, item);
				
				item = new Item;
				item->id = 3;
				item->name = "Dagger [ Required Slots: 3 ]";
				
				items->addItem(enemyInventory0, item);
				
				item = new Item;
				item->id = 2;
				item->name = "Fire Potion [ Required Slots: 2 ]";
				
				items->addItem(enemyInventory0, item);
				
				items->seekBegin(enemyInventory0);
				
				enemies[0] = new Enemy;
				enemies[0]->id = 0;
				enemies[0]->name = "Bandit";
				enemies[0]->il = enemyInventory0;
				
				//Tworzenie drugiego wroga:
				
				item = new Item;
				item->id = 5;
				item->name = "One-Handed Axe [ Required Slots: 5 ]";
				
				items->addItem(enemyInventory1, item);
				
				item = new Item;
				item->id = 3;
				item->name = "Small Shield [ Required Slots: 4 ]";
				
				items->addItem(enemyInventory1, item);
				
				items->seekBegin(enemyInventory1);
				
				enemies[1] = new Enemy;
				enemies[1]->id = 1;
				enemies[1]->name = "Skeleton";
				enemies[1]->il = enemyInventory1;
				
				//Tworzenie trzeciego wroga:
				
				item = new Item;
				item->id = 20;
				item->name = "Great Two-Handed Sword [ Required Slots: 20 ]";
				
				items->addItem(enemyInventory2, item);
				
				items->seekBegin(enemyInventory2);
				
				enemies[2] = new Enemy;
				enemies[2]->id = 2;
				enemies[2]->name = "Orc Chieftain";
				enemies[2]->il = enemyInventory2;
				
				enemies[3] = NULL;
				
				//Tworzenie menu walki:
				
				fightMenu = new FightMenu(il2,"You face an enemy. What should you do?",itemsToDrop,itemsToPick,enemies,
				countEnemies(enemies)); //sizeof(enemies)/sizeof(Enemy)
				fightMenu->changeOptions();
				
			} else {
				fightMenu->makeRunning();
				fightMenu->changeOptions();
			}
			
			isRunning = true;
			items->seekBegin(il);
		}
		
		//Metoda tworz¹ca listy itemów.
		void createItemsLists() {
				
			//Itemy, które mo¿na wyrzuciæ.	
			//Na pocz¹tku brak.
			
			itemsToDrop = NULL;
				
			Item* item = new Item;
			item->name = "[ PICK SOMETHING! ]";
			item->id = 0;
				
			items->addItem(itemsToDrop,item);
				
			item = new Item;
			item->name = "[ BACK! ]\n";
			item->id = 1;
				
			items->addItem(itemsToDrop,item);
				
			items->seekBegin(itemsToDrop);
			
			//Itemy, które mo¿na podnieœæ.
			
			itemsToPick = NULL;
			
			item = new Item;
			item->name = "[ DROP SOMETHING! ]";
			item->id = 0;
				
			items->addItem(itemsToPick,item);
				
			item = new Item;
			item->name = "[ BACK! ]\n";
			item->id = 1;
				
			items->addItem(itemsToPick,item);
			
			item = new Item;
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
				
			items->seekBegin(itemsToPick);
		}
		
		public:
			
		GameMenu(ItemList* il, string menuText) : Menu(il,menuText) {
			initMenu();
		}
		
		GameMenu(ItemList* il, string menuText, string emptyMenuText) : Menu(il,menuText,emptyMenuText) {
			initMenu();
		}
};
