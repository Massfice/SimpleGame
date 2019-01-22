//Plik zawiera klasê u¿ywan¹ podczas walki z przeciwnikami.

class FightMenu : public Menu {
		private:
			
			void execute() {
				
			}
			
		public:
			
		FightMenu(ItemList* il, string menuText) : Menu(il,menuText) {
			
		}
		
		FightMenu(ItemList* il, string menuText, string emptyMenuText) : Menu(il,menuText,emptyMenuText) {
			
		}
			
			void getReward(ItemList* & itemsToPick) { //Otrzymywanie nagrody za wygran¹ walkê.
			
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
				//Wielki miecz zostaje dodany do listy przedmiotów (il) le¿¹cych na ziemi i mo¿e zostaæ podniesiony przez gracza.
				//W finanlej wersji powinna pojawiæ siê ca³a klasa odpowiedzialna za walkê.
				//Metoda getReward() powinna byæ metod¹ prywatn¹, uruchamian¹ po wygraniu walki.
		}
};
