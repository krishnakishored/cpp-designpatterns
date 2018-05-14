#pragma once
#include <memory>
#include "creational_hotdrink.h"
#include "creational_drinkfactory.h"

struct HotDrink;

struct CoffeeFactory : HotDrinkFactory
{
  std::unique_ptr<HotDrink> make() const override
  {
    return std::make_unique<Coffee>();
  }
};