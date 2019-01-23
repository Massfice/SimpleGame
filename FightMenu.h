//Plik zawiera klasê u¿ywan¹ podczas walki z przeciwnikami.

class FightMenu : public Menu {
		private:
			
			ItemList* itemsToDrop; //Przedmioty posiadane, przydatne w walce.
			ItemList* itemsToPick; //Przedmioty, które aktualnie le¿¹ na ziemi. Po pokonaniu wroga, lista ta bêdzie aktualizowana.
			
			Enemy** enemies; //Tablica przeciwników.
			int defeatedEnemies; //Liczba pokonanych przeciwników na bie¿¹cym poziomie/w bie¿¹cej lokacji. Jednoczeœnie
								//indeks tablicy przeciwników. Przyk³adowo, jeœli pokonano 0 przeciwników, to walczymy z pierwszym przeciwnikiem,
								//czyli enemies[defeatedEnemies] = enemies[0]. Jeœli pokonaliœmy 19 przeciwników, to walczymy z 20 przeciwnikiem,
								//czyli enemies[defeatedEnemies] = enemies[19], etc.
			int maxEnemies; //Maksymalna liczba przeciwników na bie¿¹cym poziomie/w bie¿¹cej lokacji.
			
			void execute() {
				switch(il->item->id) {
					case 0: goAttack(); break;
					case 1: isRunning = false; items->seekBegin(il); break;
				}
			}
			
		//Metoda inicjuj¹ca menu.
		void initMenu(ItemList* & itemsToDrop, ItemList* & itemsToPick, Enemy** enemies, int maxEnemies) {
			this->itemsToDrop = itemsToDrop;
			this->itemsToPick = itemsToPick;
			this->enemies = enemies;
			this->maxEnemies = maxEnemies;
			this->defeatedEnemies = 0;	
		}
		
		//Metoda inicjuj¹ca walkê. Na podstawie id przeciwnika uruchamiana bêdzie konkretna metoda walki. Ka¿dy przeciwnik ma w³asn¹ metodê walki,
		//w³asne statystyki, umiejêtnoœci, stosowan¹ strategiê, etc.
		void goAttack() {
			if(defeatedEnemies < maxEnemies) { //Walczymy tylko, je¿eli nie wszyscy wrogowie zostali pokonani.
				switch(enemies[defeatedEnemies]->id) { //Wybór przeciwnika (odpowiedniej metody).
					case 0: fightBandit(); break; //Walka z Bandyt¹.
					case 1: fightSkeleton(); break; //Walka ze Szkieletem.
					case 2: fightOrcChieftain(); break; //Walka z Wodzem Orków.
				}	
			} else { //W przeciwnym razie, wyœwietlamy komunikat.
				system("cls");
				cout << endl << " There's no enemies here... Sorry, Mighty Warrior." << endl;
				cout << " ";
				system("pause");
			}
		}
		
		//Metoda wywo³ywana po wygranej walce (bez wzglêdu na rodzaj przeciwnika.
		void victory() {
			//Wyœwietlamy komunikat:
			system("cls");
			cout << endl << " You killed " << enemies[defeatedEnemies]->name << "! Enemy's items dropped on the groud: " << endl;
			
			//Pêtla przepisuj¹ca przedmioty pokonanego wroga, do listy przedmiotów, le¿¹cych na ziemi (pobojowisko).
			while(enemies[defeatedEnemies]->il != NULL) { //Usuwamy przedmioty z listy tak d³ugo a¿ nie bêdzie pusta (NULL) i przepisujemy je.
				cout << " - " << enemies[defeatedEnemies]->il->item->name << endl; //Wypisujemy listê przedmiotów, która wypad³a
				items->addItem(itemsToPick,enemies[defeatedEnemies]->il->item);
				items->remItem(enemies[defeatedEnemies]->il);
			}

			items->seekBegin(itemsToPick);
			
			cout << endl << " Congratulations!" << endl;
						
			defeatedEnemies++; //Zwiêkszamy licznik pokonanych przeciwników.
			
			cout << " ";
			system("pause");
		}
		
		//Metoda walki z Bandyt¹:
		void fightBandit() {
			victory(); //Póki co metoda nie zosta³a opracowana. Gracz automatycznie pokonuje Bandytê.
		}
		
		//Metoda walki ze Szkieletem:
		void fightSkeleton() {
			victory(); //Póki co metoda nie zosta³a opracowana. Gracz automatycznie pokonuje Szkieleta.
		}
		
		//Metoda walki z Wodzem Orków:
		void fightOrcChieftain() {
			victory(); //Póki co metoda nie zosta³a opracowana. Gracz automatycznie pokonuje Wodza Orków.
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
