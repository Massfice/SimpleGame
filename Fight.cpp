//Plik zawiera klas� u�ywan� podczas walki z przeciwnikami.

#include "header.h" //Do��czamy nag��wek. Dzi�ki temu nag��wek wystarczy zmodyfikowa� raz i b�dzie mia�o to wp�yw na wszystkie pliki z nag��wkiem.

class Fight {
		
	public:
		void getReward(ItemList* & itemsOnTheGround) { //Otrzymywanie nagrody za wygran� walk�.
			
			Item* item = new Item;
			item->id = 5;
			item->slots = 25;
			item->name = "Wielki Miecz";
			
			items->addItem(itemsOnTheGround,item);
			
			system("cls");
			cout << "Ork defeated! Great sword was dropped.";
			system("pause");
			
			//W tej wersji nie ma zaimplementowanej walki. Ork zawsze zostaje pokonany i upuszcza wielki miecz.
			//Wielki miecz zostaje dodany do listy przedmiot�w (il) le��cych na ziemi i mo�e zosta� podniesiony przez gracza.
			//W finanlej wersji powinna pojawi� si� ca�a klasa odpowiedzialna za walk�.
			//Metoda getReward() powinna by� metod� prywatn�, uruchamian� po wygraniu walki.
		}
};
