//Plik zawiera klas� u�ywan� podczas walki z przeciwnikami.

#include "header.h" //Do��czamy nag��wek. Dzi�ki temu nag��wek wystarczy zmodyfikowa� raz i b�dzie mia�o to wp�yw na wszystkie pliki z nag��wkiem.

class Fight {
	
	private:
		
		int &liczba;
	
	public:
		
		Fight(int &liczba) : liczba(liczba){}
		
		void inc() {
			liczba = liczba + 2;
		}
};
