#pragma once
#include <string>
#include "creational_hotdrink.h"
#include "creational_hotdrinkfactory.h"
#include "creational_teafactory.h"
#include "creational_coffeefactory.h"
#include <map>
#include <functional>
using namespace std;

struct HotDrink;

class DrinkFactory
{
  std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;
public:
  DrinkFactory()
  {
    hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
    hot_factories["tea"] = std::make_unique<TeaFactory>();
  }

  std::unique_ptr<HotDrink> make_drink(const std::string& name)
  {
    auto drink = hot_factories[name]->make();
    drink->prepare(200); // oops!
    return drink;
  }
};

class DrinkWithVolumeFactory
{
  std::map<std::string, function<std::unique_ptr<HotDrink>()>> factories;
public:

  DrinkWithVolumeFactory()
  {
    factories["tea"] = [] {
      auto tea = std::make_unique<Tea>();
      tea->prepare(200);
      return tea;
    };
  }

  std::unique_ptr<HotDrink> make_drink(const std::string& name);
};

inline std::unique_ptr<HotDrink> DrinkWithVolumeFactory::make_drink(const std::string& name)
{
  return factories[name]();
}
