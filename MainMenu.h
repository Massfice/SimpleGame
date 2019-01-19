//Klasa odpowiedzialna za menu g³owne.

class MainMenu : public Menu {
	private:
		
		void execute() {
			switch(il->item->id) { //Wykonujemy opcjê po identyfikatorze danego "przedmiotu" (opcji).
				case 0: system("cls"); cout << "Inventory" << endl; system("pause"); break;
				case 1: isRunning = false; break;
			}
		}
	
	public:
		
		MainMenu(ItemList* il, string menuText):Menu(il,menuText){}
		
};
