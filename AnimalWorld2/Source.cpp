#include<iostream>
using namespace std;

class Herbivore abstract
{
public:
	virtual void EatGrass() = 0;
};

class Carnivore abstract
{
public:
	virtual void Eat(Herbivore* a) = 0;
};

class Wildebeest :public Herbivore
{
public:
	void EatGrass() override
	{
		cout << "Wildebeest Eats grass";
	}
};
class Bison :public Herbivore
{
public:
	void EatGrass() override
	{
		cout << "Bison Eats grass";
	}
};

class lion :public Carnivore
{
public:
	void Eat(Herbivore* a) override
	{
		cout << "lion Eats meat";
	}
};
class Wolf :public Carnivore
{
public:
	void Eat(Herbivore* a) override
	{
		cout << "Wolf Eats meat";
	}
};

class Continent 
{
public:
	virtual Carnivore* CreateCarnivore() = 0;
	virtual Herbivore* CreateHerbivore() = 0;

};
class Africa :public Continent
{
	Carnivore* CreateCarnivore() {
		return new lion;
	}
	Herbivore* CreateHerbivore() {
		return new Bison;
	}
};

class NorthAmerica :public Continent
{
	Carnivore* CreateCarnivore() {
		return new Wolf;
	}
	Herbivore* CreateHerbivore() {
		return new Wildebeest;
	}
};

class AnimalWorld {
	Herbivore* h;
	Carnivore* c;
public:
	AnimalWorld(Continent*b) {
		h = b->CreateHerbivore();
		c = b->CreateCarnivore();
	}
	void MealsHerbivores() {
		h->EatGrass();
	}
	void MealsCarnivores() {
		c->Eat(h);
	}
};

int main() {
	Continent* a = new Africa();
	AnimalWorld* a1 = new AnimalWorld(a);
	a1->MealsHerbivores();
	a1->MealsCarnivores();

	delete a;
	delete a1;
}