//Plik startowy projektu.

#include "header.h" //Do��czamy nag��wek. Dzi�ki temu nag��wek wystarczy zmodyfikowa� raz i b�dzie mia�o to wp�yw na wszystkie pliki z nag��wkiem.

//Do��czamy pliki nag��wkowe poszczeg�lnych klas.
#include "Items.h"
#include "Fight.h"
#include "Menu.h"
#include "InventoryMenu.h"
#include "MainMenu.h"


int main() {

	//Tworzenie menu g��wnego.
	ItemList* il = NULL;
	MainMenu* mainMenu = NULL;
	
	Item* item = new Item;
	item->id = 0;
	item->name = "[ INVENTORY! ]";
	
	items->addItem(il,item);

	item = new Item;
	item->id = 1;
	item->name = "[ FIGHT WITH TERRIBLE ORC! ]";
	
	items->addItem(il,item);
	
	item = new Item;
	item->id = 2;
	item->name = "[ QUIT! ]";
	
	items->addItem(il,item);
	
	items->seekBegin(il);
	
	if(mainMenu == NULL) mainMenu = new MainMenu(il,"Use W to scroll UP | Use S to scroll DOWN | Use K to EXECUTE");
	mainMenu->changeOptions();
	
	cout << " ";
	system("pause");
	return 0;
}
