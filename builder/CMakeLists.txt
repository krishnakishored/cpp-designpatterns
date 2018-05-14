#add_subdirectory(BuilderFacets)

add_library(libbuilder creational_builder.cpp creational_groovystyle.cpp BuilderFacets/Facets.cpp BuilderFacets/Person.cpp BuilderFacets/Person.h BuilderFacets/PersonAddressBuilder.h BuilderFacets/PersonBuilder.cpp BuilderFacets/PersonBuilder.h BuilderFacets/PersonJobBuilder.h)
# add_library(libbuilder creational_builder.cpp creational_groovystyle creational_builderexercise.cpp)

