//Plik zawiera klasê u¿ywan¹ podczas walki z przeciwnikami.

class Fight {
		
	public:
		void getReward(ItemList* & itemsOnTheGround) { //Otrzymywanie nagrody za wygran¹ walkê.
			
			Item* item = new Item;
			item->id = 5;
			item->name = "Wielki Miecz";
			
			items->addItem(itemsOnTheGround,item);
			
			system("cls");
			cout << "Ork defeated! Great sword was dropped." << endl;
			system("pause");
			
			//W tej wersji nie ma zaimplementowanej walki. Ork zawsze zostaje pokonany i upuszcza wielki miecz.
			//Wielki miecz zostaje dodany do listy przedmiotów (il) le¿¹cych na ziemi i mo¿e zostaæ podniesiony przez gracza.
			//W finanlej wersji powinna pojawiæ siê ca³a klasa odpowiedzialna za walkê.
			//Metoda getReward() powinna byæ metod¹ prywatn¹, uruchamian¹ po wygraniu walki.
		}
};
