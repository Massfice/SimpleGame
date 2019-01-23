//Plik zawiera struktur� przeciwnika.

struct Enemy {
	int id; //Identyfikator przeciwnika.
	string name; //Nazwa przeciwnika.
	ItemList* il; //Przedmioty, kt�re przeciwnik posiada.
};

//Metoda zliczaj�ca przeciwnik�w. Po stworzeniu listy przeciwnik�w (Enemy** enemies) na koniec listy nale�y doda� "NULL".
int countEnemies(Enemy** enemies) {
	int i = 0;
	while(enemies[i] != NULL) i++;
	return i;
}
