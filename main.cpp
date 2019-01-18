//Plik startowy projektu.

#include "header.h" //Do³¹czamy nag³ówek. Dziêki temu nag³ówek wystarczy zmodyfikowaæ raz i bêdzie mia³o to wp³yw na wszystkie pliki z nag³ówkiem.

#include "Items.cpp"
Items* items = new Items();

#include "Fight.cpp"

void refreshScreen(ItemList* il) {
	system("cls");
	cout << "W - Next Item | S - Previous Item | Q - Quit" << endl << endl;
	
	ItemList* temp = il;
	do {
		if(il == temp) cout << "[ " << il->item->name << " ]" << endl;
		else cout << il->item->name << endl;
		items->nextItem(il);
	} while(il != temp);
	
	cout << endl;
}

int main() {
	
	ItemList* il = NULL;
	
	Item* item = new Item;
	item->id = 0;
	item->slots = 5;
	item->name = "Miecz";
	
	items->addItem(il,item);
	
	item = new Item;
	item->id = 1;
	item->slots = 3;
	item->name = "Tarcza";
	
	items->addItem(il,item);
	
	item = new Item;
	item->id = 2;
	item->slots = 7;
	item->name = "Luk";
	
	items->addItem(il,item);
	
	item = new Item;
	item->id = 3;
	item->slots = 1;
	item->name = "Mikstura";
	
	items->addItem(il,item);
	
	item = new Item;
	item->id = 3;
	item->slots = 1;
	item->name = "Mikstura";
	
	items->addItem(il,item);
	
	items->seekBegin(il);

	refreshScreen(il);
	
	char c;
	bool isRunning = true;
	
	while(isRunning) {
		c = _getch();
		
		switch(c) {
			case 'w': items->nextItem(il); refreshScreen(il); break;
			case 's': items->prevItem(il); refreshScreen(il); break;
			case 'q': isRunning = false;
		}
	}
	
	system("pause");
	return 0;
}
