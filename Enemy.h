//Plik zawiera strukturê przeciwnika.

struct Enemy {
	int id; //Identyfikator przeciwnika.
	string name; //Nazwa przeciwnika.
	ItemList* il; //Przedmioty, które przeciwnik posiada.
};

//Metoda zliczaj¹ca przeciwników. Po stworzeniu listy przeciwników (Enemy** enemies) na koniec listy nale¿y dodaæ "NULL".
int countEnemies(Enemy** enemies) {
	int i = 0;
	while(enemies[i] != NULL) i++;
	return i;
}
