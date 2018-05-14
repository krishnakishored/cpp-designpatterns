#include <iostream>
#include <memory>
#include <map>
#include "creational_hotdrink.h"
#include "creational_drinkfactory.h"
using namespace std;

std::unique_ptr<HotDrink> make_drink(string type)
{
  std::unique_ptr<HotDrink> drink;
  if (type == "tea")
  {
    drink = std::make_unique<Tea>();
    drink->prepare(200);
  }
  else 
  {
    drink = std::make_unique<Coffee>();
    drink->prepare(50);
  }
  return drink;
}

int main_abstractfactory()
{
  auto d = make_drink("tea");

  DrinkFactory df;
  df.make_drink("coffee");

  getchar();
  return 0;
}