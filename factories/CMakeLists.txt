# add_subdirectory(BuilderFacets)


add_library(libfactories creational_factorymethod.cpp creational_factory.cpp creational_innerfactory.cpp AbstractFactory/creational_abstractfactory.cpp AbstractFactory/creational_coffeefactory.h AbstractFactory/creational_drinkfactory.h AbstractFactory/creational_hotdrinkfactory.cpp AbstractFactory/creational_hotdrinkfactory.h AbstractFactory/creational_teafactory.h)

# add_library(libfactories creational_factorymethod.cpp creational_factory.cpp creational_innerfactory.cpp \
#     AbstractFactory/creational_abstractfactory.cpp \
#   AbstractFactory/creational_coffeefactory.cpp \
#   AbstractFactory/creational_drinkfactory.h \
#   AbstractFactory/creational_hotdrinkfactory.cpp \
#   AbstractFactory/creational_hotdrinkfactory.h \
#   AbstractFactory/creational_teafactory.h)
