#pragma once
#include "creational_drinkfactory.h"

struct TeaFactory : HotDrinkFactory
{
  std::unique_ptr<HotDrink> make() const override {
    return std::make_unique<Tea>();
  }
};