#include <iostream>
#include<string>
#include <map> // map + multimap
#include <list>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

typedef map<int, std::string> GAI;

const GAI CRIMES = {
	{0,"N/A"},
	{1,"Проезд на красный"},
	{2,"Превышение скорости"},
	{3,"Парковка в неположенном месте"},
	{4,"Пересечение сплошной"},
	{5,"Езда в нетрезвом состоянии"},
	{6,"Оскорбление сотрудника полиции"},
	{7,"Ремень безопасности"}
};

class Crime {
	int id; // Статья
	std::string place; // Место правонарушения
public:

	void set_id(int id) {
		if (id > CRIMES.size()) {
			id = 0;
		}
		this->id = id;
	}
	int get_id()const {
		return id;
	}


	void set_place(const std::string& place) {
		this->place = place;
	}
	const std::string& get_place()const {
		return place;
	}
	
	Crime(int id, const std::string& place) {
		set_id(id);
		set_place(place);
	}
	~Crime() {}

};


std::ostream& operator<< (std::ostream& os, const Crime& obj) {
	return os << obj.get_id() << "\t" << obj.get_place();
}

typedef map<string, std::list<Crime>> BASE;

void show(BASE m1) {
	GAI::iterator cr;
	BASE::iterator it;
	list<Crime>::iterator it2;
	map<int, std::string> it3;
	for (it = m1.begin(); it != m1.end(); ++it) {
		cout << it->first;

		for (it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
			cout << tab << "Нарушение пункта - " << it2->get_id();
			if (cr->first == it2->get_id()) {
				cout << cr->second;
			}
			cout << "," << tab << "на месте - " << it2->get_place() << ".\n";
		}cout << endl;
		
	}cout << endl;
	
}

int main() // ~Ассоциативные контейнеры
{
	setlocale(0, "");
	
	BASE base = {
		{"m777ab",	{Crime(1,"ул.Ленина"),			Crime(2,"ул.Ленина"),		Crime(4,"ул.Парижской коммунны")}	},
		{"k231cc",	{Crime(5,"ул.Карла Маркса"),	Crime(6,"ул.Карла Маркса")}										},
		{"o000o",	{Crime(3,"ул.Пролетарская"),	Crime(7,"ул.Пролетарская")}										}
	};

	show(base);

}
