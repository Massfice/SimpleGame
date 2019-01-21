//Plik startowy projektu.

#include "header.h" //Do³¹czamy nag³ówek. Dziêki temu nag³ówek wystarczy zmodyfikowaæ raz i bêdzie mia³o to wp³yw na wszystkie pliki z nag³ówkiem.

//Do³¹czamy pliki nag³ówkowe poszczególnych klas.
#include "Items.h"
#include "Fight.h"
#include "Menu.h"
#include "InventoryMenu.h"
#include "MainMenu.h"


int main() {

	//Tworzenie menu g³ównego.
	ItemList* il = NULL;
	MainMenu* mainMenu = NULL;
	
	Item* item = new Item;
	item->id = 0;
	item->name = "Inventory";
	
	items->addItem(il,item);
	
	item = new Item;
	item->id = 1;
	item->name = "Quit";
	
	items->addItem(il,item);
	
	//Tworzenie menu g³ównego
	if(mainMenu == NULL) mainMenu = new MainMenu(il,"Use W to scroll UP | Use S to scroll DOWN | Use K to EXECUTE");
	mainMenu->changeOptions();
	
	system("pause");
	return 0;
}
