#include <iostream>

using namespace std;

class Stack
{
private:
	int* tablica; //tablica dynamiczna
	int sizestack; //rozmiar stosu
	int topstack; //wskaxnik na szczyt stosu

public:
	//Inicjalizacja stosu z okreslona pojemnoscia
	Stack(int size) {
		sizestack = size;
		tablica = new int[sizestack];
		topstack = -1; //Stos na poczatku jest pusty
	}
	//Destruktor
	~Stack() {
		delete[] tablica;  //zwalnianie pamieci tablicy 
	}
	bool Empty() //Sprawdza czy stos jest pusty
	{
		return topstack == -1;
	}
	bool Full() //funcja sprawdza czy stos jest pelny
	{
		return topstack == sizestack - 1;
	}

	void push(int value) //Funckja dodajaca kolejny element stosu
	{
		if (Full())
		{
			cout << "Stos jest pelny" << endl;
			return;
		}
		tablica[++topstack] = value;
	}

	void pop() //Funkcja usuwajaca element ze stosu
	{
		if (Empty())
		{
			cout << "Stos jest pusty" << endl;
			return;
		}
		--topstack;
	}
	void display()//Funkcja wyswietlajaca zawartosc stosu
	{
		cout << "Zawartosc stosu:" << endl;
		for (int i = topstack; i >= 0; i--)
		{
			cout << tablica[i] << " ";
		}
		cout << endl;
	}
};


int main()
{
	unsigned int size, choise;
	cout << "Podaj rozmiar stosu:" << endl;
	cin >> size;
	int value;

	Stack stack(size);

	do {
		cout << "Opcje do wyboru:" << endl;
		cout << "1. Dodawanie elementu na stos(push)" << endl;
		cout << "2. Usuwanie elementu ze stosu(pop)" << endl;
		cout << "3. Sprawdzenie, czy stos jest pusty" << endl;
		cout << "4. Sprawdzenie, czy stos jest pelny" << endl;
		cout << "5. Wyswietlenie zawartoœci stosu" << endl;
		cin >> choise;

		switch (choise)
		{
		case 1:
			cout << "Podaj wartosc elementu do dodania:" << endl;
			cin >> value;
			stack.push(value);
			break;
		case 2:
			stack.pop();
			break;
		case 3:
			if (stack.Empty())
			{
				cout << "Stos jest pusty" << endl;
			}
			else
			{
				cout << "Stos nie jest pusty" << endl;
			}
			break;
		case 4:
			if (stack.Full())
			{
				cout << "Stos jest pelny" << endl;
			}
			else
			{
				cout << "Stos nie jest pelny" << endl;
			}
			break;
		case 5:
			stack.display();
			break;
		case 0:
			cout << "Koniec programu" << endl;
			break;
		default:
			cout << "Niepoprawne dane, wybierz ponownie z menu prawidlow¹ wartosc:" << endl;
		}
	} while (choise != 0);

	return 0;
}