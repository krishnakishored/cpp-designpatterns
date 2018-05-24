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
    *An Object that facilitates the traversal of a data structure*
* An iterator is a class that facilitates the traversal
    - Keeps a reference to the current element
    - Knows how to move to a different element
* Can be used implicitly
    - Range-based for
    - coroutines (generators)

#### Mediator
    *A component that facilitates communication between other components without them necessarily being aware of each other or having direct(reference) access to each other*
* Components may go in and out of a system at any time
    - Chat room participants
* It makes no sense for them to have direct references to one another - those references may go dead at any time
* Solution: to have them all refer to some central component that facilitates communication

#### Memento
    *Keep a memento of an object's state to return to that state*
* An object or system goes through changes - e.g.a bank account gets deposits and withdrawals
* There are different ways of navigating those changes
    - One way is to record every change (command) and teach a commond to undo itself
    - Another is to simply save snapshots of the system
* *A token/handle representing the system state.Lets us roll back to the state when the token was generated.May or may not directly expose state info*

#### Observer
    *An observer is an object that wishes to be informed about events happening in the system.The entity generating the events is an observable*
* Getting notification when things happen
    - Object's field changes
    - Object does something
    - Some external event occurs
* We want to listen to events and notified when they occur
* Terminology:
    - event and subscriber
    - signal and slot (Boost,Qt,..)
* Two participants:
    - Observer provides a way of subscribing to an event (signal)
    - Observable performs the subscription

#### State
* Changes in state can be explicit or in response to event (Observer pattern)
* *A pattern in which the object's behaviour is determined by its state. An object transitions from one state to another(something needs to trigger a transition)*
* *A formalized construct which manages state and transitions is called a state machine*    

#### Strategy
    *System behaviour partially specified at runtime*
* Many algorithms can be decomposed into higher and lower level parts
* The high-level algorithm can be reused.
* *Enables the exact behavior of a system to be selected either at run-time(dynamic) or compile time(static)*
* This pattern is also known as a *policy*

#### Template Method
    *A high-level blueprint for an algorithm to be completed by inheritors*
* Algorithms can be decomposed into common parts + specifics
* Strategy pattern does this through composition
    - High-level algorithm uses an inheritance
    - Concrete implementations implement the interface
* Template Method does the same thing through inheritance
    - Overall algo makes use of abstract  member
    - Inheritors override the abstract members
    - Parent template method invoked
* Allows us to define the 'skeleton' of the algorithm with concrete implementations defined in subclasses.

#### Visitor
    *Typically a tool for structure traversal rather than anything else*
* Need to define a new operation on an entire class hierarchy
    - e.g: make a document model printable to HTML/Markdown
* Do not want to keep modifying every class in the hierarchy
* Need access to the non-common aspects of classes in the hierarchy
    - Cannot put everything into a single interface
* Create an external component to handle rendering
    - But preferably avoid type checks
* *A Pattern where a component(visitor) is allowed to traverse the entire inheritance hierarchy. Implemented by propagating a single visit() method throughout the entire hierarchy*