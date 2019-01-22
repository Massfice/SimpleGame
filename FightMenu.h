//Plik zawiera klas� u�ywan� podczas walki z przeciwnikami.

class FightMenu : public Menu {
		private:
			
			void execute() {
				switch(il->item->id) {
					case 0: isRunning = false; break;
				}
			}
			
		//Metoda inicjuj�ca menu
		void initMenu() {
					
		}
			
		public:
			
		FightMenu(ItemList* il, string menuText) : Menu(il,menuText) {
			initMenu();
		}
		
		FightMenu(ItemList* il, string menuText, string emptyMenuText) : Menu(il,menuText,emptyMenuText) {
			initMenu();
		}
			
			void getReward(ItemList* & itemsToPick) { //Otrzymywanie nagrody za wygran� walk�.
			
				Item* item = new Item;
				item->id = 20;
				item->name = "Great Sword [ Required Slots: 20 ]";
			
				items->addItem(itemsToPick,item);
			
				system("cls");
				cout << endl;
				cout << " Ork defeated! Great sword was dropped." << endl;
				cout << " ";
				system("pause");
			
				//W tej wersji nie ma zaimplementowanej walki. Ork zawsze zostaje pokonany i upuszcza wielki miecz.
				//Wielki miecz zostaje dodany do listy przedmiot�w (il) le��cych na ziemi i mo�e zosta� podniesiony przez gracza.
				//W finanlej wersji powinna pojawi� si� ca�a klasa odpowiedzialna za walk�.
				//Metoda getReward() powinna by� metod� prywatn�, uruchamian� po wygraniu walki.
		}
};