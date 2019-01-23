//Plik zawiera klas� u�ywan� podczas walki z przeciwnikami.

class FightMenu : public Menu {
		private:
			
			ItemList* itemsToDrop; //Przedmioty posiadane, przydatne w walce.
			ItemList* itemsToPick; //Przedmioty, kt�re aktualnie le�� na ziemi. Po pokonaniu wroga, lista ta b�dzie aktualizowana.
			
			Enemy** enemies; //Tablica przeciwnik�w.
			int defeatedEnemies; //Liczba pokonanych przeciwnik�w na bie��cym poziomie/w bie��cej lokacji. Jednocze�nie
								//indeks tablicy przeciwnik�w. Przyk�adowo, je�li pokonano 0 przeciwnik�w, to walczymy z pierwszym przeciwnikiem,
								//czyli enemies[defeatedEnemies] = enemies[0]. Je�li pokonali�my 19 przeciwnik�w, to walczymy z 20 przeciwnikiem,
								//czyli enemies[defeatedEnemies] = enemies[19], etc.
			int maxEnemies; //Maksymalna liczba przeciwnik�w na bie��cym poziomie/w bie��cej lokacji.
			
			void execute() {
				switch(il->item->id) {
					case 0: goAttack(); break;
					case 1: isRunning = false; items->seekBegin(il); break;
				}
			}
			
		//Metoda inicjuj�ca menu.
		void initMenu(ItemList* & itemsToDrop, ItemList* & itemsToPick, Enemy** enemies, int maxEnemies) {
			this->itemsToDrop = itemsToDrop;
			this->itemsToPick = itemsToPick;
			this->enemies = enemies;
			this->maxEnemies = maxEnemies;
			this->defeatedEnemies = 0;	
		}
		
		//Metoda inicjuj�ca walk�. Na podstawie id przeciwnika uruchamiana b�dzie konkretna metoda walki. Ka�dy przeciwnik ma w�asn� metod� walki,
		//w�asne statystyki, umiej�tno�ci, stosowan� strategi�, etc.
		void goAttack() {
			if(defeatedEnemies < maxEnemies) { //Walczymy tylko, je�eli nie wszyscy wrogowie zostali pokonani.
				switch(enemies[defeatedEnemies]->id) { //Wyb�r przeciwnika (odpowiedniej metody).
					case 0: fightBandit(); break; //Walka z Bandyt�.
					case 1: fightSkeleton(); break; //Walka ze Szkieletem.
					case 2: fightOrcChieftain(); break; //Walka z Wodzem Ork�w.
				}	
			} else { //W przeciwnym razie, wy�wietlamy komunikat.
				system("cls");
				cout << endl << " There's no enemies here... Sorry, Mighty Warrior." << endl;
				cout << " ";
				system("pause");
			}
		}
		
		//Metoda wywo�ywana po wygranej walce (bez wzgl�du na rodzaj przeciwnika.
		void victory() {
			//Wy�wietlamy komunikat:
			system("cls");
			cout << endl << " You killed " << enemies[defeatedEnemies]->name << "! Enemy's items dropped on the groud: " << endl;
			
			//P�tla przepisuj�ca przedmioty pokonanego wroga, do listy przedmiot�w, le��cych na ziemi (pobojowisko).
			while(enemies[defeatedEnemies]->il != NULL) { //Usuwamy przedmioty z listy tak d�ugo a� nie b�dzie pusta (NULL) i przepisujemy je.
				cout << " - " << enemies[defeatedEnemies]->il->item->name << endl; //Wypisujemy list� przedmiot�w, kt�ra wypad�a
				items->addItem(itemsToPick,enemies[defeatedEnemies]->il->item);
				items->remItem(enemies[defeatedEnemies]->il);
			}

			items->seekBegin(itemsToPick);
			
			cout << endl << " Congratulations!" << endl;
						
			defeatedEnemies++; //Zwi�kszamy licznik pokonanych przeciwnik�w.
			
			cout << " ";
			system("pause");
		}
		
		//Metoda walki z Bandyt�:
		void fightBandit() {
			victory(); //P�ki co metoda nie zosta�a opracowana. Gracz automatycznie pokonuje Bandyt�.
		}
		
		//Metoda walki ze Szkieletem:
		void fightSkeleton() {
			victory(); //P�ki co metoda nie zosta�a opracowana. Gracz automatycznie pokonuje Szkieleta.
		}
		
		//Metoda walki z Wodzem Ork�w:
		void fightOrcChieftain() {
			victory(); //P�ki co metoda nie zosta�a opracowana. Gracz automatycznie pokonuje Wodza Ork�w.
		}		
			
		public:
			
		FightMenu(ItemList* il, string menuText, ItemList* & itemsToDrop, ItemList* & itemsToPick, Enemy** enemies,
		int maxEnemies) : Menu(il,menuText) {
			initMenu(itemsToDrop, itemsToPick, enemies, maxEnemies);
		}
		
		FightMenu(ItemList* il, string menuText, string emptyMenuText, ItemList* & itemsToDrop, ItemList* & itemsToPick, Enemy** enemies,
		int maxEnemies) : Menu(il,menuText,emptyMenuText) {
			initMenu(itemsToDrop, itemsToPick, enemies, maxEnemies);
		}
};
