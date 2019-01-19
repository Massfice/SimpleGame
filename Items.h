//Plik zawieraja struktury przedmiotów, listy przedmiotów (itemów), a tak¿e metody modyfikuj¹ce strukturê listy przedmiotów.

//Struktura przedmiotów.
struct Item {
	int id; //Parametr ten okreœla identyfikator (id) danego przedmiotu lub ID opcji. Nie stworzono jeszcze ¿adnych przedmiotów, wiêc póki co
			//parametr ten bêdzie okreœla³ iloœæ miejsca w ekwipunku zajmowan¹ przez przedmiot.
	string name; //Nazwa danego przedmiotu.
};

//Struktura listy przedmiotów: (Lista dwukierunkowa, cykliczna)
struct ItemList {
	Item* item; //Przedmiot.
	ItemList* next; //Parametr ten jest wskaŸnikiem na nastêpny przedmiot na liœcie.
	ItemList* prev; //Parametr ten jest wskaŸnikiem na poprzedni przedmiot na liœcie.
	ItemList* begin; //Parametr ten okresla pocz¹tek listy.
};
		

class Items {
		public:
		
		//Metoda wyboru nastêpnego przedmiotu na liœcie:
		void nextItem(ItemList* & il) {
			il = il->next; //Wybór nastêpnego przedmiotu.
		}
		
		//Metoda wyboru poprzedniego przedmiotu na liœcie:
		void prevItem(ItemList* & il) {
			il = il->prev;
		}
		
		//Metoda ustawiaj¹ca wskaŸnik listy na pocz¹tku:
		void seekBegin(ItemList* & il) {
			il = il->begin; //Ustaw wskaŸnik listy na pocz¹tku.
		}
		
		//Metoda ustawiaj¹ca wskaŸnik listy na koñcu:
		void seekEnd(ItemList* & il) {
			seekBegin(il); //Ustaw wskaŸnik listy na pocz¹tku.
			prevItem(il); //"Cofamy siê o jedn¹ pozycjê w ty³ (do ostatniego elementu).
		}
			
		//Metoda dodaj¹ca itemy do listy:
		void addItem (ItemList* & il, Item* item) {
			if(il == NULL) { //Je¿eli lista przedmiotów nie istnieje (jest NULLem):
				il = new ItemList; //Stwórz now¹ listê.
				il->item = item; //Zapisz przedmiot na liœcie.
				il->next = il; //Nastêpny przedmiot na liœcie, to ten sam, który w³aœnie zosta³ dodany (innego jeszcze nie by³o).
				il->prev = il; //Poprzedni przedmiot na liœcie, to ten sam, który w³aœnie zosta³ dodany (innego jeszcze nie by³o).
				il->begin = il; //Pocz¹tek listy.
			} else { //Jeœli lista przedmiotów istnieje (nie jest NULLem):
				seekEnd(il); //PrzejdŸ na koniec listy.
				ItemList* temp = new ItemList; //Stwórz zmienn¹ pomocnicz¹.
				temp->item = item; //Zapisz item.
				temp->begin = il->begin; //Pocz¹tek zawsze zostaje bez zmian.
				temp->prev = il; //Stworzony element staje siê ostatnim na liœcie, wiêc jego poprzednik musi byæ przedostatnim.
				temp->next = il->begin; //Stworzony element staje siê ostatnim na liœcie, a wiêc jego nastêpnik musi byæ pierwszym.
				il->next = temp; //Ostatni element na liœcie staje siê przedostatnim, a wiêc jego nastêpnik musi byæ ostatnim.
				il->begin->prev = temp; //Poprzednik pierwszego elementu na liœcie jest ostatnim elementem.
			}
		}
		
		//Metoda usuwaj¹ca aktywny przedmiot z listy:
		void remItem(ItemList* & il) {
			if(il != NULL) { //Usuwamy przedmiot, jedynie, jesli lista nie jest pusta (nie jest NULLem).
				if(il == il->next && il == il->prev) { //Je¿eli na liœcie jest tylko jeden przedmiot:
					delete il; //(1)
					il = NULL; //(2)
					
					//(1) i (2): Usuwamy listê i ustawiamy j¹ na NULL.
				} else { //Je¿eli na liœcie jest wiêcej ni¿ 1 przedmiot:
					ItemList* temp = il; //Tworzymy zmienn¹ pomocnicz¹.
					
						if(il == il->begin) { //Je¿eli usuwany element jest pocz¹tkiem listy:
						
							do {
								il->begin = il->begin->next; //Nowym pocz¹tkiem staje siê nastêpnik starego pocz¹tku.
								nextItem(il); //PrzejdŸ do nastêpnego przedmiotu.
							} while(il != temp);
						
						}
					
					il->prev->next = il->next; //(1)
					il->next->prev = il->prev; //(2)
					
					//(1) i (2): "Omijamy" bie¿¹cy element.
					
					il = il->next; //Nowa lista - nastêpny element.
					delete temp; //(3)
					temp = NULL; //(4)
					
					//(3) i (4): Usuwamy element i ustawiamy go na NULL.
					
				}
			}
		}		
};

Items* items = new Items();
