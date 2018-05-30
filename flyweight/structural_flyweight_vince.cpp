// Purpose.  Flyweight                  
//
// Discussion.  Trying to use objects at very low levels of granularity is nice, but the overhead may be prohibitive.  
// Flyweight suggests removing the non-shareable state from the class, and having the client supply it when methods are called. 
// This places more responsibility on the client, but, considerably fewer instances of the Flyweight class are now created.     
// Sharing of these instances is facilitated by introducing a Factory class that maintains a "cache" of existing Flyweights.                 

// In this example, the "X" state is considered shareable (within each row anyways), and the "Y" state has been externalized 
// (it is supplied by the client when report() is called).                             
                                        
#include <iostream> 
#include <string>

using std::cout;
using std::endl;                  
                                        
const int X = 6;                        
const int Y = 10;                       
                                        
class Gazillion1 {                       
public:                                 
   Gazillion1() {                        
      val1_ = num_ / Y;                 
      val2_ = num_ % Y;                 
      num_++;                           
   }
   void report() {                      
      cout << val1_ << val2_ << ' ';    
   }
private:                                
   int    val1_;                        
   int    val2_;                        
   static int num_;                     
};                                      
                                        
int Gazillion1::num_ = 0;                
                                        
// int main_flyweight_1( void )   
int main_without_flyweight()                       
{                                       
   Gazillion1  matrix[X][Y];
   for (int i=0; i < X; i++)            
   {                                    
      for (int j=0; j < Y; j++)         
         matrix[i][j].report();         
      cout << endl;                     
   }    
   return 0;                                
}                                       
                                        
// 00 01 02 03 04 05 06 07 08 09        
// 10 11 12 13 14 15 16 17 18 19        
// 20 21 22 23 24 25 26 27 28 29        
// 30 31 32 33 34 35 36 37 38 39        
// 40 41 42 43 44 45 46 47 48 49        
// 50 51 52 53 54 55 56 57 58 59



class Gazillion {
public:
   Gazillion( int in ) {
      val1_ = in;
      cout << "ctor: "<< val1_<<endl; }
   ~Gazillion() {
      cout << val1_ << ' '; }
   void report( int in ) {
      cout << val1_ << in << ' '; }
private:
   int  val1_;
};

class Factory {
public:
   static Gazillion* getFly(int in) {
      if ( ! pool_[in])
         pool_[in] =
                 new Gazillion( in );
      return pool_[in];
   }
   static void cleanUp() {
      cout << "dtors: ";
      for (int i=0; i < X; i++)
         if (pool_[i])
            delete pool_[i];
      cout << endl;
   }
private:
   static Gazillion*  pool_[X];
};

Gazillion*  Factory::pool_[]  = {
                         0,0,0,0,0,0 };

int main_flyweight_vince_1( void )
{
   for (int i=0; i < X; i++)
   {
      for (int j=0; j < Y; j++)
         Factory::getFly(i)->report(j);
      cout << endl;
   }
   Factory::cleanUp();
   return 0;
}

// ctor: 0
// 00 01 02 03 04 05 06 07 08 09
// ctor: 1
// 10 11 12 13 14 15 16 17 18 19
// ctor: 2
// 20 21 22 23 24 25 26 27 28 29
// ctor: 3
// 30 31 32 33 34 35 36 37 38 39
// ctor: 4
// 40 41 42 43 44 45 46 47 48 49
// ctor: 5
// 50 51 52 53 54 55 56 57 58 59
// dtors: 0 1 2 3 4 5



// Purpose.  Flyweight design pattern demo.
// 
// Discussion.  Flyweight describes how to share objects, so that their use at fine granularities is not cost prohibitive.  
// A key concept is the distinction between "intrinsic" and "extrinsic" state.  
// Intrinsic state consists of information that is independent of the flyweight's context - information that is sharable 
// (i.e. each Icon's name, width, and height).  It is stored in the flyweight (i.e. the Icon class).
// Extrinsic state cannot be shared, it depends on and varies with the flyweight's context 
// (i.e. the x,y position that each Icon instance's upper left corner will be drawn at).  
// Extrinsic state is stored or computed by the client and is passed to the flyweight when an operation is invoked.  
// Clients should not instantiate Flyweights directly, they should obtain them exclusively from a FlyweightFactory object to ensure
// they are shared properly.




class Icon {
public:
	Icon( char* fileName ) {
		strcpy( _name, fileName );
		if ( ! strcmp(fileName, "go"))     { _width = 20;  _height = 20; }
		if ( ! strcmp(fileName, "stop"))   { _width = 40;  _height = 40; }
		if ( ! strcmp(fileName, "select")) { _width = 60;  _height = 60; }
		if ( ! strcmp(fileName, "undo"))   { _width = 30;  _height = 30; } }
	const char* getName() { return _name; }
	void draw( int x, int y ) {
		cout << "   drawing " << _name << ": upper left (" << x << "," << y
		<< ") - lower right (" << x + _width << "," << y + _height << ")"
		<< endl; }
private:
	char  _name[20];
	int   _width;
	int   _height;
};


class FlyweightFactory {
public:
	static Icon* getIcon( char* name ) {
		for (int i=0; i < _numIcons; i++)
			if ( ! strcmp( name, _icons[i]->getName() ))
				return _icons[i];
		_icons[_numIcons] = new Icon( name );
		return _icons[_numIcons++]; }
	static void reportTheIcons() {
		cout << "Active Flyweights: ";
		for (int i=0; i < _numIcons; i++)
			cout << _icons[i]->getName() << " ";
		cout << endl; }
private:
	enum { MAX_ICONS = 5 };
	static int    _numIcons;
	static Icon*  _icons[MAX_ICONS];
};

int   FlyweightFactory::_numIcons = 0;
Icon* FlyweightFactory::_icons[];


class DialogBox {
public:
	DialogBox( int x, int y, int incr ) : _iconsOriginX(x), _iconsOriginY(y),
		_iconsXIncrement(incr) { }
	virtual void draw() = 0;
protected:
	Icon* _icons[3];
	int   _iconsOriginX;
	int   _iconsOriginY;
	int   _iconsXIncrement;
};

class FileSelection : public DialogBox {
public:
	FileSelection( Icon* first, Icon* second, Icon* third ) :
		DialogBox(100,100,100) {
		_icons[0] = first;
		_icons[1] = second;
		_icons[2] = third; }
	void draw() {
		cout << "drawing FileSelection:" << endl;
		for (int i=0; i < 3; i++)
			_icons[i]->draw( _iconsOriginX + (i * _iconsXIncrement),
				_iconsOriginY ); }
};

class CommitTransaction : public DialogBox {
public:
	CommitTransaction( Icon* first, Icon* second, Icon* third ) :
		DialogBox(150,150,150) {
		_icons[0] = first;
		_icons[1] = second;
		_icons[2] = third; }
	void draw() {
		cout << "drawing CommitTransaction:" << endl;
		for (int i=0; i < 3; i++)
			_icons[i]->draw( _iconsOriginX + (i * _iconsXIncrement),
				_iconsOriginY ); }
};


int main() {
	DialogBox* dialogs[2];
	dialogs[0] = new FileSelection(
		FlyweightFactory::getIcon((char*)"go"),
		FlyweightFactory::getIcon((char*)"stop"),
		FlyweightFactory::getIcon((char*)"select") );
	dialogs[1] = new CommitTransaction(
		FlyweightFactory::getIcon((char*)"select"),
		FlyweightFactory::getIcon((char*)"stop"),
		FlyweightFactory::getIcon((char*)"undo") );

	for (int i=0; i < 2; i++)
		dialogs[i]->draw();

	FlyweightFactory::reportTheIcons();
    return 0;
}

// drawing FileSelection:
//    drawing go: upper left (100,100) - lower right (120,120)
//    drawing stop: upper left (200,100) - lower right (240,140)
//    drawing select: upper left (300,100) - lower right (360,160)
// drawing CommitTransaction:
//    drawing select: upper left (150,150) - lower right (210,210)
//    drawing stop: upper left (300,150) - lower right (340,190)
//    drawing undo: upper left (450,150) - lower right (480,180)
// Active Flyweights: go stop select undo 