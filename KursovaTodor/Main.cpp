#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
class ArrayList {
	int index = -1;
	int size = 0;
	int* glasuvali;


public:
	//ArrayList() {}


	void add(int glasove) {
		
		if (size == 0) {
			size += 1;
			glasuvali = (int*)calloc(size,sizeof(int));
			
		}else if (index == size - 1) {
			size += 1;
			glasuvali = (int*)realloc(glasuvali, (size) * sizeof(int));
		

		}
		index++;
		glasuvali[index] = glasove;








	}

	int replace(int index,int value) {
		if (index >= size) return 0;
		
		if (glasuvali[index] = value) {
			return 1;
		}
		return 0;
		
	}

	int Size() {
		return size;
	}

	int get(int index) {
		if (index >= size)return NULL;

		return glasuvali[index];
	}

};


class IzbiratelenRaion {
	char* name;
	int glasopodavateli;
	int ostavashtiGlasobodavateli;
	const int partii = 5;
	ArrayList* glasuvali = new ArrayList();
	const char* imenaNaPartii[5] = {"GERB","VMRO","BZNS","GORD","GOR"};

	int index = 0;

public:
	IzbiratelenRaion(char* name,int glasopodavateli) {
		this->name = name;
		this->glasopodavateli = glasopodavateli;
		
		this->ostavashtiGlasobodavateli = glasopodavateli;
		
		for (int i = 0; i < partii; i++) {
			glasuvali->add(0);
		}
		

	}

	
	void addGlas(int index,int glasove) {
		
		
	


		if (glasove > ostavashtiGlasobodavateli) {
			glasove = ostavashtiGlasobodavateli;
			
		}
		
		if (index >= partii)return;
		
		
		glasuvali->replace(index, glasuvali->get(index) + glasove);
		
		
		ostavashtiGlasobodavateli -= glasove;
		

	}
	void addGlas(char* imeNaPartia,int glasove) {
		for (int i = 0; i < partii;i++)
		{
			if (compareString(imeNaPartia, imenaNaPartii[i]) == 0) {
				addGlas(i,glasove);
				break;
			}
		
		}
	}
	void procentGlasuvaliZaVsqkaPartia() {
		cout << name<<":\n";
		for (int i = 0; i < partii; i++) {
			
			cout << imenaNaPartii[i] << ":" << glasuvali->get(i) *100/ glasopodavateli <<"%"<< endl;
		}
		cout << endl;
	}
	int bezPopeditel() {
		int check = 1;
		for (int i = 1; i < partii; i++) {
			if (glasuvali->get(0) * 100 / glasopodavateli == glasuvali->get(i) * 100 / glasopodavateli) {
				check = 0;
			}
			else {
				check = 1;
				break;
			}
			
		}
		return check;
	}
	int getPartiiSize() {
		return partii;
	}

	int getGlasopodavateli(){
		return glasopodavateli;
	}
	int getOstavashtiGlasove() {
		return ostavashtiGlasobodavateli;
	}
	char* getName() {
		return name;
	}
	ArrayList* getListSusGlasove() {
		return glasuvali;
	}

	const char** getImenaNaParii() {
		return imenaNaPartii;
	}
	


private:
	int compareString(char* first, const char* second)
	{
		while (*first == *second)
		{
			if (*first == '\0' || *second == '\0')
				break;

			first++;
			second++;
		}
		if (*first == '\0' && *second == '\0')
			return 0;
		else
			return -1;
	}
	friend ostream& operator<<(ostream& os, const IzbiratelenRaion* dt);
};
ostream& operator<<(ostream& os, const IzbiratelenRaion* ir)
{
	os << "Ime:" << ir->name << "\nGlasopodavateli:" << ir->glasopodavateli << endl;
	os << "Ostavashti glasove:" << ir->ostavashtiGlasobodavateli << endl;
	
	for (int i = 0; i < ir->glasuvali->Size(); i++) {
		
		os << ir->imenaNaPartii[i] << ":" << ir->glasuvali->get(i) * 100 / ir->glasopodavateli << "%" << endl;

	}
	os << endl;
	return os;
}

int main(){
	IzbiratelenRaion** raioni = new IzbiratelenRaion*[100];
	int index = 0;

	ofstream file;
	file.open("bezPobeditel.txt");

	ofstream r;
	r.open("raioni.txt");
	
	
	int n;
	do {

		cout << endl << "1.Dobavi Raion" << endl;
		cout << "2.Dobavi glas kum daden raion i partiq" << endl;
		cout << "3.Printiraj procenta na glasuvalite po azbuchen red sprqmo imeto na raiona" << endl;
		cout << "4.Zapishi vuv fajl imenata na raionite v koito nqma pobedtel i procenta na neglasuvalite" << endl;


		cout << "Vuvedi chislo:";
		cin >> n;


		switch (n) {
		case 1:
		{
			if (index == 100) {
				cout << "Previshixte limita";
				break;
			}
			
			int br;
		
			string text;
			cout << "Dobavi Ime:";
			cin >> text;
			cout<< "Dobavi broj glasobodavateli:";
			cin >> br;

			char* cstr = new char[text.length() + 1];
			
			#pragma warning(suppress : 4996)
			strcpy(cstr, text.c_str());

			
			raioni[index] = new IzbiratelenRaion(cstr,br);
			index++;
			

		}
			break;
		case 2:
		{
			if (index == 0)break;
			
			int n;
			int n1;
			int glas;
			
			for (int i = 0; i < index ; i++) {
					cout << i + 1 << "." << raioni[i]->getName()<<endl;
				}
				do {
					cout << "Izberi chislo:";
					cin >> n;
				} while (n<1 || n>index);
				
				for (int i = 0; i < 5; i++) {
					cout << i + 1 << "." << raioni[0]->getImenaNaParii()[i] << endl;
				}
				do {
					cout << "Izberi chislo:";
					cin >> n1;
				} while (n1<1 || n1>5);
				
				cout << "Kolko glasa:";
				cin >> glas;
				raioni[n-1]->addGlas(n1-1,glas);
				



		}
		break;
		case 3:
			IzbiratelenRaion * temp;
			for (int i = 0; i < index; i++)
			{

				for (int j = i; j < index; j++)
				{
					if (raioni[i]->getName()[0] > raioni[i]->getName()[0])
					{
						temp = raioni[j];
						raioni[j] = raioni[i];
						raioni[i] = temp;


					}
				}


			}
			for (int i = 0; i < index; i++) {
				raioni[i]->procentGlasuvaliZaVsqkaPartia();
			}
			break;
		case 4:
			for (int i = 0; i < index; i++) {
				if(raioni[i]->bezPopeditel()==0)
				file << raioni[i]->getName() << endl;
				file << raioni[i]->getOstavashtiGlasove()*100/ raioni[i]->getGlasopodavateli() <<"%"<< endl;
			}
			break;
		}
	} while (n >= 1 && n < 5);

	
	for (int i = 0; i < index; i++) {
		r << raioni[i];
	}
	
	
	file.close();
	r.close();
	


	return 0;
}

