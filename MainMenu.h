//Klasa odpowiedzialna za menu g�owne.

class MainMenu : public Menu {
	private:
		
		GameMenu* gameMenu;
		
		void execute() {
			switch(il->item->id) { //Wykonujemy opcj� po identyfikatorze danego "przedmiotu" (opcji).
				case 0: goPlay(); break;
				case 2: isRunning = false; break; //Powr�t do Menu G��wnego.
			}
		}
		
		//W��czamy gr�
		void goPlay() {
			
			isRunning = false;
			
			if(gameMenu == NULL) {
				ItemList* il2 = NULL;
	
				Item* item = new Item;
				item->id = 0;
				item->name = "[ INVENTORY! ]";
		
				items->addItem(il2,item);

				item = new Item;
				item->id = 1;
				item->name = "[ FIGHT! ]";
	
				items->addItem(il2,item);
	
				item = new Item;
				item->id = 2;
				item->name = "[ RETURN TO MAIN MENU! ]";
	
				items->addItem(il2,item);
	
				items->seekBegin(il2);
	
				gameMenu = new GameMenu(il2,"Use W to scroll UP | Use S to scroll DOWN | Use K to EXECUTE");
				gameMenu->changeOptions();
				
			} else {
				gameMenu->makeRunning();
				gameMenu->changeOptions();				
			}
			
			isRunning = true;
		}
	
	public:
	
		MainMenu(ItemList* il, string menuText) : Menu(il,menuText) {
			this->gameMenu = NULL;
		}
		
		MainMenu(ItemList* il, string menuText, string emptyMenuText) : Menu(il,menuText,emptyMenuText) {
			this->gameMenu = NULL;
		}
		
};
