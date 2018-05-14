#pragma once
#include "creational_hotdrink.h"

struct HotDrinkFactory
{
  virtual std::unique_ptr<HotDrink> make() const = 0;
};