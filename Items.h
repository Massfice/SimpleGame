//Plik zawieraja struktury przedmiot�w, listy przedmiot�w (item�w), a tak�e metody modyfikuj�ce struktur� listy przedmiot�w.

//Struktura przedmiot�w.
struct Item {
	int id; //Parametr ten okre�la identyfikator (id) danego przedmiotu lub ID opcji. Nie stworzono jeszcze �adnych przedmiot�w, wi�c p�ki co
			//parametr ten b�dzie okre�la� ilo�� miejsca w ekwipunku zajmowan� przez przedmiot.
	string name; //Nazwa danego przedmiotu.
};

//Struktura listy przedmiot�w: (Lista dwukierunkowa, cykliczna)
struct ItemList {
	Item* item; //Przedmiot.
	ItemList* next; //Parametr ten jest wska�nikiem na nast�pny przedmiot na li�cie.
	ItemList* prev; //Parametr ten jest wska�nikiem na poprzedni przedmiot na li�cie.
	ItemList* begin; //Parametr ten okresla pocz�tek listy.
};
		

class Items {
		public:
		
		//Metoda wyboru nast�pnego przedmiotu na li�cie:
		void nextItem(ItemList* & il) {
			il = il->next; //Wyb�r nast�pnego przedmiotu.
		}
		
		//Metoda wyboru poprzedniego przedmiotu na li�cie:
		void prevItem(ItemList* & il) {
			il = il->prev;
		}
		
		//Metoda ustawiaj�ca wska�nik listy na pocz�tku:
		void seekBegin(ItemList* & il) {
			il = il->begin; //Ustaw wska�nik listy na pocz�tku.
		}
		
		//Metoda ustawiaj�ca wska�nik listy na ko�cu:
		void seekEnd(ItemList* & il) {
			seekBegin(il); //Ustaw wska�nik listy na pocz�tku.
			prevItem(il); //"Cofamy si� o jedn� pozycj� w ty� (do ostatniego elementu).
		}
			
		//Metoda dodaj�ca itemy do listy:
		void addItem (ItemList* & il, Item* & item) {
			if(il == NULL) { //Je�eli lista przedmiot�w nie istnieje (jest NULLem):
				il = new ItemList; //Stw�rz now� list�.
				il->item = item; //Zapisz przedmiot na li�cie.
				il->next = il; //Nast�pny przedmiot na li�cie, to ten sam, kt�ry w�a�nie zosta� dodany (innego jeszcze nie by�o).
				il->prev = il; //Poprzedni przedmiot na li�cie, to ten sam, kt�ry w�a�nie zosta� dodany (innego jeszcze nie by�o).
				il->begin = il; //Pocz�tek listy.
			} else { //Je�li lista przedmiot�w istnieje (nie jest NULLem):
				seekEnd(il); //Przejd� na koniec listy.
				ItemList* temp = new ItemList; //Stw�rz zmienn� pomocnicz�.
				temp->item = item; //Zapisz item.
				temp->begin = il->begin; //Pocz�tek zawsze zostaje bez zmian.
				temp->prev = il; //Stworzony element staje si� ostatnim na li�cie, wi�c jego poprzednik musi by� przedostatnim.
				temp->next = il->begin; //Stworzony element staje si� ostatnim na li�cie, a wi�c jego nast�pnik musi by� pierwszym.
				il->next = temp; //Ostatni element na li�cie staje si� przedostatnim, a wi�c jego nast�pnik musi by� ostatnim.
				il->begin->prev = temp; //Poprzednik pierwszego elementu na li�cie jest ostatnim elementem.
			}
		}
		
		//Metoda usuwaj�ca aktywny przedmiot z listy:
		void remItem(ItemList* & il) {
			if(il != NULL) { //Usuwamy przedmiot, jedynie, jesli lista nie jest pusta (nie jest NULLem).
				if(il == il->next && il == il->prev) { //Je�eli na li�cie jest tylko jeden przedmiot:
					delete il; //(1)
					il = NULL; //(2)
					
					//(1) i (2): Usuwamy list� i ustawiamy j� na NULL.
				} else { //Je�eli na li�cie jest wi�cej ni� 1 przedmiot:
					ItemList* temp = il; //Tworzymy zmienn� pomocnicz�.
					
						if(il == il->begin) { //Je�eli usuwany element jest pocz�tkiem listy:
						
							do {
								il->begin = il->begin->next; //Nowym pocz�tkiem staje si� nast�pnik starego pocz�tku.
								nextItem(il); //Przejd� do nast�pnego przedmiotu.
							} while(il != temp);
						
						}
					
					il->prev->next = il->next; //(1)
					il->next->prev = il->prev; //(2)
					
					//(1) i (2): "Omijamy" bie��cy element.
					
					il = il->next; //Nowa lista - nast�pny element.
					delete temp; //(3)
					temp = NULL; //(4)
					
					//(3) i (4): Usuwamy element i ustawiamy go na NULL.
					
				}
			}
		}		
};

Items* items = new Items();
