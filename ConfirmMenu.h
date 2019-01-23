//Klasa odpowiedzialna za menu typu "Tak" (true) /"Nie" (false).

//Tworzenie opcji menu:

class ConfirmMenu : public Menu {
	private:
		
		bool confirmed;
		
		ItemList* & createConfirm() {
			ItemList* il2 = NULL;
			
			Item* item = new Item;
			item->name = "[ NO! ]";
			item->id = 0;
			
			items->addItem(il2,item);
			
			item = new Item;
			item->name = "[ YES! ]";
			item->id = 1;
			
			items->addItem(il2,item);
			
			items->seekBegin(il2);
			
			return il2;
		}
		
		void execute() {
			switch(il->item->id) {
				case 0: confirmed = false; isRunning = false; break;
				case 1: confirmed = true; isRunning = false; break;
			}
		}
	
	public:
		
		ConfirmMenu(string menuText) : Menu(createConfirm(),menuText) {
			confirmed = false;
		}
		
		bool isConfirmed() {
			makeRunning();
			changeOptions();
			return confirmed;
		}
};
