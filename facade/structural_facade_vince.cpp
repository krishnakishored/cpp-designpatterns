// Purpose.  Facade                   
//                                    
// Discussion.  Class Compute models a decimal digit adder module.  
// An entire "subsystem" can be configured by linking as many of these modules as the desired precision requires.  

#include <iostream>                   
#include <string>                     

using std::endl;
using std::cout;
using std::cin;

class Compute {                         
public:                                 
   char add( char a, char b, int& c) 
   {  
      int result = a + b + c - 96;      
      c = 0;                            
      if (result > 9) {                 
         result -= 10;                  
         c = 1;                         
      }                                 
      return result + 48;               
   }                                    
};                                      

// The "subsystem" being modeled in main() is complex and burdensome to use.  
int main_without_facade( void ) {                    
   Compute  tens, ones;                
   char     a[9], b[9], c, d;          
   int      cary;                      
while (1) {                            
   cout << "Enter 2 two-digit nums: ";           
   cin >> a >> b;                      
   cout << "   sum is ";               
   cary = 0;                           
   if ((strlen(a) > 1) && (strlen(b) > 1)) {   
      c = ones.add( a[1], b[1], cary); 
      d = tens.add( a[0], b[0], cary); 
   } else if (strlen(a) > 1) {             
      c = ones.add( a[1], b[0], cary); 
      d = tens.add( a[0],  '0', cary);
   } else if (strlen(b) > 1) {             
      c = ones.add( b[1], a[0], cary); 
      d = tens.add( b[0],  '0', cary); 
   } else {                            
      c = tens.add( a[0], b[0], cary); 
      d = 'x';                         
   }                                   
   if (cary) cout << '1';              
   if (d != 'x') cout << d;            
   cout << c << endl;
}  
return 0;
}                                 
// Enter 2 nums: 99 99   sum is 198                  
// Enter 2 nums: 38 83   sum is 121                  

// Wrapping this subsystem inside of a Facade that exports a simple interface is desirable.                         
 class Facade {
 public:
 char* add( char* a, char* b ) {
    int cary = 0, i = 0;
    char c, d;
    if ((strlen(a) > 1) && (strlen(b) > 1)) {
       c = ones.add( a[1], b[1], cary );
       d = tens.add( a[0], b[0], cary );
    } else if (strlen(a) > 1) {
       c = ones.add( a[1], b[0], cary );
       d = tens.add( a[0],  '0', cary );
    } else if (strlen(b) > 1) {
       c = ones.add( b[1], a[0], cary );
       d = tens.add( b[0],  '0', cary );
    } else {
       c = tens.add( a[0], b[0], cary );
       d = 'x';
    }
    if (cary) ans[i++] = '1';
    if (d != 'x') ans[i++] =  d;
    ans[i++] = c;
    ans[i] = '\0';
    return ans;
 }
 private:
    Compute  tens, ones;
    char     ans[9];
 };


int  main_facade_vince_1( ) {
    Facade  f;
    char a[9], b[9];
    while (1) {
      cout << "Enter 2 nums: ";
      cin >> a >> b;
      cout <<" sum is "<< f.add(a,b) << endl;
   }  
   return 0;
}
// Enter 2 nums: 9 13
//    sum is 22






// Purpose.  Facade design pattern demo.
// 
// Discussion.  Structuring a system into subsystems helps reduce complexity. 
// A common design goal is to minimize the communication and dependencies between subsystems. 
// One way to achieve this goal is to introduce a "facade" object that provides a single, simplified interface to the many, potentially complex, individual interfaces within the subsystem.  
// In this example, the "subsystem" for responding to a networking service request has been modeled, and a facade (FacilitiesFacade) interposed.  
// The facade "hides" the twisted and bizarre choreography necessary to satisfy even the most basic of requests.
// All the user of the facade object has to do is make one or two phone calls a week for 5 months, and a completed service request results.


class MisDepartment {
public:
	void submitNetworkRequest() { _state = 0; }
	bool checkOnStatus() {
		_state++;
		if (_state == Complete)
			return 1;
		return 0; }
private:
	enum States {Received, DenyAllKnowledge, ReferClientToFacilities,
		FacilitiesHasNotSentPaperwork, ElectricianIsNotDone,
		ElectricianDidItWrong, DispatchTechnician, SignedOff, DoesNotWork,
		FixElectriciansWiring, Complete};
	int _state;
};

class ElectricianUnion {
public:
	void submitNetworkRequest() { _state = 0; }
	bool checkOnStatus() {
		_state++;
		if (_state == Complete)
			return 1;
		return 0; }
private:
	enum States {Received, RejectTheForm, SizeTheJob, SmokeAndJokeBreak,
		WaitForAuthorization, DoTheWrongJob, BlameTheEngineer, WaitToPunchOut,
		DoHalfAJob, ComplainToEngineer, GetClarification, CompleteTheJob,
		TurnInThePaperwork, Complete};
	int _state;
};

class FacilitiesDepartment {
public:
	void submitNetworkRequest() { _state = 0; }
	bool checkOnStatus() {
		_state++;
		if (_state == Complete)
			return 1;
		return 0; }
private:
	enum States {Received, AssignToEngineer, EngineerResearches,
		RequestIsNotPossible, EngineerLeavesCompany, AssignToNewEngineer,
		NewEngineerResearches, ReassignEngineer, EngineerReturns,
		EngineerResearchesAgain, EngineerFillsOutPaperWork, Complete};
	int _state;
};

class FacilitiesFacade {
public:
	FacilitiesFacade()          { _count = 0; }
	void submitNetworkRequest() { _state = 0; }
	bool checkOnStatus() {
		_count++;
		/* Job request has just been received */
		if (_state == Received) {
			_state++;
			/* Forward the job request to the engineer */
			_engineer.submitNetworkRequest();
			cout << "submitted to Facilities - " << _count
				<< " phone calls so far" << endl; }
		else if (_state == SubmitToEngineer) {
			/* If engineer is complete, forward to electrician */
			if (_engineer.checkOnStatus()) {
				_state++;
				_electrician.submitNetworkRequest();
				cout << "submitted to Electrician - " << _count
					<< " phone calls so far" << endl; } }
		else if (_state == SubmitToElectrician) {
			/* If electrician is complete, forward to technician */
			if (_electrician.checkOnStatus()) {
				_state++;
				_technician.submitNetworkRequest();
				cout << "submitted to MIS - " << _count
					<< " phone calls so far" << endl; } }
		else if (_state == SubmitToTechnician) {
			/* If technician is complete, job is done */
			if (_technician.checkOnStatus())
				return 1; }
		/* The job is not entirely complete */
		return 0; }
	int getNumberOfCalls() { return _count; }
private:
	enum States {Received, SubmitToEngineer, SubmitToElectrician,
		SubmitToTechnician};
	int                   _state;
	int                   _count;
	FacilitiesDepartment  _engineer;
	ElectricianUnion      _electrician;
	MisDepartment         _technician;
};

int main() {
	FacilitiesFacade  facilities;

	facilities.submitNetworkRequest();
	/* Keep checking until job is complete */
	while ( ! facilities.checkOnStatus());

	cout << "job completed after only " << facilities.getNumberOfCalls()
		<< " phone calls" << endl;
    return 0;
}

// submitted to Facilities - 1 phone calls so far
// submitted to Electrician - 12 phone calls so far
// submitted to MIS - 25 phone calls so far
// job completed after only 35 phone calls
