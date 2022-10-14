#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <conio.h>
using namespace std;

class Item {
protected:
	string name = "";
	int price = 0;
public:
	Item(string name, int price = 0) {
		this->name = name;
		this->price = price;
	}
	string getName() {
		return this->name;
	}
	int getPrice() {
		return this->price;
	}
	void setName(string name) {
		this->name = name;
	}
	void setPrice(int price) {
		this->price = price;
	}
};

class Weapon : public Item {
private:
	int damage = 0;
public:
	Weapon(string name, int damage, int price = 0) :Item(name, price)
	{
		this->damage = damage;
	}
	int getDamage() {
		return this->damage;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	void printInfo() {
		cout << name << ".  Damage:  " << damage << "  Price:  " << price;
	}
};

class Armor : public Item {
private:
	int defence = 0;
public:
	Armor(string name, int defence, int price = 0) :Item(name, price)
	{
		this->defence = defence;
	}
	int getDefence() {
		return this->defence;
	}
	void setDefence(int defence) {
		this->defence = defence;
	}
	void printInfo() {
		cout << name << ".  Defence:  " << defence << "  Price:  " << price;
	}
};
class Person {
protected:
	string name = "";
	int health = 0, healthMax = 0;
	int energy = 0, energyMax = 0;
	int level = 1;

public:
	Person(string name, int level, int health, int energy) {
		this->name = name;
		this->level = level;
		this->health = health;
		this->healthMax = health;
		this->health = health;
		this->energy = energy;
		this->energyMax = energy;
	}

	int getLevel() {
		return this->level;
	}
	int getHP() {
		return health;
	}
	int getHPMax() {
		return healthMax;
	}
	int getEnergy() {
		return energy;
	}
	int getEnergyMax() {
		return energy;
	}
	string getName() {
		return name;
	}
	void setLevel(int level) {
		this->level = level;
	}
	void setHP(int health) {
		this->health = health;
	}
	void setHPMax(int healthMax) {
		this->healthMax = healthMax;
	}
	void setEnergy(int energy) {
		this->energy = energy;
	}
	void setEnergyMax(int energyMax) {
		this->energyMax = energyMax;
	}
};


class Player : public Person {
private:
	int strength = 0;
	int agility = 0;
	int endurance = 0;
	int experience = 0;
	int experienceMax = 100;
	int cash = rand() % 20;
	Weapon* weapon = NULL;
	Armor* armor = NULL;

public:
	Player(string name, int hp, int en, int str, int ag, int end, Weapon* weapon) : Person(name, 1, hp, en) {
		strength = str;
		agility = ag;
		endurance = end;
		this->weapon = weapon;
		this->armor = new Armor("None", 0, 0);
	}

	int getStr() {
		return strength;
	}
	int getAgility() {
		return agility;
	}
	int getEndurance() {
		return endurance;
	}
	int getExperience() {
		return experience;
	}
	int getExperienceMax() {
		return experienceMax;
	}
	int getCash() {
		return(this->cash);
	}
	Weapon* getWeapon() {
		return this->weapon;
	}
	Armor* getArmor() {
		return this->armor;
	}
	void setStr(int str) {
		this->strength = str;
	}
	void setAgility(int agility) {
		this->agility = agility;
	}
	void setEndurance(int endurance) {
		this->endurance = endurance;
	}

	void setCash(int money) {
		this->cash = money;
	}
	void setWeapon(Weapon* weapon) {
		this->weapon = weapon;
	}
	void setArmor(Armor* armor) {
		this->armor = armor;
	}

	void regeneration(int regenerate) {
		health += regenerate;
		cout << "Regenerated " << regenerate << " HP.\n";
		if (health > healthMax) {
			health = healthMax;
		}
	}

	void giveExperience(int exp) {
		experience += exp;
		while (experienceMax <= experience) {

			experience -= experienceMax;
			levelUp();
		}
	}
	void levelUp() {
		level += 1;
		experienceMax += 90 + rand() % 21;
		healthMax += rand() % 10;
		energyMax += rand() % 10;
		strength += rand() % 4;
		endurance += rand() % 4;
		agility += rand() % 4;
		cout << "You level increased.("<<level<<")\n";
	}

	int generateDamage() {
		int damage = weapon->getDamage() + strength;
		int critChance = (agility + level) / 3;

		if ((rand() % agility) <= critChance) {
			damage += agility;
		}

		return damage * 2 / 3;
	}

	int generateDefence(int damage) {

		return damage - (endurance + armor->getDefence()) / 3;
	}
};

class Monster : public Person {
private:
	int damage = 0;
	int defence = 0;
	int experience = 0;
	int money = 0;
public:
	Monster(string name, int hp, int en, int dmg, int def, int lvl, int exp, int money) : Person(name, lvl, hp, en) {
		damage = dmg;
		defence = def;
		experience = exp;
		this->money = money;
	}

	int getDamage() {
		return this->damage * 2 / 3;
	}
	int getDefence() {
		return this->defence;
	}
	int getExperience() {
		return this->experience;
	}
	int getMoney() {
		return this->money;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	void setDefence(int defence) {
		this->defence = defence;
	}
	void setExperience(int experience) {
		this->experience = experience;
	}
	int generateDefence(int damage) {

		return damage - (defence) / 3;
	}

};

class Engine {
private:
	vector <string> monsterNames = { "Bogeyman","Vampire","Zombie", "Hydra","Chimera","Yeti","Dragon","Basilisk","Werewolf", "Gorgon" };
	vector <string> armorNames = { "Leather Armor", "Golden Armor","Bronze Armor","Black Armor" };
	vector <string> weaponNames = { "Sword", "Dagger", "Pike", "Axe", "Spear" };

	
public:
	int random(int min, int max) {
		return min + rand() % (max - min + 1);
	}
	Player* createPlayer(string name, int category) {

		int str = random(4, 7), ag = random(4, 7), end = random(4, 7);
		switch (category)
		{
		case 1:
			str += random(2, 5);
			break;
		case 2:
			end += random(2, 5);
			break;
		case 3:
			ag += random(2, 5);
			break;
		}

		return new Player(name, random(25, 50), random(25, 50), str, ag, end, createWeapon(1));
	}

	Monster* createMonster(int lvl) {

		if (lvl > 1) {
			lvl += this->random(-1, 1);
		}
		else {
			lvl += this->random(0, 1);
		}

		int dmg = this->random(2, 10) + lvl * random(2, 4);
		int def = this->random(2, 10) + lvl * random(2, 4);
		int hp = this->random(20, 30) + lvl * random(5, 10);
		int en = this->random(5, 15) + lvl * random(5, 10);
		int exp = this->random(5, 40) + lvl * random(10, 25);
		int money = this->random(2, 7) + lvl * random(3, 5);

		return new Monster(this->monsterNames[random(0, this->monsterNames.size())], hp, en, dmg, def, lvl, exp, money);
	}

	void fight(Player* player, Monster* monster) {
		cout << "You met a " << monster->getName() << endl;
		do {
			int playerDamage = monster->generateDefence(player->generateDamage());
			cout << "You dealed monster " << playerDamage << ".\n";
			monster->setHP(monster->getHP() - playerDamage);
			int monsterDamage = player->generateDefence(monster->getDamage());
			cout << "Monster dealed you " << monsterDamage << ".\n";
			player->setHP(player->getHP() - monsterDamage);
		} while (monster->getHP() > 0 && player->getHP() > 0);
		if (player->getHP() <= 0) {
			cout << "You lost\n";
		}
		else
		{
			cout << "You won\n"<<
				"You get "<< monster->getExperience()<<"EXP and "<< monster->getMoney()<<"$.\n";
			
			player->giveExperience(monster->getExperience());
			player->setCash(player->getCash() + monster->getMoney());
		}
	}

	Weapon* createWeapon(int lvl) {
		int dmg = random(lvl * 2 + 1, lvl * 2 + 20);
		return new Weapon(this->weaponNames[random(0, this->weaponNames.size() - 1)], dmg, dmg + random(0, lvl / 3));
	}
	Armor* createArmor(int lvl) {
		int def = random(lvl * 2 + 3, lvl * 2 + 20);
		return new Armor(this->armorNames[random(0, this->armorNames.size() - 1)], def, def + random(0, lvl / 3));
	}

};

class Event {
private:
	Engine* engine = NULL;
	Player* player = NULL;
	vector <Armor*> armorShop = {};
	vector <Weapon*> weaponShop = {};

	void buyItem() {
		int itemNumber;
		cout << "What would you like to buy?(enter number)\n";
		cin >> itemNumber;
		if (itemNumber > armorShop.size()) {
			Weapon* weapon = weaponShop[itemNumber - armorShop.size() - 1];
			if (enoughMoney(weapon->getPrice())) {
				player->setWeapon(weapon);
				player->setCash(player->getCash() - weapon->getPrice());
				cout << "You've bought " << weapon->getName() << " for " << weapon->getPrice() << endl;
			}
			else {
				cout << "You don't have enough money";
			}
		}
		else if (itemNumber > 0) {
			Armor* armor = armorShop[itemNumber - 1];
			if (enoughMoney(armor->getPrice())) {
				player->setArmor(armor);
				player->setCash(player->getCash() - armor->getPrice());
				cout << "You've bought " << armor->getName() << " for " << armor->getPrice() << endl;
			}
			else {
				cout << "You don't have enough money";
			}
		}
		else {
			cout << "Unknown item";
		}
	}

	bool enoughMoney(int price) {
		if (price <= player->getCash()) {
			return true;
		}
		return false;
	}
public:
	Event(Player* player, Engine* engine) {
		this->player = player;
		this->engine = engine;
	}

	void shop(int itemsCount) {
		this->armorShop.clear();
		this->weaponShop.clear();
		int armorCount = 1 + rand() % (itemsCount - 1);
		int itemNumber = 0;
		int count = 0;
		while (count < armorCount) {
			Armor* armor = this->engine->createArmor(this->player->getLevel());
			this->armorShop.push_back(armor);
			count++;
		}
		count = 0;
		while (count < itemsCount - armorCount) {
			Weapon* weapon = engine->createWeapon(this->player->getLevel());
			weaponShop.push_back(weapon);
			count++;

		}
		if (armorShop.size() != 0) {
			cout << "========Armor========\n";
			for (int i = 0; i < armorShop.size(); i++) {
				cout << i + 1 << " -> ";
				armorShop[i]->printInfo();
				cout << endl;
			}
		}
		if (weaponShop.size() != 0) {
			cout << "========Weapon========\n";
			for (int i = 0; i < weaponShop.size(); i++) {
				cout << i + armorShop.size() + 1 << " -> ";
				weaponShop[i]->printInfo();
				cout << endl;
			}
		}
		cout << "Your cash: "<<player->getCash()<<"\nYour weapon: ";
		player->getWeapon()->printInfo();
		cout << "\nYour armor: ";
		player->getArmor()->printInfo();
		cout << endl;
		cout << "Would you like to buy something?(yes or no)\n";
		string answer = "";
		cin >> answer;

		transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c) { return tolower(c); });
		if (answer == "yes") {
			buyItem();
		}
	}
	void meetMonster() {
		Monster* monster = this->engine->createMonster(this->player->getLevel());
		engine->fight(player, monster);
	}

	void hunting() {
		int eventNumber = 1 + rand() % 2;
		switch (eventNumber)
		{
		case 1:
			cout << "You caught a hare in the forest. \n";
			player->setAgility(player->getAgility() + rand() % 4);
			player->setEndurance(player->getEndurance() + rand() % 4);
			break;
		case 2:
			cout << "You defeated a bear in the forest. \n";
			player->setStr(player->getStr() + rand() % 4);
		default:
			break;
		}

	}

};

class SaveLoad {
public:
	Player* load() {
		Player* player = NULL;
		ifstream load;
		load.open("playerBase.txt");
		load.read((char*)&player, sizeof(Player));
		load.close();
		return player;
	}
	void save(Player* player) {
		ofstream save;
		save.open("playerBase.txt");
		save << player;
		save.close();
	}
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	SaveLoad* saveLoad = new SaveLoad();
	Engine* engine = new Engine();
	Player* player = NULL;
	Event* event = NULL;
	//player=saveLoad->load();
	if (player == NULL) {
		string name = "";
		int category = 0;

		cout << "Enter player name: ";
		cin >> name;

		cout << "Choose your class: 1-Barbarian, 2-Tank, 3-Rogue:" << endl;
		cin >> category;

		if (category < 1 || category > 3) {
			cout << "Error!";
			return 0;
		}

		player = engine->createPlayer(name, category);
		
	}
	event = new Event(player, engine);

	do {
		int eventChance = rand() % 100;
		if (eventChance < 5) {
			//event->shop(engine->random(3,7));
		}
		else if (eventChance < 45) {
			event->meetMonster();
		}
		else if (eventChance<70)
		{
			event->hunting();
		}
		else
		{
			cout << "...\n";
		}


		if (player->getHP() < 0) {
			cout << "You died.";
			saveLoad->save(NULL);
			return 1;
		}
		player->regeneration(engine->random(player->getHP() / 5, player->getHP() /2));
		cout << "Press ESC to stop game or press any other key to continue.\n";
	} while (_getch()!=27);
	saveLoad->save(player);

	return 1;
}
