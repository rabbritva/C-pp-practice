#include <iostream>
#include <string>
using namespace std;

class Ship {
	string name;
	float v;
	float speed;
public:
	static float all_t;
	Ship(string name = "", float v = 0, float speed = 0) {
		this->name = name;
		this->v = v < 0 ? 0 : v;
		this->speed = speed < 0 ? 0 : speed;
		all_t += v;
	}
	virtual void show() {
		printf("\n*** SHOW Name: %s ***\nTonnazh: %.3f\nSpeed: %.3f\n", name.c_str(), v, speed);
	}
};

class Sailbot : virtual public Ship {
	int mast;
public:
	Sailbot(string name = "", float v = 0, float speed = 0, int mast = 1) : Ship(name, v, speed) {
		this->mast = max(mast, 0);
	}
	void show() {
		Ship::show();
		printf("Mast: %i\n", mast);
	}
	int get_mast() { return mast; }
};
class Steamship : virtual public Ship {
	float power;
public:
	Steamship(string name = "", float v = 0, float speed = 0, float power = 0) : Ship(name, v, speed) {
		this->power = power < 0 ? 0 : power;
	}
	void show() {
		Ship::show();
		printf("Power: %.3f\n", power);
	}
	float get_power() { return power; }
};
class Corvet : public Steamship, public Sailbot {
	int gun;
public:
	Corvet(string name = "", float v = 0, float speed = 0, int mast = 1, int gun = 0) :
	Ship(name, v, speed), Sailbot(name, v, speed, mast) {
		this->gun = gun < 0 ? 0 : gun;
	}
	Corvet(string name = "", float v = 0, float speed = 0, double power = 0, int gun = 0) :
	Ship(name, v, speed),Steamship(name, v, speed, power) {
		this->gun = gun < 0 ? 0 : gun;
	}
	void show() {
		if (get_power()) {
			Steamship::show();
			printf("Gun: %i\n", gun);
		}
		else {
			Sailbot::show();
			printf("Gun: %i\n", gun);
		}
	}
};
float Ship::all_t = 0;

int main() {
	setlocale(LC_ALL, "");
	Ship s1("Черная жемчужина", 200, 25);

	Sailbot s2("Галка", 2000, 10, 3);

	Steamship s3("Титаник", 2000, 27, 55000);

	Corvet s4("Адмирал Нахимов", 500, 33, (double)30000.0, 3),
	s5("Марат", 4000, 24, 1, 6);

	Ship* flot[] = {&s1, &s2, &s3, &s4, &s5, new Corvet("Test_ship", 200, 25, 2, 16) };
	for (auto i: flot) {
		i->show();
	}
	cout << "\nAll tonnazh: " << Ship::all_t << endl;
}