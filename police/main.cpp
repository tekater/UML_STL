#include <iostream>
#include <fstream>
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
	return os << CRIMES.at(obj.get_id()) << "\t" << obj.get_place();
}
std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj) {
	ofs << obj.get_id() << "\t" << obj.get_place();
	return ofs;
}
typedef map<string, std::list<Crime>> BASE;

void print(BASE m1) {
	BASE::iterator it;
	list<Crime>::iterator it2;
	for (it = m1.begin(); it != m1.end(); ++it) {
		cout << it->first;

		for (it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
			cout << tab << "Нарушение пункта - " << it2->get_id();
			cout << " " << CRIMES.at(it2->get_id()) << tab;
			cout << "," << tab << "на месте - " << it2->get_place() << ".\n";
		}cout << endl;

	}cout << endl;

	/*for (std::pair<std::string, list<Crime>> i : m1) {
		cout << i.first << ":\n";
		for (Crime j : i.second) {
			cout << tab << j << endl;
		}
		cout << endl;
	}*/
}

void save(const BASE& base, const std::string& filename) {
	std::ofstream fout(filename);
	for (std::pair<std::string, std::list<Crime>> i : base) {
		fout << i.first << ":\t";
		for (Crime j : i.second) {
			fout << tab << j << "," ;
		}
		fout.seekp(-1,std::ios::cur); // смещаем курсор на позицию влево
		fout << ";\n";
	}
}
BASE load(const std::string filename) {
	BASE base;
	std::string license_plate;
	std::string all_crimes;

	std::ifstream fin(filename);
	if (fin.is_open()) {
		while (!fin.eof()) {
			std::getline(fin, license_plate, ':');
			if (license_plate.empty()) {
				continue;
			}
			fin.ignore();
			std::getline(fin, all_crimes);
			size_t start = 0;
			size_t end = all_crimes.find(',');
			while (end != std::string::npos) {
				end = all_crimes.find(',');
				std::string s_crime = all_crimes.substr(0, end);
				if (s_crime.empty()) {
					break;
				}
				int id = std::stoi(s_crime, nullptr, 10);
				s_crime.erase(0, s_crime.find_first_of(' ') + 1);
				base[license_plate].push_back(Crime(id, s_crime));
				all_crimes.erase(0, end + 1);
			}
		}
		fin.close();
		return base;
	}
}

int main() // ~Ассоциативные контейнеры
{
	setlocale(0, "");
	
	/*BASE base = {
		{"m777ab",	{Crime(1,"ул.Ленина"),			Crime(2,"ул.Ленина"),		Crime(4,"ул.Парижской коммунны")}	},
		{"k231cc",	{Crime(5,"ул.Карла Маркса"),	Crime(6,"ул.Карла Маркса")}										},
		{"o000o",	{Crime(3,"ул.Пролетарская"),	Crime(7,"ул.Пролетарская")}										}
	};*/
	BASE base = load("base.txt");
	print(base);
	//save(base, "base.txt");

	
}
