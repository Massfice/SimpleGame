//Plik startowy projektu.

#include "header.h" //Do³¹czamy nag³ówek. Dziêki temu nag³ówek wystarczy zmodyfikowaæ raz i bêdzie mia³o to wp³yw na wszystkie pliki z nag³ówkiem.

//Do³¹czamy pliki nag³ówkowe poszczególnych klas.
#include "Items.h"
#include "Enemy.h"
#include "Menu.h"
#include "FightMenu.h"
#include "InventoryMenu.h"
#include "GameMenu.h"
#include "MainMenu.h"


int main() {

	//Tworzenie menu g³ównego.
	ItemList* il = NULL;
	
	Item* item = new Item;
	item->id = 0;
	item->name = "[ PLAY! ]";
	
	items->addItem(il,item);
	
	item = new Item;
	item->id = 2;
	item->name = "[ QUIT! ]";
	
	items->addItem(il,item);
	
	items->seekBegin(il);
	
	MainMenu* mainMenu = new MainMenu(il,"Use W to scroll UP | Use S to scroll DOWN | Use K to EXECUTE");
	mainMenu->changeOptions();
	
	cout << " ";
	system("pause");
	return 0;
}
