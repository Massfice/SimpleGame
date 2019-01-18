//Plik zawiera klasê u¿ywan¹ podczas walki z przeciwnikami.

#include "header.h" //Do³¹czamy nag³ówek. Dziêki temu nag³ówek wystarczy zmodyfikowaæ raz i bêdzie mia³o to wp³yw na wszystkie pliki z nag³ówkiem.

class Fight {
	
	private:
		
		int &liczba;
	
	public:
		
		Fight(int &liczba) : liczba(liczba){}
		
		void inc() {
			liczba = liczba + 2;
		}
};
