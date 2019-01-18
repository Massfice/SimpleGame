//Plik startowy projektu.

#include "header.h" //Do��czamy nag��wek. Dzi�ki temu nag��wek wystarczy zmodyfikowa� raz i b�dzie mia�o to wp�yw na wszystkie pliki z nag��wkiem.

#include "Items.cpp"
Items* items = new Items();

#include "Fight.cpp"

//void refreshScreen(ItemList* il) {
//	system("cls");
//	cout << "W - Go Down | S - Go Up | Q - Quit" << endl << endl;
//	
//	ItemList* cil = il; //Current ItemList - obecna pozycja na liscie
//	items->seekBegin(il);
//	ItemList* temp = il;
//	do {
//		if(il == cil) cout << " * " << il->item->name << endl;
//		else cout << "   "  << il->item->name << endl;
//		items->nextItem(il);
//	} while(il != temp);
//	
//	cout << endl;
//}

void refreshScreen() {
	system("cls");
	cout << "I - Open Inventory | F - Fight with terrible Orc | Q - Quit" << endl << endl;
}

int main() {
	
	ItemList* itemsOnTheGround = NULL; //Przedmioty na ziemi.
	
	Fight* f = new Fight();
//	
//	Item* item = new Item;
//	item->id = 0;
//	item->slots = 5;
//	item->name = "Miecz";
//	
//	items->addItem(il,item);
//	
//	item = new Item;
//	item->id = 1;
//	item->slots = 3;
//	item->name = "Tarcza";
//	
//	items->addItem(il,item);
//	
//	item = new Item;
//	item->id = 2;
//	item->slots = 7;
//	item->name = "Luk";
//	
//	items->addItem(il,item);
//	
//	item = new Item;
//	item->id = 3;
//	item->slots = 1;
//	item->name = "Mikstura";
//	
//	items->addItem(il,item);
//	
//	item = new Item;
//	item->id = 3;
//	item->slots = 1;
//	item->name = "Mikstura";
//	
//	items->addItem(il,item);
//	
//	items->seekBegin(il);
//
	refreshScreen();
//

//	char c; //Zmienna przechwytuj�ca znak z klawiatury.
//	bool isRunning = true; //
//	
//	while(isRunning) {
//		c = _getch();
//		
//		switch(c) {
//			case 's': items->nextItem(il); refreshScreen(il); break;
//			case 'w': items->prevItem(il); refreshScreen(il); break;
//			case 'q': isRunning = false;
//		}
//	}
		
	char c; //Zmienna przechwytuj�ca znak z klawiatury.
	bool isRunning = true; //P�tla b�dzie dzia�a�a dop�ki ta zmienna b�dzie 'True'. Umo�liwia to wyj�cie z p�tli i zako�czenie programu.
	
	while(isRunning) {
		c = _getch();
		
		switch(c) {
			case 'i': break;
			case 'f': f->getReward(itemsOnTheGround); break;
			case 'q': isRunning = false;
		}
	}
	
	system("pause");
	return 0;
}
