//Klasa odpowiedzialna za menu g�owne.

class MainMenu : public Menu {
	private:
		
		void execute() {
			switch(il->item->id) { //Wykonujemy opcj� po identyfikatorze danego "przedmiotu" (opcji).
				case 0: system("cls"); cout << "Inventory" << endl; system("pause"); break;
				case 1: isRunning = false; break;
			}
		}
	
	public:
		
		MainMenu(ItemList* il, string menuText):Menu(il,menuText){}
		
};
