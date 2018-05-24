# **SOLID**

## Single Responsibility Principle
* A class should only have one reason to change
* *Separation of concerns*  - different classes handling different, independent tasks/ problems

## Open-Close Principle

- Classes should be open form extension but closed for modification

## Liskov Substitution Principle
* You should be able to substitute a base type for a subtype

## Interface Segregation Principle
- Don't put too much into an interface; split into separate interfaces
- YAGNI - You Ain't Going to Need It

## Dependency Inversion Principle
* High-level modules should not depend upon low-level ones; use abstractions


> Written with [StackEdit](https://stackedit.io/)

# ** Design Patterns - Motivations **

#### Builder
  *When construction gets a little bit complicated*
 * Some objects are simple and can be created in a single ctor call & others require a lot of ceremony to create 
 * Having an obj with 10 ctor arguments is not productive, instead opt for piecewise construction
 * *When piecewise object construction is complicated, provide an API for doing it succintly*
    - StringBuilder

#### Adapter 
 *Getting the interface you want from the interface you have*
* *A construct which adapts an existing interface X to conform to required interface Y*

#### Bridge
  *Connecting components together through abstractions*
* Bridge prevents a 'Cartesian product' complexity explosion
* Bridge pattern avoids the entity explosion
* *A mechanism that decouples interface(hierarchy) from an implementation (hierarachy)*
    - pImpl idiom

#### Composite
 *Treating individual and aggregate objects uniformly*
* Objects use other objects' fields/properties/members through inheritance and composition
* Composition lets us make compound objects 
* *A mechanism of treating individual(scalar) objects and compositions of objects in a uniform manner*
    - Foo & Collection<Foo> have common APIs

#### Decorator
 *Adding behaviour without altering the class itself*
* Facilitates the addition of behaviours to individual objects
* Want to augment an object with additional functionality
* Do not want to rewrite or alter existing code (OCP)
* Want to keep new functionality separate (SRP)
* Need to be able to interact with existing structures
* Two options
    - Aggregate the decorated object
    - Inherit from the decorated object


 #### Facade
  *Exposing several components through a single interface*
* Balancing complexity and presentation/usability
* *Provides a simple, easy to understand/user interface over a large and sophisticated body of code*
    - console

#### Flyweight 
 *Space optimization* 
* Avoid redundancy when storing data
* *A space optimization technique that lets us use less memory by storing externally the data associated with similart objects*
    - Store a list of first/last names and pointers to them
    - bold or italic text in console - don't format each character instead operate on ranges(line no., start/end positions)

#### Singleton
 *A component which is instantiated only once*
* For some components it only makes sense to have one in the system
    - Database repository
    - Object factory
    - the ctor is expensive, do it only once and provide everyone with the same instance
    - Want to prevent anyone creating additional copies
    - Need to take care of lazy instantiation and thread safety

#### Prototype
 *When it's easier to copy an existing object to fully initialize a new one*    
* Complicatd objects aren't designed from scratch, they reiterate existing designs 
* An existing (partially or fully constructed) design is a prototype
* We make a copy(clone) the prototype and customize it - *Requires 'deep copy' support*
* *A partially or fully initialized object that you copy(clone) and make use of*

#### Factories - Factory method & Abstract Factory
* Object creation logic becomes too convoluted
* Constructor is not descriptive
    - Name mandated by name of containing type
    - Can't overload with same sets of args with different names
    - Can turn into 'optional parameter hell'
* Object creation (non-piece, unlike builder) can be outsourced to 
    - A separate function (Factory Method)
    - That may exist in a separate class (Factory)
    - Can create hierarchy of factories with Abstract Factory
* *A component responsible soley for the wholesale(not piecewise) creation of objects*

#### Proxy
 *An interface for accessing a particular resource*
* You are calling foo.bar(), assume that foo is in the same process as bar()
* What if, later on you want to put all Foo-related operations into a separate process? 
  Can you avoid changign your code?
* Proxt to the rescue
    - Same interface,entirely different behaviour
* This is called a communication proxy
    - Other types: logging, virtual, guarding ..  
* *A class that functions as an interface to a particular resource. That resource may be remote, expensive to construct, or may require logging or some other added functionality*
    - Smart Pointers

#### Chain of Responsibility
 *Sequence of handlers processing an event one after another*
* *A chain of components who all get a chance to process a commmand or query,optionally having default processing implementation and an ability to terminate the processing chain*
    - A graphical element on a form: button handles it, stops further processing or the underlying group box or the the underlying window

#### Command 
 *An object which represents an instruction to perform a particular action. Contains all the info necessary for the action to be taken*    
* Ordinary c++ statements are perishable
    - can't undo a field/property assignment
    - can't directly serialize a sequence of actions (calls)
* Uses: GUI Commands, multi-level undo/redo, macro recording and more.
* Command Query Separation
    - A command is asking for an action; it is mutable(causes mutation of the object) but doesn't have a return value.
    - Query - asking for info & has a return value
    - CQS - having separate means of sending commands and queries
 *Wrapping some instructions in a object*

#### Interpreter 

* Textual inputs needs to be processed - turned into OOP structures
* examples - IDEs, compilers, numeric expressions, HTML, XML, Regular expressions
* *A component that processes structured text data. Does so by turning it into
separate lexical tokens(lexing) and then interpreting sequences of said tokens (parsing)*

#### Iterator
* How traversal of data structures happens and who makes it happen


#### Mediator

#### Memento

#### Observer

#### State

#### Strategy

#### Template Method

#### Visitor