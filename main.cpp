#include <iostream>
#include <vector>
using namespace std;

class LandingVeg
{
public:
    virtual void info() const = 0;
    virtual ~LandingVeg() { }
};

//классы агро-дачных культур
class Potato : public LandingVeg
{
public:
    void info() const {
        cout << "Potato" << endl;
    }
};

class Onion : public LandingVeg
{
public:
    void info() const {
        cout << "Onion" << endl;
    }
};

class Corn : public LandingVeg
{
public:
    void info() const {
        cout << "Corn" << endl;
    }
};

class Berry : public LandingVeg
{
public:
    void info() const {
        cout << "Berry" << endl;
    }
};

class AppleTree : public LandingVeg
{
public:
    void info() const {
        cout << "AppleTree" << endl;
    }
};

class Plant
{
public:
    vector<vector<LandingVeg*> > chPlant;

    void info() const {
        for (size_t i = 0; i < chPlant.size(); ++i)
        {
            for (size_t j = 0; j < chPlant[i].size(); ++j)
                chPlant[i][j]->info();
        }
    }
};

// класс PlantBuilder объявляет интерфейс для построения огорода
class PlantBuilder
{
protected:
    Plant* p;
public:
    PlantBuilder(): p(0) {}
    virtual ~PlantBuilder() {}
    virtual void createPlant() {}
    virtual void buildPotato() {}
    virtual void buildOnion() {}
    virtual void buildCorn() {}
    virtual void buildBerry() {}
    virtual void buildAppleTree() {}
    virtual Plant* getPlant() { return p; }
};
//билдер для огорода Pомана
class RomanPlantBuilder : public PlantBuilder
{
public:
    void createPlant() { p = new Plant; }
    void buildPotato()
    {
        vector<LandingVeg*> vec;
        vec.push_back(new Potato());
        p->chPlant.push_back(vec);
    }

    void buildOnion()
    {
        vector<LandingVeg*> vec;
        vec.push_back(new Onion());
        p->chPlant.push_back(vec);
    }

    void buildCorn()
    {
        vector<LandingVeg*> vec;
        vec.push_back(new Corn());
        vec.push_back(new Corn());
        vec.push_back(new Corn());
        vec.push_back(new Corn());
        vec.push_back(new Corn());
        vec.push_back(new Corn());
        vec.push_back(new Corn());//так много кукурузы выросло, вы что Хрущева пародируете?:)
        p->chPlant.push_back(vec);
    }

    void buildBerry()
    {
        vector<LandingVeg*> vec;
        vec.push_back(new Berry());
        p->chPlant.push_back(vec);
    }
};
//билдер для моего огорода
class VladPlantBuilder : public PlantBuilder
{
public:
    void createPlant() { p = new Plant; }

    void buildOnion()
    {
        vector<LandingVeg*> vec;
        vec.push_back(new Onion());
        p->chPlant.push_back(vec);
    }

    void buildBerry()
    {
        vector<LandingVeg*> vec;
        vec.push_back(new Berry());
        p->chPlant.push_back(vec);
    }

    void buildAppleTree()
    {
        vector<LandingVeg*> vec;
        vec.push_back(new AppleTree());
        p->chPlant.push_back(vec);
    }
};

// Класс-распорядитель, здесь определен алгоритм построения огорода.
class Director
{
public:
    Plant* createPlant( PlantBuilder & builder )
    {
        builder.createPlant();
        builder.buildPotato();
        builder.buildOnion();
        builder.buildCorn();
        builder.buildBerry();
        builder.buildAppleTree();
        return( builder.getPlant());
    }
};

int main()
{
    Director dir;
    RomanPlantBuilder builder_1;
    VladPlantBuilder builder_2;
    Plant * ro = dir.createPlant( builder_1);
    Plant * vl = dir.createPlant( builder_2);
    cout << "Roman Plant:" << endl;
    ro->info();
    cout << "\nVlad Plant:" << endl;
    vl->info();
    return 0;
}