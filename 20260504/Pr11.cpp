#include <iostream>
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
		this->speed = v < 0 ? 0 : speed;
		all_t += v;
	}
	virtual void show() {
		printf("\n*** SHOW Name: %s ***\nTonnazh: %.3f\nSpeed: %.3f\n", name.c_str(), v, speed);
	}
};

class Sailbot : public Ship {
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
class Steamship : public Ship {
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
	Corvet(string name = "", float v = 0, float speed = 0, int mast = 1, int gun = 0) : Sailbot(name, v, speed, mast) {
		this->gun = gun < 0 ? 0 : gun;
	}
	Corvet(string name = "", float v = 0, float speed = 0, double power = 0, int gun = 0) : Steamship(name, v, speed, power) {
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
	s1.show();
	Sailbot s2("Галка", 2000, 10, 3);
	s2.show();
	Steamship s3("Титаник", 2000, 27, 55000);
	s3.show();
	Corvet s4("Адмирал Нахимов", 500, 33, 30000.0, 3), s5("Марат", 4000, 24, 1, 6);
	s4.show();
	s5.show();
	cout << "All tonnazh: " << Ship::all_t << endl;
}