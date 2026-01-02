#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;


class ShipSearch {
protected:
    string name, captain_name, capacity;
    string departure_time, arrival_time;
    int id;
    string travel_date, file_date, departure_port, file_departure_port, destination_port, file_destination_port;
    int count;
    int nodays;

	public:
    ShipSearch()  {
	count=0;
	}
	void menuofships()
	{
		cout<<" ____________________________________________"<<endl;
		cout<<"|Our ship going to these date and time .     |"<<endl;
		cout<<"|____________________________________________|"<<endl;
		cout<<"|Travel_date    =                  2023-12-12|"<<endl;
		cout<<"|Ship_name      =                triple-seven|"<<endl;
		cout<<"|ID             =                         777|"<<endl;
		cout<<"|Captain Name   =                      Rizwan|"<<endl;
		cout<<"|Capacity       =                    500_tons|"<<endl;
		cout<<"|Departure Point=                    pakistan|"<<endl;
		cout<<"|Destination Point =                    india|"<<endl;
		cout<<"|Start Date   = December_12_2023__06_00_00_Pm|"<<endl;
		cout<<"|End Date     = December_15_2023__08_00_00_Pm|"<<endl;
		cout<<"|No Of Days   =                             4|"<<endl;
		cout<<"|____________________________________________|"<<endl;
		
	}
    void search() {
    	file:
    	cout<<" ________________________________________________"<<endl;
        cout<<"|Enter the date you want to travel (YYYY-MM-DD): |"<<endl;
        cout<<"|________________________________________________|";
        cout<<"\t\t";
        cin>>travel_date;
        cout<<endl;
        
        cout<<" __________________________"<<endl;
        cout<<"|Enter the departure port: |"<<endl;
        cout<<"|__________________________|";
        cout<<"\t\t";
        cin>>departure_port;
        cout<<endl;
        
        cout<<" ____________________________"<<endl;
        cout<<"|Enter the destination port: |"<<endl;
        cout<<"|____________________________|";
        cout<<"\t\t";
        cin>>destination_port;

        ifstream file("search.txt");

        if (file.fail()) {
            cerr<<"Error opening file!"<<endl;
            return;
        }
		
        while (file>>file_date>>name>>id>>captain_name>>capacity>>file_departure_port>>file_destination_port>>departure_time>>arrival_time>>nodays) {
            if (travel_date == file_date && departure_port == file_departure_port && destination_port == file_destination_port) {
                count = 1;
                cout<<" _______________________________________________________________________________________"<<endl;
                cout<<"|Date:                              |"<<"\t------->"<<travel_date<<"				|"<<endl;
                cout<<"|Name:                              |"<<"\t------->"<<name<<"				|"<<endl;
                cout<<"|ID:                                |"<<"\t------->"<<id<<"					|"<<endl;
                cout<<"|Captain Name:                      |"<<"\t------->"<<captain_name<<"					|"<<endl;
                cout<<"|Capacity:                          |"<<"\t------->"<<capacity<<"				|"<<endl;
                cout<<"|Departure Port:                    |"<<"\t------->"<<departure_port<<"				|"<<endl;
                cout<<"|Destination Port:                  |"<<"\t------->"<<destination_port<<"					|"<<endl;
                cout<<"|Departure Time:                    |"<<"\t------->"<<departure_time<<"		|"<<endl;
                cout<<"|Arrival Time:                      |"<<"\t------->"<<arrival_time<<"		|"<<endl;
                cout<<"|Number of days spend in the ship:  |"<<"\t------->"<<nodays<<"					|"<<endl;
                cout<<"|_______________________________________________________________________________________|"<<endl;
            }
        }

        file.close();

        if (count == 0) {
        	cout<<" ______________"<<endl;
            cout<<"|Ship not found|__________________________________________________"<<endl;
            cout<<"|Because our ship is not gone at that day please select any other.|"<<endl;
            cout<<"|_________________________________________________________________|"<<endl;
            goto file;
        }
    }
    int getDays()
    {
    	ifstream day;
    	day.open("search.txt");
    	day >> nodays;
    	return nodays;
    	day.close();
	}
};


class Booking {
private:
    int bookingId;
    int passenger;
    int cabin;
    string departureDate;
    string arrivalDate;
    int cabin_type;
    string destination_start;
    string destination_end;
    double total_price;
    int luxry_price;
	int Standarad_price;
	int Third_classp;

public:
	ShipSearch ss1;
    // Setters
	void setcabin_type(int ct) {
        cabin_type = ct;
    }
    void setdestination_start(string ds) {
        destination_start = ds;
    }
    void setdestination_end(string de) {
        destination_end = de;
    }
    void setArrivalDate(string date) {
        arrivalDate = date;
    }
    void setCabin(int cab) {
        cabin = cab;
    }
    void setBookingId(int id) {
        bookingId = id;
    }
    void setDepartureDate(string datee) {
        departureDate = datee;
    }
    void setPassenger(int pass) {
        passenger = pass;
    }
    void setToralPrice(double tp)
    {
    	total_price = tp;
	}

    // Getters
    double gettotal_price()
    {
    	return total_price;
	}
    int getluxry_price() {
        return (10000 * passenger * ss1.getDays());
    }
    int getStandarad_price() {
        return (6500 * passenger * ss1.getDays()) ;
    }
    int getThird_classp() {
        return (3500 * passenger * ss1.getDays());
    }
    string getArrivalDate() {
        return arrivalDate;
    }
    int getCabin() {
        return cabin;
    }
    int getBookingId() {
        return bookingId;
    }
    string getDepartureDate() {
        return departureDate;
    }
    int getPassenger() {
        return passenger;
    }
    int getcabin_type() {
        return cabin_type;
    }
    string getdestination_start() {
        return destination_start;
    }
    string getdestination_end() {
        return destination_end;
    }
    
    
};


// PASSENGER...
class Passenger {
private:
    int id;
    string passengerName;
    int age;
    string nationality;
    string gender;
    int contactNumber;
    string emailAddress;

public:

    // Setters
    void setPassID()           // Setting passenger id
    {
    	ifstream pid;
    	pid.open("passenger.txt",ios::app);
    	int id;
    	pid >> id;
    	pid.close();	
	}
	void incrementPassID()
	{
		 id++;
		ofstream pids;
		pids.open("passenger.txt");
		pids << id;
		pids.close();
		
		cout<<"Assigned id is: "<<id<<endl;
	
	}
//    void setPassengerId(int id) {
//        passengerId = id;
//    }
    void setPassengerName(string name) {
        passengerName = name;
    }
    
    void setAge(int a) {
        age = a;
    }
    void setNationality(string nation) {
        nationality = nation;
    }
    void setGender(string gen) {
        gender = gen;
    }
    void setContactNumber(int number) {
        contactNumber = number;
    }
    void setEmailAddress(string email) {
        emailAddress = email;
    }

    // Getters
//    int getPassengerId() {
//        return passengerId;
//    }
    string getPassengerName() {
        return passengerName;
    }
    int getAge() {
        return age;
    }
    string getNationality() {
        return nationality;
    }
    string getGender() {
        return gender;
    }
    int getContactNumber() {
        return contactNumber;
    }
    string getEmailAddress() {
        return emailAddress;
    }
};

//////////////////////////////////////////////////////////////////////////////  Cargo //////////////////////////////////////////////////////////////////////////

class Freight
{
	private:
		int id;
		string name;
		double weight;
		double length;
		double width;
		int materialSensitivity;
		double area;
		int noOfCartons;
		int noOfContainers;
		int price;
		int hazardPrice;
		int foodPrice;
		int highPrice;
		int vehiclesPrice;
		
	public:
		void setiD(int id)
		{
			id = id;
		}
		void setname(string n)
		{
			name = n;
		}
		void setweight(int w)
		{
			weight = w;
		}
		void setlength(int l)
		{
			length = l;
		}
		void setwidth(int width)
		{
			width = width;
		}
		void setmaterialSensitivity(int ms)
		{
			materialSensitivity = ms;
		}
		void setnoOfCartons(int noc)
		{
			noOfCartons = noc;
		}
		void setprice(int p)
		{
			price = p;
		}
		void setnoOfContainers(int nocon)
		{
			noOfContainers = nocon;
		}
		// Getters
		int getid()
		{
			return id;
		}
		string getname()
		{
			return name;
		}
		double getweight()
		{
			return weight;
		}
		double getlength()
		{
			return length;
		}
		double getwidth()
		{
			return width;
		}
		int getmaterialSensitivity()
		{
			return materialSensitivity;
		}
		int getnoOfCartons()
		{
			return noOfCartons;
		}
		
		int gethazardPrice()
		{
			return (5000 * noOfCartons);
		}
		int getfoodPrice()
		{
			return (1000 * noOfCartons);
		}
		int gethighPrice()
		{
			return (2500 * noOfCartons);
		}
		int getvehiclePrice()
		{
			return (10000 * noOfCartons);
		}
		int getprice()
		{
			return price;
		}
		int getnoOfContainers()
		{
			return noOfContainers;
		}
};

class CargoInsurance {
private:
    int insuranceId;
    string policyNumber;
    string providerName;
    int coverageType;
    string startDate;
    string endDate;
    int price;
    int lossPrice;
    int theftPrice;
    int liabilityPrice;
    int allPrice;

public:
	Freight freight;
    // Setters
    void setInsuranceId(int id) {
        insuranceId = id;
    }
    void setPolicyNumber(string number) {
        policyNumber = number;
    }
    void setProviderName(string name) {
        providerName = name;
    }
    void setCoverageType(int type) {
        coverageType = type;
    }
    void setStartDate(string date) {
        startDate = date;
    }
    void setEndDate(string date) {
        endDate = date;
    }
    void setprice(int p) {
        price = p;
    }

    // Getters
    int getInsuranceId() {
        return insuranceId;
    }
    string getPolicyNumber() {
        return policyNumber;
    }
    string getProviderName() {
        return providerName;
    }
    int getCoverageType() {
        return coverageType;
    }
    string getStartDate() {
        return startDate;
    }
    string getEndDate() {
        return endDate;
    }
     int getprice() {
        return price;
    }
     int getlossPrice() {
        return (1000 * freight.getnoOfContainers());
    }
     int gettheftPrice() {
        return (1000 * freight.getnoOfContainers());
    }
     int getliabilityPrice() {
        return (1000 * freight.getnoOfContainers());
    }
     int getallPrice() {
        return (3000 * freight.getnoOfContainers());
    }
};


class Cargo_login {
private:
    int ID;

public:
    void setID(int id){
        ID = id;
    }

    int getpas(){
        return ID;
    }

    bool islogin(){
    	cout<<endl<<endl;
    	cout<<"\t ____________________"<<endl;
        cout<<"\t|Enter the Cargo  ID |"<<endl;
        cout<<"\t|____________________|";
        cout<<"\t\t";
        cin>>ID;

        ifstream file;
        file.open("Cargo_login.txt");
        int id_;

        while(file>>id_){
            if(ID == id_ ){
            	cout<<endl<<endl;
            	cout<<"\t _________________________________________________________________________"<<endl;
                cout<<"\t|OK ! It ensures that management given you the booking id on your request.|"<<endl;
                cout<<"\t|Now , we will do further booking requirements.                           |"<<endl;
                cout<<"\t|_________________________________________________________________________|"<<endl;
                file.close();
                return true;
            }
        }
        file.close();
        cout<<"\t ______________"<<endl;
        cout<<"\t|Failed login  |"<<endl;
        cout<<"\t|______________|"<<endl;
        return false;
    } 
	void registerUser() {
		int id = rand()%1000;
		cout<<"\t _____________"<<endl;
		cout<<"\t|Your ID is:  |"<<endl;
		cout<<"\t|_____________|";
		cout<<"\t\t";
		cout<<id<<endl;
		
    	ofstream file;
    	file.open("Cargo_login.txt", ios::app); // Open in append mode
    	file << id <<endl;
    	file.close();
	}
	
	void verifying()
	{
		ifstream file;
		int Cid__,id;
		file.open("Cargo_login.txt");
		cout<<"Enter the primary ID of Cargo to check data:  ";
		cin>>Cid__;
		file>>id;
		if(id==Cid__)
		{
			cout<<"ID: "<< id<<endl;
			cout<<"So it is confirmed that you already registered yourself. "<<endl;
		}
		file.close();
	}
	 int getDays()
    {
    	ifstream Id;
    	Id.open("Cargo_login.txt");
    	Id >> ID;
    	return ID;
    	Id.close();
	}
  
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class cabinType
class Cabintype
{
	private:
		string fooditems;
		string beverages;
		string entertainment;
		string location;
		
	public:
		void setfooditems(string ft) {
        fooditems = ft;
    	}	
    	void setbeverages(string bv) {
        beverages = bv;
    	}	
    	void setentertainment(string enter) {
        entertainment = enter;
    	}	
    	void setlocation(string loc) {
        location = loc;
    	}
		string getfooditems() {
        return fooditems;
    	}
		string getbeverages() {
        return beverages;
    	}
		string getentertainment() {
        return entertainment;
    	}
		string getlocation() {
        return location;
    	}	
    	
	
};

class Employee
{
	private:
		static int t_no_employee;
		int full_employee;
		static int full_employee_hours;
		int half_employee;
		static int half_employee_hours;
		static int t_no_officers;
		int total_salaries;
		int total_officers_salary;
		int total_employee_salary;
		
	public:
		void sett_no_employee(int t_no_employee)
		{
			t_no_employee = t_no_employee;
		}
		void setfull_employee(int full_employee)
		{
			full_employee = full_employee;
		}
		void setfull_employee_hours(int full_employee_hours)
		{
			full_employee_hours = full_employee_hours;
		}
		void sethalf_employee(int half_employee)
		{
			half_employee = half_employee;
		}
		void sethalf_employee_hours(int half_employee_hours)
		{
			half_employee_hours = half_employee_hours;
		}
		void sett_no_officers(int t_no_officers)
		{
			t_no_officers = t_no_officers;
		}
		void settotal_salaries(int total_salaries)
		{
			total_salaries = total_salaries;
		}
		
		void set_total_officers_salary(int total_officers_salary)
		{
			total_officers_salary = total_officers_salary;
		}
		void set_total_employee_salary(int total_employee_salary)
		{
			total_employee_salary = total_employee_salary;
		}
		// Getters
		int gett_no_employee()
		{
			return t_no_employee;
		}
		int getfull_employee()
		{
			return full_employee;
		}
		int getfull_employee_hours()
		{
			return full_employee_hours;
		}
		int gethalf_employee()
		{
			return half_employee;
		}
		int gethalf_employee_hours()
		{
			return half_employee_hours;
		}
		int gett_no_officers()
		{
			return t_no_officers;
		}
		int gettotal_salaries()
		{
			return total_salaries;
		}
		int get_total_officers_salary()
		{
			return total_officers_salary;
		}
		int get_total_employee_salary()
		{
			return total_employee_salary;
		}
		//////////////////////////////////////////////////////////////////////////////
		int employees_full()
		{
			return (full_employee_hours * 2000);
		}
		int employees_half()
		{
			return (half_employee_hours * 2000);
		}
		int officers_full()
		{
			return (full_employee_hours * 5000);
		}
		int officers_half()
		{
			return (half_employee_hours * 5000);
		}
		
		
		//////////////////////////////////////////////////////////////////////////////
		
		void display()
		{
			Employee e1;
			int tef,teh,tefs;
	    	cout<<endl<<endl;
		    cout<<"Calculating Salaries."<<endl<<endl<<endl;
			// Calculating salaries of  employees
			cout<<"Salaries for employees."<<endl<<endl<<endl<<endl;
			cout<<"The total number of employees working at cruise :  "<<e1.gett_no_employee()<<endl<<endl;
			tef:
			cout<<"Enter total number of employees working at cruise full day :  ";
		    cin>>tef;
		    if(tef>50)
		    {
		    	cout<<endl<<"Enter less than 50."<<endl;
		    	goto tef;
			}
			cout<<endl<<endl;
	        cout<<"The worked hours of those employees who work full day : "<<e1.getfull_employee_hours()<<endl<<endl;
		        
	        teh = e1.gett_no_employee() - tef;
			cout<<"Enter total number of employees working at cruise but not full day :  "<<teh<<endl<<endl;
		    cout<<"The worked hours of those employees who not work full day : "<<e1.gethalf_employee_hours()<<endl<<endl;
	        
	        cout<<"The salary of employee is '2000' per hour."<<endl<<endl;
		    cout<<"The salary of full day employees are:  "<<((e1.employees_full()) * tef)<<endl<<endl;
		    cout<<"The salary of employees not working full day : "<<((e1.employees_half()) * teh)<<endl<<endl;
		    int total_employee_salary = (((e1.employees_full()) * tef) + ((e1.employees_half()) * teh));
		    cout<<"The total amount of salaries of employees : "<<total_employee_salary << endl<<endl<<endl<<endl;
		    
		    ofstream employee_salary;
		    employee_salary.open("employee_salary.txt",ios::app);
		    employee_salary << e1.getfull_employee_hours() << "  " << e1.gethalf_employee_hours() << "  " << ((e1.employees_full()) * tef) << "  " << ((e1.employees_half()) * teh) << "  " << total_employee_salary << endl;
		    employee_salary.close();
			cout<<endl<<endl<<endl;
			    
		    // Calculating salaries of officers    
		    cout<<"Salaries for officers."<<endl<<endl<<endl;
		    cout<<"The total number of officers working at cruise :  "<<e1.gett_no_officers()<<endl<<endl;
		    tefs:
			cout<<"Enter total number of officers working at cruise full day :  ";
		    cin>>tefs;
		    if(tefs>50)
		    {
		    	cout<<endl<<"Enter less than 50."<<endl;
		    	goto tef;
			}
			cout<<endl<<endl;
	        cout<<"The worked hours of those officers who work full day : "<<e1.getfull_employee_hours()<<endl<<endl;
		        
	        teh = e1.gett_no_employee() - tef;
			cout<<"Enter total number of officers working at cruise but not full day :  "<<teh<<endl<<endl;
		    cout<<"The worked hours of those officers who not work full day : "<<e1.gethalf_employee_hours()<<endl<<endl<<endl;
	        
	        cout<<"The salary of officers is '5000' per hour."<<endl<<endl;
		    cout<<"The salary of full day officers are:  "<<((e1.officers_full()) * tef)<<endl<<endl;
		    cout<<"The salary of officers not working full day : "<<((e1.officers_half()) * teh)<<endl<<endl;
		    int total_officers_salary = (((e1.officers_full()) * tef) + ((e1.officers_half()) * teh));
		    cout<<"The total amount of salaries of officers : "<<total_officers_salary << endl<<endl<<endl;
		    
		    ofstream officers_salary;
		    officers_salary.open("officers_salary.txt",ios::app);
		    officers_salary << e1.getfull_employee_hours() << "  " << e1.gethalf_employee_hours() << "  " << ((e1.officers_full()) * tef) << "  " << ((e1.officers_half()) * teh) << "  " << total_officers_salary << endl;
		    officers_salary.close();
		    
		     //Calculating total salaries of employees and salaries
		    cout<<endl<<endl;
		    int total_salaries_storing = (total_employee_salary + total_officers_salary);
		    cout<<"Total salaries is  =  "<<total_salaries_storing<<endl<<endl;
		    
		    ofstream total_salaries;
		    total_salaries.open("total_salaries.txt",ios::app);
		    total_salaries << total_salaries_storing <<endl;
		    total_salaries.close();
		}
		int get_salary()
	    {
	    	ifstream salary;
	    	int total_salaries_storing;
	    	salary.open("total_salaries.txt");
	    	salary >> total_salaries_storing;
	    	return total_salaries_storing;
	    	salary.close();
		}
	
};
int Employee :: t_no_employee = 50;
int Employee :: full_employee_hours = 8;
int Employee :: half_employee_hours = 6;
int Employee :: t_no_officers = 50;

class Menusss
{
	public:
		Booking b1;
		Passenger p1;
		Cabintype c1;
		ShipSearch search;
		// for cargo
		Cargo_login cl1;
		Freight freight;
		CargoInsurance ci1;
		Employee e1;
		
	void Passengers()
	{
		cout<<endl<<endl;
			cout<<"\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
			cout<<"\t\t\t\t\t\t@                  ==================================                   @"<<endl;
			cout<<"\t\t\t\t\t\t@                  ==================================                   @"<<endl;
			cout<<"\t\t\t\t\t\t@     -------->>>  Welcome ! to the Passenger Booking  <<<-------       @"<<endl;
			cout<<"\t\t\t\t\t\t@                  ==================================                   @"<<endl;
			cout<<"\t\t\t\t\t\t@                  ==================================                   @"<<endl;
			cout<<"\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
			cout<<endl<<endl;
			
			
		search.search();
			
		cout<<" ____________________________________________"<<endl;
		cout<<"|If you are choose the passenger.            |"<<endl;
		cout<<"|You must fillfull the following requiremnts.|"<<endl;
		cout<<"|And you firstly book the tickets.           |"<<endl;
		cout<<"|____________________________________________|"<<endl;
		cout<<endl;
			
			//Booking the passengers
			double ct;
			int c,p,tp,id;
			id = rand()%1000;
			cout<<" ___________________"<<endl;
			cout<<"|Your Booking ID is: |"<<endl;
			cout<<"|____________________|";
			cout<<"\t\t";
			cout<< id<<endl;
			
			cout<<" __________________________________________________________"<<endl;
			cout<<"|Enter the number of cabin required according to your need: |"<<endl;
			cout<<"|___________________________________________________________|";
			cout<<"\t\t";
			cin>>c;
			
			we:
			cout<<" ____________________________________________________"<<endl;
			cout<<"|Enter the number of passengers which are travelling: |"<<endl;
			cout<<"|_____________________________________________________|";
			cout<<"\t\t";
			cin>>p;
			if(p>2)
			{
				goto we;
			}
			
			cout<<" ______________________"<<endl;
			cout<<"|Enter the cabin type: |"<<endl;
			cout<<"|______________________|"<<endl;
			
			cout<<" ________________________________________________________________________________________________________________"<<endl;
			cout<<"|1. ----------------------------------------------Luxry----------------------------------------------------------|"<<endl;
			cout<<"|Followng facilities are given in luxry rooms                                                                    |"<<endl;
			cout<<"|a. AC rooms                                                                                                     |"<<endl;
			cout<<"|b. Royal Foods                                                                                                  |"<<endl;
			cout<<"|c. Sea views                                                                                                    |"<<endl;
			cout<<"|d. Entertainment                                                                                                |"<<endl;
			cout<<"|---------------->>>>>>>>>>>   But the price of Luxry cabin is 10,000 per day    <<<<<<<<<<----------------------|"<<endl;
			cout<<"|________________________________________________________________________________________________________________|"<<endl;
			cout<<endl;
			
			cout<<" ________________________________________________________________________________________________________________"<<endl;
			cout<<"|1. ----------------------------------------------Standarad------------------------------------------------------|"<<endl;
			cout<<"|Followng facilities are given in Standarad rooms                                                                |"<<endl;
			cout<<"|a. Air cooler rooms                                                                                             |"<<endl;
			cout<<"|b. Standarad foods                                                                                              |"<<endl;
			cout<<"|c. Simple & Far distance view                                                                                   |"<<endl;
			cout<<"|d. Little Entertainment                                                                                         |"<<endl;
			cout<<"|---------------->>>>>>>>>>>   But the price of Standarad cabin is 6,500 per day    <<<<<<<<<<-------------------|"<<endl;
			cout<<"|________________________________________________________________________________________________________________|"<<endl;
			cout<<endl;
			
			cout<<" ________________________________________________________________________________________________________________"<<endl;
			cout<<"|1. ----------------------------------------------Third class----------------------------------------------------|"<<endl;
			cout<<"|Followng facilities are given in Standarad rooms                                                                |"<<endl;
			cout<<"|a. Rooms withfans                                                                                               |"<<endl;
			cout<<"|b. Simple foods                                                                                                 |"<<endl;
			cout<<"|c. No any sea view view                                                                                         |"<<endl;
			cout<<"|d. No Entertainment                                                                                             |"<<endl;
			cout<<"|---------------->>>>>>>>>>>   But the price of Third class cabin is 3,500 per day    <<<<<<<<<<-----------------|"<<endl;
			cout<<"|________________________________________________________________________________________________________________|"<<endl;
			cout<<endl;
			cin>>ct;
			
			b1.setCabin(c);
			b1.setPassenger(p);
			b1.setcabin_type(ct);
			
			if(b1.getcabin_type() == 1)
			{
				cout<<" ______________________________"<<endl;
				cout<<"|You must submit this amount : |"<<endl;
				cout<<"|______________________________|";
				cout<<"\t\t";
				cout<<b1.getluxry_price()<<endl;
			}
			else if(b1.getcabin_type() == 2)
			{
				cout<<" ______________________________"<<endl;
				cout<<"|You must submit this amount : |"<<endl;
				cout<<"|______________________________|";
				cout<<"\t\t";
				cout<<b1.getStandarad_price()<<endl;
			}
			else if(b1.getcabin_type() == 3)
			{
				cout<<" ______________________________"<<endl;
				cout<<"|You must submit this amount : |"<<endl;
				cout<<"|______________________________|";
				cout<<"\t\t";
				cout<<b1.getThird_classp()<<endl;
			}
			dobara:
			cout<<" _________________________________________________________"<<endl;
			cout<<"|Enter the total price submitted according to your class: |"<<endl;
			cout<<"|_________________________________________________________|";
			cout<<"\t\t";
			cin>>tp;
			if(tp != b1.getluxry_price() && tp != b1.getStandarad_price() && tp != b1.getThird_classp())
			{
				cout<<" _________________________________________"<<endl;
				cout<<"|You don't give the actual payment.        |"<<endl;
				cout<<"|So, give me exact amount to proceed next. |"<<endl;
				cout<<"|__________________________________________|"<<endl;
				goto dobara;
			}
			
			b1.setToralPrice(tp);

			ofstream booking;
			booking.open("Booking.txt",ios::app);
			booking<<id<<"  "<<c<<"  "<<p<<"  "<<ct<<"  "<<tp<<"  "<<endl;
			booking.close();
				
			cout<<endl<<endl;
			// setting the passengers
			int pid,ap;
			string pn,n,g,mail;
			if(b1.getPassenger() == 1)
			{
				pid = rand()%1000;
				cout<<" ______________________"<<endl;
				cout<<"|The passenger id is : |"<<pid<<endl;
				cout<<"|______________________|"<<endl;
							
				cout<<" __________________________________"<<endl;
				cout<<"|Enter the name of the passengers: |"<<endl;
				cout<<"|__________________________________|";
				cout<<"\t\t";
				cin>>pn;
							
				cout<<" ________________________________"<<endl;
				cout<<"|Enter the gender of passengers :|"<<endl;
				cout<<"|________________________________|";
				cout<<"\t\t";
				cin>>g;
							
				cout<<" _______________________________________"<<endl;
				cout<<"|Enter the Nationallity of passengers : |"<<endl;
				cout<<"|_______________________________________|";
				cout<<"\t\t";
				cin>>n;
							
				cout<<" ______________________________"<<endl;
				cout<<"|Enter the age of passengers : |"<<endl;
				cout<<"|______________________________|";
				cout<<"\t\t";
				cin>>ap;
							
				cout<<" _________________________________________"<<endl;
				cout<<"|Enter the E-mail address of passengers : |"<<endl;
				cout<<"|_________________________________________|";
				cout<<"\t\t";
				cin>>mail;
				//p1.setPassengerId(pid);
				p1.setPassengerName(pn);
				p1.setGender(g);
				p1.setNationality(n);
				p1.setAge(ap);
				p1.setEmailAddress(mail);
								
				ofstream passenger;
				passenger.open("passenger.txt",ios::app);
				passenger<<pid<<"  "<<pn<<"  "<<g<<"  "<<n<<"  "<<ap<<"  "<<mail<<endl;
				passenger.close();
							
				//Checking the passengers data
				int count = 0;
				int pid_;
				char choice;
				ifstream passengers;
							
				cout<<endl<<endl;
				cout<<" ________________________________________________________________________"<<endl;
				cout<<"|You click 'y' or 'Y' if you want to check the biodata of the passenger. |"<<endl;
				cout<<"|If you click other key you dont get any biodata.                        |"<<endl;
				cout<<"|________________________________________________________________________|";
				cout<<"\t\t";
				cin>>choice;
							
				passengers.open("passenger.txt");
				if(choice == 'y' || choice == 'Y')
				{
					cout<<" __________________________________________"<<endl;
					cout<<"|Enter the ID of passenger to check data:  |"<<endl;
					cout<<"|__________________________________________|";
					cout<<"\t\t";
					cin>>pid_;
					while(passengers.eof()==0)
					{
						passengers>>pid>>pn>>g>>n>>ap>>mail;
						if(pid==pid_)
						{
							count = 1;
							cout<<" __________________________________"<<endl;
							cout<<"|ID: "<< pid<<endl;
							cout<<"|Name: "<<pn<<endl;
							cout<<"|Gender: "<<g<<endl;
							cout<<"|Nationallity: "<<n<<endl;
							cout<<"|Age: "<<ap<<endl;
							cout<<"|G-Mail: "<<mail<<endl;
							cout<<"|__________________________________"<<endl;
							break;
						}
					}
					passengers.close();
				}
				else if(count==0)
				{
				cout<<" ___________________________"<<endl;
				cout<<"|Passenger does not exsists.|"<<endl;
				cout<<"|___________________________|"<<endl;
				}
		}
			
			else if(b1.getPassenger() == 2)
			{
					for(int i=0;i<2;i++)
					{
						pid = rand()%1000;
						cout<<" ______________________"<<endl;
						cout<<"|The passenger id is : |"<<pid<<endl;
						cout<<"|______________________|"<<endl;
						
						cout<<" __________________________________"<<endl;
						cout<<"|Enter the name of the passengers: |"<<endl;
						cout<<"|__________________________________|";
						cout<<"\t\t";
						cin>>pn;
						
						cout<<" ________________________________"<<endl;
						cout<<"|Enter the gender of passengers :|"<<endl;
						cout<<"|________________________________|";
						cout<<"\t\t";
						cin>>g;
						
						cout<<" _______________________________________"<<endl;
						cout<<"|Enter the Nationallity of passengers : |"<<endl;
						cout<<"|_______________________________________|";
						cout<<"\t\t";
						cin>>n;
						
						cout<<" ______________________________"<<endl;
						cout<<"|Enter the age of passengers : |"<<endl;
						cout<<"|______________________________|";
						cout<<"\t\t";
						cin>>ap;
						
						cout<<" _________________________________________"<<endl;
						cout<<"|Enter the E-mail address of passengers : |"<<endl;
						cout<<"|_________________________________________|";
						cout<<"\t\t";
						cin>>mail;
						//p1.setPassengerId(pid);
						p1.setPassengerName(pn);
						p1.setGender(g);
						p1.setNationality(n);
						p1.setAge(ap);
						p1.setEmailAddress(mail);
							
						ofstream passenger;
						passenger.open("passenger.txt",ios::app);
						passenger<<pid<<"  "<<pn<<"  "<<g<<"  "<<n<<"  "<<ap<<"  "<<mail<<endl;
						passenger.close();
						
						//Checking the passengers data
						int count = 0;
						int pid_;
						char choice;
						ifstream passengers;
						
						cout<<endl<<endl;
						cout<<" ________________________________________________________________________"<<endl;
						cout<<"|You click 'y' or 'Y' if you want to check the biodata of the passenger. |"<<endl;
						cout<<"|If you click other key you dont get any biodata.                        |"<<endl;
						cout<<"|________________________________________________________________________|";
						cout<<"\t\t";
						cin>>choice;
						
						passengers.open("passenger.txt");
						if(choice == 'y' || choice == 'Y')
						{
							cout<<" __________________________________________"<<endl;
							cout<<"|Enter the ID of passenger to check data:  |"<<endl;
							cout<<"|__________________________________________|";
							cout<<"\t\t";
							cin>>pid_;
							while(passengers.eof()==0)
							{
								passengers>>pid>>pn>>g>>n>>ap>>mail;
								if(pid==pid_)
								{
									count = 1;
									cout<<" __________________________________"<<endl;
									cout<<"|ID: "<< pid<<endl;
									cout<<"|Name: "<<pn<<endl;
									cout<<"|Gender: "<<g<<endl;
									cout<<"|Nationallity: "<<n<<endl;
									cout<<"|Age: "<<ap<<endl;
									cout<<"|G-Mail: "<<mail<<endl;
									cout<<"|__________________________________"<<endl;
									break;
								}
							}
							passengers.close();
						}
						else if(count==0)
						{
							cout<<" ___________________________"<<endl;
							cout<<"|Passenger does not exsists.|"<<endl;
							cout<<"|___________________________|"<<endl;
						}
					}
			}
			
			
			
			cout<<" _______________________________________"<<endl;
			cout<<"|Accrding to the choice of the passenger.|"<<endl;
			cout<<"|________________________________________|"<<endl;
			if(b1.getcabin_type()==1)
			{
				cout<<" __________________________________"<<endl;
				cout<<"|Passenger choose the luxry cabin.  |"<<endl;
				cout<<"|So they have variety of facilties. |"<<endl;
				cout<<"|___________________________________|"<<endl;
				string ft,bv,enter,loc;
				
				//Food items
				luxry_food:
				cout<<" ___________________________________________"<<endl;
				cout<<"|Follwing food items which are you select:  |"<<endl;
				cout<<"|1. Meat                                    |"<<endl;
				cout<<"|2. pastas                                  |"<<endl;
				cout<<"|3. sweets                                  |"<<endl;
				cout<<"|4. Vegetable                               |"<<endl;
				cout<<"|5. rice                                    |"<<endl;
				cout<<"|6. Kababs                                  |"<<endl;
				cout<<"|7. Fast_foods                              |"<<endl;
				cout<<"|8. BarbQ                                   |"<<endl;
				cout<<"|9. Ice_creams                              |"<<endl;
				cout<<"|___________________________________________|"<<endl;
				cin>>ft;
				
				char option;
				cout<<" _________________________________________________________"<<endl;	
				cout<<"|You click 'y' or 'Y' if you want to order some more food.|"<<endl;
				cout<<"|If you click other key you dont get any food.            |"<<endl;
				cout<<"|_________________________________________________________|";
				cin>>option;
				
				    ofstream luxry_type;
					luxry_type.open("luxry_type.txt",ios::app);
					luxry_type<<pid<<"   "<<ft;
					luxry_type.close();
					
				if(option == 'Y' || option == 'y')
				{
					goto luxry_food;
				}
				
				c1.setfooditems(ft);
					
				//Beverages
				luxry_beveage:
				cout<<" _______________________________________________"<<endl;	
				cout<<"|Follwing Beverages items which are you select:  |"<<endl;
				cout<<"|1. Mineral_water                                |"<<endl;
				cout<<"|2. Distilled_water                              |"<<endl;
				cout<<"|3. Soft_Drinks                                  |"<<endl;
				cout<<"|4. Power_Drinks                                 |"<<endl;
				cout<<"|5. Juices                                       |"<<endl;
				cout<<"|6. Slushes                                      |"<<endl;
				cout<<"|7. Milk_Shakes                                  |"<<endl;
				cout<<"|________________________________________________|"<<endl;	
				cin>>bv;

				char options;
				cout<<" ______________________________________________________________"<<endl;	
				cout<<"|You click 'y' or 'Y' if you want to order some more beverages.|"<<endl;
				cout<<"|If you click other key you dont get any beverages.            |"<<endl;
				cout<<"|______________________________________________________________|";
				cin>>options;
				
					ofstream luxry_types;
					luxry_types.open("luxry_type.txt",ios::app);
					luxry_types<<"   "<<bv;
					luxry_types.close();
				if(options == 'y' || options == 'Y')
				{
					goto luxry_beveage;
				}	
				c1.setbeverages(bv);
					
				//Entertainment
				luxry_entertainment:
				cout<<" ________________________________________________"<<endl;
				cout<<"|Follwing Beverages items which are you select:  |"<<endl;
				cout<<"|1. Swimming                                     |"<<endl;
				cout<<"|2. Scadding                                     |"<<endl;
				cout<<"|3. Boat_Riding                                  |"<<endl;
				cout<<"|4. Boat_Driving                                 |"<<endl;
				cout<<"|5. Party                                        |"<<endl;
				cout<<"|________________________________________________|"<<endl;
				cin>>enter;
				
					ofstream luxry_typess;
					luxry_typess.open("luxry_type.txt",ios::app);
					luxry_typess<<"   "<<enter;
					luxry_typess.close();
					
				char optionss;
				cout<<" __________________________________________________________________"<<endl;	
				cout<<"|You click 'y' or 'Y' if you want to order some more Entertainment.|"<<endl;
				cout<<"|If you click other key you dont get any Entertainment.            |"<<endl;
				cout<<"|__________________________________________________________________|";
				cin>>optionss;
				
				if(optionss == 'Y' || optionss == 'y')
				{
					goto luxry_entertainment;
				}	
				c1.setentertainment(enter);
					
		
				//Location
				luxry_location:
				cout<<" _____________________________________________________________"<<endl;	
				cout<<"|You set your location in the cruise according to your choice. |"<<endl;
				cout<<"|1. Sea_view                                                   |"<<endl;
				cout<<"|2. On_the_roof                                                |"<<endl;
				cout<<"|3. In_the_basements                                           |"<<endl;
				cout<<"|4. Balcony_view                                               |"<<endl;
				cout<<"|______________________________________________________________|"<<endl;	
				cin>>loc;
				
				char optionsss;
				cout<<" _____________________________________________________________"<<endl;	
				cout<<"|You click 'y' or 'Y' if you want to order some more Location.|"<<endl;
				cout<<"|If you click other key you dont get any Location.            |"<<endl;
				cout<<"|_____________________________________________________________|";
				cin>>optionsss;
				
					ofstream luxry_typesss;
					luxry_typesss.open("luxry_type.txt",ios::app);
					luxry_typesss<<"   "<<loc;
					luxry_typesss.close();
					
				
				if(optionsss == 'Y' || optionsss == 'y')
				{
					goto luxry_location;
				}	
				c1.setlocation(loc);
				
				
				
			}
			else if(b1.getcabin_type()==2)
			{
				cout<<" _______________________________________"<<endl;	
				cout<<"|Passenger choose the Standarad cabin.   |"<<endl;
				cout<<"|So they have variety of facilties.      |"<<endl;
				cout<<"|________________________________________|"<<endl;	
				string ft,bv,enter,loc;
				
				//Food items
				Standarad_food:
				cout<<" __________________________________________"<<endl;	
				cout<<"|Follwing food items which are you select:  |"<<endl;
				cout<<"|1. Meat_with_breads                        |"<<endl;
				cout<<"|2. sweets                                  |"<<endl;
				cout<<"|3. Vegetables_Cerieals                     |"<<endl;
				cout<<"|4. Different_types_of_rice                 |"<<endl;
				cout<<"|5. Ice_creams                              |"<<endl;
				cout<<"|___________________________________________|"<<endl;	
				cin>>ft;
				
				char option;
				cout<<" _________________________________________________________"<<endl;	
				cout<<"|You click 'y' or 'Y' if you want to order some more food.|"<<endl;
				cout<<"|If you click other key you dont get any food.            |"<<endl;
				cout<<"|_________________________________________________________|";
				cin>>option;
				
					ofstream Standarad_type;
					Standarad_type.open("Standarad_type.txt",ios::app);
					Standarad_type<<pid<<"   "<<ft;
					Standarad_type.close();
				
				if(option == 'Y' || option == 'y')
				{
					goto Standarad_food;
				}
				
				c1.setfooditems(ft);
					
				//Beverages
				Standarad_beveage:
				cout<<" ________________________________________________"<<endl;
				cout<<"|Follwing Beverages items which are you select:  |"<<endl;
				cout<<"|1. Mineral_water                                |"<<endl;
				cout<<"|2. Distilled_water                              |"<<endl;
				cout<<"|3. Soft_Drinks                                  |"<<endl;
				cout<<"|5. Juices                                       |"<<endl;
				cout<<"|________________________________________________|"<<endl;
				cin>>bv;

				char options;
				cout<<" ______________________________________________________________"<<endl;	
				cout<<"|You click 'y' or 'Y' if you want to order some more beverages.|"<<endl;
				cout<<"|If you click other key you dont get any beverages.            |"<<endl;
				cout<<"|______________________________________________________________|";
				cin>>options;
				
					ofstream Standarad_types;
					Standarad_types.open("Standarad_type.txt",ios::app);
					Standarad_types<<"   "<<bv;
					Standarad_types.close();
				
				if(options == 'Y' || options == 'y')
				{
					goto Standarad_beveage;
				}	
				c1.setbeverages(bv);
					
				//Entertainment
				Standarad_entertainment:
				cout<<" ________________________________________________"<<endl;
				cout<<"|Follwing Beverages items which are you select:  |"<<endl;
				cout<<"|1. Swimming                                     |"<<endl;
				cout<<"|2. Scadding                                     |"<<endl;
				cout<<"|________________________________________________|"<<endl;
				cin>>enter;
				
				char optionss;
				cout<<" __________________________________________________________________"<<endl;	
				cout<<"|You click 'y' or 'Y' if you want to order some more Entertainment.|"<<endl;
				cout<<"|If you click other key you dont get any Entertainment.            |"<<endl;
				cout<<"|__________________________________________________________________|";
				cin>>optionss;
				
					ofstream Standarad_typess;
					Standarad_typess.open("Standarad_type.txt",ios::app);
					Standarad_typess<<"   "<<enter;
					Standarad_typess.close();
				
				if(optionss == 'Y' || optionss == 'y')
				{
					goto Standarad_entertainment;
				}	
				c1.setentertainment(enter);
					
		
				//Location
				Standarad_location:
				cout<<" _____________________________________________________________"<<endl;	
				cout<<"|You set your location in the cruise according to your choice. |"<<endl;
				cout<<"|1. Sea_view                                                   |"<<endl;
				cout<<"|2. On_the_roof                                                |"<<endl;
				cout<<"|______________________________________________________________|"<<endl;	
				cin>>loc;
				
				char optionsss;
				cout<<" _____________________________________________________________"<<endl;	
				cout<<"|You click 'y' or 'Y' if you want to order some more Location.|"<<endl;
				cout<<"|If you click other key you dont get any Location.            |"<<endl;
				cout<<"|_____________________________________________________________|";
				cin>>optionsss;
				
					ofstream Standarad_typesss;
					Standarad_typesss.open("Standarad_type.txt",ios::app);
					Standarad_typesss<<"   "<<loc<<endl;
					Standarad_typesss.close();
				
				if(optionsss == 'Y' || optionsss == 'y')
				{
					goto Standarad_location;
				}	
				c1.setlocation(loc);
				

				}
				
			else if(b1.getcabin_type()==3)
			{
				string ft,bv,enter,loc;
				cout<<" _____________________________________________________________________________________________"<<endl;	
				cout<<"|Passenger choose the Third class  cabin.                                                      |"<<endl;
				cout<<"|So they don't have any facilities and avail only those whch are offered by management to them.|"<<endl;
				cout<<"|_____________________________________________________________________________________________|"<<endl;	
				//Foods Beverages Entertainment Location
				
				Thirdclass_food:
				cout<<" __________________________________________"<<endl;	
				cout<<"|Follwing food items which are you select:  |"<<endl;
				cout<<"|1. Meat_with_breads                        |"<<endl;
				cout<<"|2. sweets                                  |"<<endl;
				cout<<"|3. Vegetables_Cerieals                     |"<<endl;
				cout<<"|4. Different_types_of_rice                 |"<<endl;
				cout<<"|___________________________________________|"<<endl;	
				cin>>ft;
				
				char option;
				cout<<" _________________________________________________________"<<endl;	
				cout<<"|You click 'y' or 'Y' if you want to order some more food.|"<<endl;
				cout<<"|If you click other key you dont get any food.            |"<<endl;
				cout<<"|_________________________________________________________|";
				cin>>option;
				
					ofstream Thirdclass_type;
					Thirdclass_type.open("thirdclass_type.txt",ios::app);
					Thirdclass_type<<pid<<"   "<<ft;
					Thirdclass_type.close();
				
				if(option == 'Y' || option == 'y')
				{
					goto Thirdclass_food;
				}
				
				c1.setfooditems(ft);
				
				Thirdclass_beverage:
				cout<<" ________________________________________________"<<endl;
				cout<<"|Follwing Beverages items which are you select:  |"<<endl;
				cout<<"|1. Mineral_water                                |"<<endl;
				cout<<"|2. Soft_Drinks                                  |"<<endl;
				cout<<"|________________________________________________|"<<endl;
				cin>>bv;
				
				char options;
				cout<<" ______________________________________________________________"<<endl;	
				cout<<"|You click 'y' or 'Y' if you want to order some more beverages.|"<<endl;
				cout<<"|If you click other key you dont get any beverages.            |"<<endl;
				cout<<"|______________________________________________________________|";
				cin>>options;
				
					ofstream Thirdclass_types;
					Thirdclass_types.open("thirdclass_type.txt",ios::app);
					Thirdclass_types<<pid<<"   "<<bv;
					Thirdclass_types.close();
				
				if(option == 'Y' || option == 'y')
				{
					goto Thirdclass_beverage;
				}
				
				c1.setfooditems(ft);
				
				Thirdclass_entertainment:
				cout<<" _____________________________________________________"<<endl;
				cout<<"|Follwing Beverages items which are you select:       |"<<endl;
				cout<<"|1. Only Swimming                                     |"<<endl;
				cout<<"|_____________________________________________________|"<<endl;
				cin>>enter;
				
				
					ofstream Thirdclass_typess;
					Thirdclass_typess.open("thirdclass_type.txt",ios::app);
					Thirdclass_typess<<pid<<"   "<<enter;
					Thirdclass_typess.close();
				
				c1.setfooditems(ft);
				
				cout<<" ____________________________________________________________"<<endl;
				cout<<"|You set your location in the cruise according to your choice |"<<endl;
				cout<<"|1. Only Sea_view                                             |"<<endl;
				cout<<"|_____________________________________________________________|"<<endl;
				cin>>loc;
				
				
					ofstream Thirdclass_typesss;
					Thirdclass_typesss.open("thirdclass_type.txt",ios::app);
					Thirdclass_typesss<<pid<<"   "<<loc<<endl;
					Thirdclass_typesss.close();
				
			}
			
		cout<<endl<<endl<<endl<<endl;
		cout<<"\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
		cout<<"\t\t\t\t\t%                              =================================================                                         %"<<endl;
		cout<<"\t\t\t\t\t%                              Allhamdullilah  you booked passenger successfully                                         %"<<endl;
		cout<<"\t\t\t\t\t%                              =================================================                                         %"<<endl;
		cout<<"\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
		cout<<endl<<endl<<endl<<endl;
	}
	
	void Cargo()
	{
		int choice;
			cout<<endl<<endl;
			cout<<"\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
			cout<<"\t\t\t\t\t\t@                  ==============================                       @"<<endl;
			cout<<"\t\t\t\t\t\t@                  ==============================                       @"<<endl;
			cout<<"\t\t\t\t\t\t@     -------->>>  Welcome ! to the Cargo Booking  <<<-----------       @"<<endl;
			cout<<"\t\t\t\t\t\t@                  ==============================                       @"<<endl;
			cout<<"\t\t\t\t\t\t@                  ==============================                       @"<<endl;
			cout<<"\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
			cout<<endl<<endl;
			
			again:
			cout<<"\t ___________________________"<<endl;
			cout<<"\t|1. Already book cargo      |"<<endl;
			cout<<"\t|___________________________|"<<endl;
			cout<<"\t|2. New Booker              |" <<endl;
			cout<<"\t|___________________________|"<<endl;
			cout<<"\t|3.Exit the cargo services. |"<<endl;
			cout<<"\t|___________________________|"<<endl;
			
			cout<<endl<<endl;
			cout<<"\t _____________________________"<<endl;
			cout<<"\t|Enter your choice from above.|"<<endl;
			cout<<"\t|_____________________________|";
			cout<<"\t\t";
			cin>>choice;
			if(choice == 1)
			{
				if(cl1.islogin()==1)
				{
					cout<<endl<<endl;
					cout<<"\t\t\t\t\t _____________________________________________"<<endl;
					cout<<"\t\t\t\t\t|If you are choose the Cargo services.        |"<<endl;
					cout<<"\t\t\t\t\t|You must fillfull the following requiremnts. |"<<endl;
					cout<<"\t\t\t\t\t|_____________________________________________|"<<endl;
					cout<<endl;
					
					int ms,noc,price,id,nocon;
					string n;
					double w,l,width;
					id = rand()%1000;
					
					cout<<endl<<endl;
					cout<<"\t ___________________________________________________________________________________"<<endl;
					cout<<"\t|Enter the appropriate type of material so assigned cargo according to it.          |"<<endl;
					cout<<"\t|___________________________________________________________________________________|"<<endl;
					cout<<"\t|1.  Hazardious Material (Chemicals,Biological Substances,RadioActive Substances) : |"<<endl;
					cout<<"\t|2.  Pershuble foods (Meat,Diary Products, Pharmaceuticals, Flowers and plants) :   |"<<endl;
					cout<<"\t|3.  High value items (Computers , Smart Phones, Jewlery, Antiques things) :        |"<<endl;
					cout<<"\t|4.  Oversized and heavy Cargo (Vehicles, Industrial & Construction products) :     |"<<endl;
					cout<<"\t|___________________________________________________________________________________|";
					cout<<"\t\t";
					cin>>ms;
					cout<<endl;
					
					cout<<endl<<endl;
					cout<<"\t _________________________________"<<endl;
					cout<<"\t|The id of the product id is:     |"<<endl;
					cout<<"\t|_________________________________|";
					cout<<"\t\t";
					cout<<id<<endl;
					
					cout<<endl<<endl;
					cout<<"\t _________________________________"<<endl;
					cout<<"\t|Enter the name of the product :  |"<<endl;
					cout<<"\t|_________________________________|";
					cout<<"\t\t";
					cin>>n;
					
					cout<<endl<<endl;
					cout<<"\t _________________________________"<<endl;
					cout<<"\t|Enter the weight of the product: |"<<endl;
					cout<<"\t|_________________________________|";
					cout<<"\t\t";
					cin>>w;
					
					cout<<endl<<endl;
					cout<<"\t _________________________________"<<endl;
					cout<<"\t|Enter the width of the product:  |"<<endl;
					cout<<"\t|_________________________________|";
					cout<<"\t\t";
					cin>>width;
					
					cout<<endl<<endl;
					cout<<"\t _________________________________"<<endl;
					cout<<"\t|Enter the length of the product: |"<<endl;
					cout<<"\t|_________________________________|";
					cout<<"\t\t";
					cin>>l;
					
					cout<<endl<<endl;
					cout<<"\t ________________________________________"<<endl;
					cout<<"\t|Enter the number of cartons/bags/items: |"<<endl;
					cout<<"\t|________________________________________|";
					cout<<"\t\t";
					cin>>noc;
					
					freight.setmaterialSensitivity(ms);
					freight.setname(n);
					freight.setweight(w);
					freight.setwidth(width);
					freight.setlength(l);
					freight.setnoOfCartons(noc);
					
					if(freight.getmaterialSensitivity() == 1)
					{
						cout<<endl<<endl;
						cout<<"\t ______________________________"<<endl;
						cout<<"\t|You must submit this amount:  |"<<endl;
						cout<<"\t|______________________________|";
						cout<<"\t\t";
						cout<<freight.gethazardPrice()<<endl;
					}
					
					else if(freight.getmaterialSensitivity() == 2)
					{
						cout<<endl<<endl;
						cout<<"\t ______________________________"<<endl;
						cout<<"\t|You must submit this amount:  |"<<endl;
						cout<<"\t|______________________________|";
						cout<<"\t\t";
						cout<<freight.getfoodPrice()<<endl;
					}
					
					else if(freight.getmaterialSensitivity() == 3)
					{
						cout<<endl<<endl;
						cout<<"\t ______________________________"<<endl;
						cout<<"\t|You must submit this amount:  |"<<endl;
						cout<<"\t|______________________________|";
						cout<<"\t\t";
						cout<<freight.gethighPrice()<<endl;
					}
					
					else if(freight.getmaterialSensitivity() == 4)
					{
						cout<<endl<<endl;
						cout<<"\t ______________________________"<<endl;
						cout<<"\t|You must submit this amount:  |"<<endl;
						cout<<"\t|______________________________|";
						cout<<"\t\t";
						cout<<freight.getvehiclePrice()<<endl;
					}
					
					nxt:
					cout<<endl<<endl;
					cout<<"\t ________________________________________________________________"<<endl;		
					cout<<"\t|Enter the total price submitted according to your booked cargo: |"<<endl;
					cout<<"\t|________________________________________________________________|";
					cout<<"\t\t";
					cin>>price;
					if(price != freight.gethazardPrice() && price != freight.getfoodPrice() && price != freight.gethighPrice() && price != freight.getvehiclePrice())
					{
						cout<<endl<<endl;
						cout<<"\t ___________________________________________"<<endl;		
						cout<<"\t|You don't give the actual payment.         |"<<endl;
						cout<<"\t|So, give me exact amount to proceed next.  |"<<endl;
						cout<<"\t|___________________________________________|"<<endl;
						goto nxt;
					}
					
					
					if(freight.getnoOfCartons() >= 1 && freight.getnoOfCartons() <=500)
					{
						nocon = 1;
						cout<<"\t _____________________________________________________________________"<<endl;
						cout<<"\t|According to your products we booked  "<<nocon<<"  Container for you.		|"<<endl;
						cout<<"\t|_____________________________________________________________________|"<<endl;
					}
					else if(freight.getnoOfCartons() >= 501 && freight.getnoOfCartons() <=1000)
					{
						nocon = 2;
						cout<<"\t _____________________________________________________________________"<<endl;
						cout<<"\t|According to your products we booked  "<<nocon<<"  Container for you.		|"<<endl;
						cout<<"\t|_____________________________________________________________________|"<<endl;
					}
					else if(freight.getnoOfCartons() >= 1001 && freight.getnoOfCartons() <=2000)
					{
						nocon = 3;
						cout<<"\t _____________________________________________________________________"<<endl;
						cout<<"\t|According to your products we booked  "<<nocon<<"  Container for you.		|"<<endl;
						cout<<"\t|_____________________________________________________________________|"<<endl;
					}
					else if(freight.getnoOfCartons() >= 2001 && freight.getnoOfCartons() <=3000)
					{
						nocon = 4;
						cout<<"\t _____________________________________________________________________"<<endl;
						cout<<"\t|According to your products we booked  "<<nocon<<"  Container for you.		|"<<endl;
						cout<<"\t|_____________________________________________________________________|"<<endl;
					}
					else
					{
						nocon = 5;
						cout<<"\t _____________________________________________________________________"<<endl;
						cout<<"\t|According to your products we booked  "<<nocon<<"  Container for you.		|"<<endl;
						cout<<"\t|_____________________________________________________________________|"<<endl;
					}
					
					freight.setprice(price);
					freight.setnoOfContainers(nocon);
		
					ofstream cargo_booking;
					cargo_booking.open("cargo_booking.txt",ios::app);
					cargo_booking<<id<<"  "<<ms<<"  "<<n<<"  "<<w<<"  "<<width<<"  "<<l<<"  "<<noc<<"  "<<price<<"  "<<nocon<<endl;
					cargo_booking.close();
					
					char option;
					cout<<endl<<endl<<endl;
					cout<<"\t _________________________________________________________"<<endl;
					cout<<"\t|Enter the choice whether you insure your products or not.|"<<endl;
					cout<<"\t|If you insure your product than click 'Y' or 'y' .       |"<<endl;
					cout<<"\t|Else you click any key.                                  |"<<endl;
					cout<<"\t|_________________________________________________________|";
					cout<<"\t\t";
					cin>>option;
					
					if(option == 'Y' ||  option == 'y')
					{
						insure:
						int insuranceID,t,insurrancePrice;
						string n;
						insuranceID = rand()%1000;
						cout<<endl<<endl;
						cout<<"\t ___________________________________"<<endl;
						cout<<"\t|The insurance ID given to you is:  |"<<endl;
						cout<<"\t|___________________________________|";
						cout<<"\t\t";
						cout<<insuranceID<<endl;
						
						cout<<endl<<endl;
						cout<<"\t ____________________________________"<<endl;
						cout<<"\t|Enter the name of insurance holder: |"<<endl;
						cout<<"\t|____________________________________|";
						cout<<"\t\t";
						cin>>n;
						
						cout<<endl<<endl;
						cout<<"\t __________________________________________________"<<endl;
						cout<<"\t|There are following types of insurances:          |"<<endl;
						cout<<"\t|__________________________________________________|"<<endl;
						cout<<"\t|1.  Loss or damage.                               |"<<endl;
						cout<<"\t|2.  Theft damage.                                 |"<<endl;
						cout<<"\t|3.  Liability (third-party damage or injury).     |"<<endl;
						cout<<"\t|4.  Select all.                                   |"<<endl;
						cout<<"\t|__________________________________________________|"<<endl;
						cout<<"\t|Enter your choice to select the type of insurance.|"<<endl;
						cout<<"\t|__________________________________________________|";
						cout<<"\t\t";
						cin>>t;
						
						ci1.setInsuranceId(insuranceID);
						ci1.setProviderName(n);
						ci1.setCoverageType(t);
						
						int insurranceAmount;
						if(ci1.getCoverageType() == 1)
						{
							insurranceAmount = (1000 * freight.getnoOfContainers());
							cout<<endl<<endl;
							cout<<"\t _____________________________"<<endl;
							cout<<"\t|You must submit this amount: |"<<endl;
							cout<<"\t|_____________________________|";
							cout<<"\t\t";
							cout<<insurranceAmount<<endl;
						}
						else if(ci1.getCoverageType() == 2)
						{
							insurranceAmount = (1000 * freight.getnoOfContainers());
							cout<<endl<<endl;
							cout<<"\t _____________________________"<<endl;
							cout<<"\t|You must submit this amount: |"<<endl;
							cout<<"\t|_____________________________|";
							cout<<"\t\t";
							cout<<insurranceAmount<<endl;
						}
						else if(ci1.getCoverageType() == 3)
						{
							insurranceAmount = (1000 * freight.getnoOfContainers());
							cout<<endl<<endl;
							cout<<"\t _____________________________"<<endl;
							cout<<"\t|You must submit this amount: |"<<endl;
							cout<<"\t|_____________________________|";
							cout<<"\t\t";
							cout<<insurranceAmount<<endl;
						}
						else if(t == 4)
						{
							insurranceAmount = (3000 * freight.getnoOfContainers());
							cout<<endl<<endl;
							cout<<"\t _____________________________"<<endl;
							cout<<"\t|You must submit this amount: |"<<endl;
							cout<<"\t|_____________________________|";
							cout<<"\t\t";
							cout<<insurranceAmount<<endl;
						}
						
						nxts:
						cout<<endl<<endl;
						cout<<"\t ___________________________________________________________________________"<<endl;
						cout<<"\t|Enter the total price submitted according to your booked cargo insurance : |"<<endl;
						cout<<"\t|___________________________________________________________________________|";
						cout<<"\t\t";
						cin>>insurrancePrice;
						if(insurrancePrice != insurranceAmount)
						{
							cout<<endl<<endl;
							cout<<"\t ___________________________________________________"<<endl;
							cout<<"\t|You don't give the actual payment.                 |"<<endl;
							cout<<"\t|So, give me exact amount to proceed next.          |"<<endl;
							cout<<"\t|___________________________________________________|"<<endl;
							goto nxts;
						}
						ci1.setprice(insurrancePrice);
						
						ofstream insurance;
						insurance.open("insurance.txt",ios::app);
						insurance<<insuranceID<<"  "<<n<<"  "<<t<<"  "<<insurrancePrice<<endl;
						insurance.close();
						
					}
					else
					{
						cout<<endl<<endl;
						cout<<"\t __________________________________________________________"<<endl;
						cout<<"\t|There is not any gurantee of your products is safe.       |"<<endl;
						cout<<"\t|In case of any emergency if your product is destroyed.    |"<<endl;
						cout<<"\t|Than management of our cruise is not resposible........   |"<<endl;
						cout<<"\t|__________________________________________________________|"<<endl;
					}
					char insure;
					cout<<"\t _______________________________________________________________________"<<endl;
					cout<<"\t|If you are sure not to take insurance press any key except 'Y' or 'y'. |"<<endl;
					cout<<"\t|_______________________________________________________________________|";
					cout<<"\t\t";
					cin>>insure;
					if(insure == 'Y' || insure == 'y')
					{
						goto insure;
					}
					else
					{
						cout<<"\t ________________"<<endl;
						cout<<"\t| As Your Choice.|"<<endl;
						cout<<"\t|________________|"<<endl;
					}
					
					
				}
				
			}	
			else if(choice == 2)
			{
				cl1.registerUser();
				cout<<endl<<endl;
				cout<<"\t ___________________________________"<<endl;
				cout<<"\t|You are successfully registered.   |"<<endl;
				cout<<"\t|___________________________________|"<<endl;
				cout<<"\t|Now you click 'Already book cargo'.|"<<endl;
				cout<<"\t|___________________________________|"<<endl;
				cout<<endl<<endl<<endl;
				goto again;
			}
				
			else if(choice == 3)
			{
				cout<<endl<<endl;
				cout<<"\t __________________________"<<endl;
				cout<<"\t|Exit the cargo services.  |"<<endl;
				cout<<"\t|__________________________|"<<endl;
			}
		cout<<endl<<endl<<endl<<endl;
		cout<<"\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
		cout<<"\t\t\t\t\t%                              =============================================                                         %"<<endl;
		cout<<"\t\t\t\t\t%                              Allhamdullilah  you booked Cargo successfully                                         %"<<endl;
		cout<<"\t\t\t\t\t%                              =============================================                                         %"<<endl;
		cout<<"\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
		cout<<endl<<endl<<endl<<endl;
	}
	
	void Management()
	{
			cout<<endl<<endl;
			cout<<"\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
			cout<<"\t\t\t\t\t\t@                  ==============================                       @"<<endl;
			cout<<"\t\t\t\t\t\t@                  ==============================                       @"<<endl;
			cout<<"\t\t\t\t\t\t@     -------->>>   Welcome ! to the Management    <<<-----------       @"<<endl;
			cout<<"\t\t\t\t\t\t@                  ==============================                       @"<<endl;
			cout<<"\t\t\t\t\t\t@                  ==============================                       @"<<endl;
			cout<<"\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
			cout<<endl<<endl;
			
			management:
			int officers;
			cout<<"\t ____________________________"<<endl;
			cout<<"\t|Enter the type of officers. |"<<endl;
			cout<<"\t|____________________________|"<<endl;
			cout<<"\t|1.  Check Officer.          |"<<endl;
			cout<<"\t|2.  Updation Officer.       |"<<endl;
			cout<<"\t|3.  Finance Officer.        |"<<endl;
			cout<<"\t|____________________________|";
			cout<<"\t\t";
			cin>>officers;
			cout<<endl;
			
			if(officers == 1)
			{
				int choose;
				cout<<endl<<endl;
				cout<<"\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
				cout<<"\t\t\t\t\t\t&   Checking Information of passengers and Cargos.    &"<<endl;
				cout<<"\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
				
				check:
				cout<<endl<<endl<<endl;
				cout<<"\t ____________________________________"<<endl;
				cout<<"\t|Enter the choice whether you check: |"<<endl;
				cout<<"\t|____________________________________|"<<endl;
				cout<<"\t|1. Passengers.                      |"<<endl;
				cout<<"\t|2. Cargos.                          |"<<endl;
				cout<<"\t|3. Exit                             |"<<endl;
				cout<<"\t|____________________________________|";
				cout<<"\t\t";
				cin>>choose;
				
				
				if(choose == 1)
				{
					int opt;
					check_pass:
					cout<<endl<<endl<<endl;
					cout<<"\t\t _______________________________"<<endl;
					cout<<"\t\t|Enter which details you see :  |" <<endl;
					cout<<"\t\t|_______________________________|"<<endl;
					cout<<"\t\t|1. Booking details.            |"<<endl;
					cout<<"\t\t|2. Passengers details.         |" <<endl;
					cout<<"\t\t|3. Exit                        |"<<endl;
					cout<<"\t\t|_______________________________|";
					cout<<"\t\t";
					cin>>opt;
					
					if(opt == 1)
					{
						//Booking details
						cout<<endl<<endl<<endl;
						cout<<"\t\t\t\t _____________________"<<endl;
						cout<<"\t\t\t\t|Booking details are: |"<<endl;
						cout<<"\t\t\t\t|_____________________|"<<endl;
						int count = 0;
						double ct;
						int c,p,tp,id,id_;
						ifstream bookinging;
					
						bookinging.open("Booking.txt");
						cout<<endl<<endl<<endl;
						cout<<"\t\t\t\t _____________________________________"<<endl;
						cout<<"\t\t\t\t|Enter the Booking ID to check data:  |"<<endl;
						cout<<"\t\t\t\t|_____________________________________|";
						cout<<"\t\t";
						cin>>id_;
						
						while(bookinging.eof() == 0)
						{
							bookinging>>id>>c>>p>>ct>>tp;
							if(id==id_)
							{
								count = 1;
								cout<<"\t\t\t\t _________"<<endl;
								cout<<"\t\t\t\t|ID:      |"<<endl;
								cout<<"\t\t\t\t|_________|";
								cout<<"\t\t";
								cout<< id<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t ________________________"<<endl;
								cout<<"\t\t\t\t|Number of Cabin :       |"<<endl;
								cout<<"\t\t\t\t|________________________|";
								cout<<"\t\t";
								cout<<c<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t ________________________"<<endl;
								cout<<"\t\t\t\t|Number of passengers:   |"<<endl;
								cout<<"\t\t\t\t|________________________|";
								cout<<"\t\t";
								cout<<p<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t _____________"<<endl;
								cout<<"\t\t\t\t|Cabin Type:  |"<<endl;
								cout<<"\t\t\t\t|_____________|";
								cout<<"\t\t";
								cout<<ct<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t ______________"<<endl;
								cout<<"\t\t\t\t|Ammount paid: |"<<endl;
								cout<<"\t\t\t\t|______________|";
								cout<<"\t\t";
								cout<<tp<<endl<<endl<<endl;
								goto check_pass;
								break;
							}
							else
							{
								cout<<"\t\t\t\t ________________________________"<<endl;
								cout<<"\t\t\t\t|This booking does not exsists.  |"<<endl;
								cout<<"\t\t\t\t|________________________________|"<<endl;
								goto check_pass;
								break;
							}
							bookinging.close();
						}
					}
				
					else if(opt == 2)
					{
						int count = 0;
						// Passengers details
						cout<<endl<<endl<<endl;
						cout<<"\t\t\t\t _______________________"<<endl;
						cout<<"\t\t\t\t|Passenger details are: |"<<endl;
						cout<<"\t\t\t\t|_______________________|"<<endl;
						int pid_,pid,ap;
						string pn,g,n,mail;
						ifstream passengering;
					
						passengering.open("passenger.txt");
						cout<<"\t\t\t\t _______________________________________"<<endl;
						cout<<"\t\t\t\t|Enter the Passenger ID to check data:  |"<<endl;
						cout<<"\t\t\t\t|_______________________________________|";
						cout<<"\t\t";
						cin>>pid_;
						
						while(passengering.eof() == 0)
						{
							passengering>>pid>>pn>>g>>n>>ap>>mail;
							if(pid==pid_)
							{
								count = 1;
								cout<<"\t\t\t\t _________"<<endl;
								cout<<"\t\t\t\t|ID:      |"<<endl;
								cout<<"\t\t\t\t|_________|";
								cout<<"\t\t";
								cout<<pid<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t ______"<<endl;
								cout<<"\t\t\t\t|Name: |"<<endl;
								cout<<"\t\t\t\t|______|";
								cout<<"\t\t";
								cout<<pn<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t _________"<<endl;
								cout<<"\t\t\t\t|Gender:  |"<<endl;
								cout<<"\t\t\t\t|_________|";
								cout<<"\t\t";
								cout<<g<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t ______________"<<endl;
								cout<<"\t\t\t\t|Nationallity: |"<<endl;
								cout<<"\t\t\t\t|______________|";
								cout<<"\t\t";
								cout<<n<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t ____"<<endl;
								cout<<"\t\t\t\t|Age:|"<<endl;
								cout<<"\t\t\t\t|____|";
								cout<<"\t\t";
								cout<<ap<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t ________"<<endl;
								cout<<"\t\t\t\t|G-Mail: |"<<endl;
								cout<<"\t\t\t\t|________|";
								cout<<"\t\t";
								cout<<mail<<endl<<endl<<endl;
								goto check_pass;
								break;
							}
							else
							{
								cout<<"\t\t\t\t __________________________________"<<endl;
								cout<<"\t\t\t\t|This Passenger does not exsists.  |"<<endl;
								cout<<"\t\t\t\t|__________________________________|"<<endl;
								goto check_pass;
								break;
							}
							passengering.close();
						}
					}
					else
					{
						cout<<"\t\t\t\t ___________"<<endl;
						cout<<"\t\t\t\t|  Exits    |"<<endl;
						cout<<"\t\t\t\t|___________|"<<endl;
					}
				
						cout<<"\t _______________________________________________________"<<endl;
						cout<<"\t|If you exit check officer press '3' else your choice.  |"<<endl;
						cout<<"\t|_______________________________________________________|"<<endl;
						goto check;
				}
				else if(choose == 2)
				{
					int opt;
					check_cargo:
					cout<<endl<<endl<<endl;
					cout<<"\t _______________________________"<<endl;
					cout<<"\t|Enter which details you see :  |" <<endl;
					cout<<"\t|_______________________________|"<<endl;
					cout<<"\t|1. Booking details.            |"<<endl;
					cout<<"\t|2. Insurance  details.         |" <<endl;
					cout<<"\t|3. Exit                        |"<<endl;
					cout<<"\t|_______________________________|";
					cout<<"\t\t";
					cin>>opt;
					
					if(opt == 1)
					{
						int count = 0;
						//Booking details
						cout<<endl<<endl<<endl;
						cout<<"\t\t\t\t\t\t _____________________"<<endl;
						cout<<"\t\t\t\t\t\t|Booking details are: |"<<endl;
						cout<<"\t\t\t\t\t\t|_____________________|"<<endl;
						int ms,noc,price,id,nocon,id_;
						string n;
						double w,l,width;
						ifstream cargo_bookinging;
						cargo_bookinging.open("cargo_booking.txt");
						cout<<endl<<endl<<endl;
						cout<<"\t\t\t\t _____________________________________"<<endl;
						cout<<"\t\t\t\t|Enter the Booking ID to check data:  |"<<endl;
						cout<<"\t\t\t\t|_____________________________________|";
						cout<<"\t\t";
						cin>>id_;
						
						while(cargo_bookinging.eof() == 0)
						{
							cargo_bookinging>>id>>ms>>n>>w>>width>>l>>noc>>price>>nocon;
							if(id==id_)
							{
								count = 1;
								cout<<"\t\t\t\t _________"<<endl;
								cout<<"\t\t\t\t|ID:      |"<<endl;
								cout<<"\t\t\t\t|_________|";
								cout<<"\t\t";
								cout<< id<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t _________________"<<endl;
								cout<<"\t\t\t\t|Name of product: |"<<endl;
								cout<<"\t\t\t\t|_________________|";
								cout<<"\t\t";
								cout<<n<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t ___________________"<<endl;
								cout<<"\t\t\t\t|Weight of product: |"<<endl;
								cout<<"\t\t\t\t|___________________|";
								cout<<"\t\t";
								cout<<w<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t __________________"<<endl;
								cout<<"\t\t\t\t|Width of product: |"<<endl;
								cout<<"\t\t\t\t|__________________|";
								cout<<"\t\t";
								cout<<width<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t ___________________"<<endl;
								cout<<"\t\t\t\t|length of product: |"<<endl;
								cout<<"\t\t\t\t|___________________|";
								cout<<"\t\t";
								cout<<l<<endl;
								
								cout<<"\t\t\t\t ___________________"<<endl;
								cout<<"\t\t\t\t|Number of product: |"<<endl;
								cout<<"\t\t\t\t|___________________|";
								cout<<"\t\t";
								cout<<noc<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t _________________"<<endl;
								cout<<"\t\t\t\t|Price Submitted: |"<<endl;
								cout<<"\t\t\t\t|_________________|";
								cout<<"\t\t";
								cout<<price<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t ________________________________"<<endl;
								cout<<"\t\t\t\t|Number of containers allocated: |"<<endl;
								cout<<"\t\t\t\t|________________________________|";
								cout<<"\t\t";
								cout<<nocon<<endl<<endl<<endl;
								goto check_cargo;
								break;
							}
							else
							{
								cout<<"\t\t\t\t _____________________________________"<<endl;
								cout<<"\t\t\t\t|This cargo booking does not exsists. |"<<endl;
								cout<<"\t\t\t\t|_____________________________________|"<<endl;
								goto check_cargo;
								break;
							}
							cargo_bookinging.close();
						}
					}
					
					else if(opt ==2)
					{
						int count = 0;
						//Insurrance details
						cout<<endl<<endl<<endl;
						cout<<"\t\t\t\t\t\t _______________________"<<endl;
						cout<<"\t\t\t\t\t\t|Insurance details are: |"<<endl;
						cout<<"\t\t\t\t\t\t|_______________________|"<<endl;
						int t,insurancePrice,insuranceID,insuranceID_;
						string name;
						ifstream insuranceing;
						insuranceing.open("insurance.txt");
						cout<<"\t\t\t\t _______________________________________"<<endl;
						cout<<"\t\t\t\t|Enter the Insurance ID to check data:  |"<<endl;
						cout<<"\t\t\t\t|_______________________________________|";
						cout<<"\t\t";
						cin>>insuranceID_;
						
						while(insuranceing.eof() == 0)
						{
							insuranceing>>insuranceID>>name>>t>>insurancePrice;
							if(insuranceID==insuranceID_)
							{
								count = 1;
								cout<<"\t\t\t\t ________"<<endl;
								cout<<"\t\t\t\t|ID:     |"<<endl;
								cout<<"\t\t\t\t|________|";
								cout<<"\t\t";
								cout<< insuranceID<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t ____________________"<<endl;
								cout<<"\t\t\t\t|Name of Applicant:  |"<<endl;
								cout<<"\t\t\t\t|____________________|";
								cout<<"\t\t";
								cout<<name<<endl<<endl<<endl;
								
								cout<<"\t\t\t\t ____________________________"<<endl;
								cout<<"\t\t\t\t|Insurance Price Submitted:  |"<<endl;
								cout<<"\t\t\t\t|____________________________|";
								cout<<"\t\t";
								cout<<insurancePrice<<endl<<endl<<endl;
								goto check_cargo;
								break;
							}
							else
							{
								cout<<"\t\t\t\t _______________________________________"<<endl;
								cout<<"\t\t\t\t|This cargo Insurance does not exsists. |"<<endl;
								cout<<"\t\t\t\t|_______________________________________|"<<endl;
								goto check_cargo;
								break;
							}
							insuranceing.close();
						}
					}
					else
					{
						cout<<"\t\t\t\t ___________"<<endl;
						cout<<"\t\t\t\t|  Exits    |"<<endl;
						cout<<"\t\t\t\t|___________|"<<endl;
					}
				cout<<"\t _______________________________________________________"<<endl;
				cout<<"\t|If you exit check officer press '3' else your choice.  |"<<endl;
				cout<<"\t|_______________________________________________________|"<<endl;
				goto check;
				}
				
				else
					{
						cout<<"\t\t\t\t _____________________________"<<endl;
						cout<<"\t\t\t\t|  Exits the Check Officer    |"<<endl;
						cout<<"\t\t\t\t|_____________________________|"<<endl;
					}
			}
			else if(officers == 2)
			{
				int choose;
				
				cout<<endl<<endl;
				cout<<"\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
				cout<<"\t\t\t\t\t\t&   Update & Delete Information of passengers and Cargos.    &"<<endl;
				cout<<"\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
				
				update_delete:
					
				cout<<endl;
				cout<<"Enter the choice whether you check: "<<endl;
				cout<<"1. Passengers."<<endl;
				cout<<"2. Cargos."<<endl;
				cout<<"3. Exit"<<endl;
				cin>>choose;
				
				if(choose == 1)
				{
					regins:
					int reigns;
					cout<<endl<<endl;
					cout<<"Enter the choice whether you check: "<<endl;
					cout<<"1. Update."<<endl;
					cout<<"2. Delete."<<endl;
					cin>>reigns;
					if(reigns == 1)
					{
						rollinss:
						int rollins;
						cout<<endl<<endl;
						cout<<"Enter the choice whether you check: "<<endl;
						cout<<"1. Booking Update."<<endl;
						cout<<"2. Passenger Update."<<endl;
						cin>>rollins;
						
						if(rollins == 1)
						{
							int id_;
       	 					int count = 0;
        					char choice;
        					double ct;
							int c,p,tp,id;

        					cout << "Enter the id you want to update data: ";
        					cin >> id_;
        					
        					ofstream temp("temp.txt");
        					ifstream bookinging("Booking.txt");
        					
        					bookinging>>id>>c>>p>>ct>>tp;
        					while (!bookinging.eof())
      						{
      							if (id_ == id)
					            {
					                count = 1;
					
					                cout << "\nDo you want to number of cabins? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new number of cabins: ";
					                    cin >> c;
					                }
					
					                cout << "\nDo you want to update number of passengers? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new number of passengers: ";
					                    cin >> p;
					                }
									
									cout << "\nDo you want to update cabin type? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new cabin type: ";
					                    cin >> ct;
					                }
					                
					                temp << id << " " << c << " " << p << " " << ct << " " << tp<< endl;
					            }
					            
					            else
					            {
					                temp << id << " " << c << " " << p << " " << ct << " " << tp<< endl;
					            }
								bookinging>>id>>c>>p>>ct>>tp;
							}
							if (count == 0)
					        {
					            cout << "ID not found" << endl;
					        }
					
					        bookinging.close();
					        temp.close();
					
					        remove("Booking.txt");
					        rename("temp.txt", "Booking.txt");
						}
						
						else if(rollins == 2)
						{
       	 					int count = 0;
        					char choice;
        					int pid_,pid,ap;
							string pn,g,n,mail;

        					cout << "Enter the id you want to update data: ";
        					cin >> pid_;
        					
        					ofstream temp("temp.txt");
        					ifstream passengering("passenger.txt");
        					
        					passengering>>pid>>pn>>g>>n>>ap>>mail;
        					while (!passengering.eof())
      						{
      							if (pid_ == pid)
					            {
					                count = 1;
					
					                cout << "\nDo you want to name of passenger? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new name of passenger: ";
					                    cin >> pn;
					                }
					
					                cout << "\nDo you want to update gender of passengers? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new gender of passengers: ";
					                    cin >> g;
					                }
									
									cout << "\nDo you want to update nationality of passengers? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new nationality of passengers: ";
					                    cin >>  n;
					                }
					                
					                cout << "\nDo you want to update age of passengers? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new age of passengers: ";
					                    cin >> ap;
					                }
					                
					                cout << "\nDo you want to update Mail of passengers? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new Mail of passengers: ";
					                    cin >> mail;
					                }
					                
					                temp << pid << " " << pn << " " << g << " " << n << " " << ap<< " " << mail << endl;
					            }
					            
					            else
					            {
					                temp << pid << " " << pn << " " << g << " " << n << " " << ap<< " " << mail << endl;
					            }
								passengering>>pid>>pn>>g>>n>>ap>>mail;
							}
							if (count == 0)
					        {
					            cout << "ID not found" << endl;
					        }
					
					        passengering.close();
					        temp.close();
					
					        remove("passenger.txt");
					        rename("temp.txt", "passenger.txt");
						}
						else
						{
							goto rollinss;
						}
						
					}
					else if(reigns == 2)
					{
						braywhaytss:
						int braywhayt;
						cout<<endl<<endl;
						cout<<"Enter the choice whether you check: "<<endl;
						cout<<"1. Booking Delete."<<endl;
						cout<<"2. Passenger Delete."<<endl;
						cin>>braywhayt;
						
						if(braywhayt == 1)
						{
							int id_;
					        int count = 0;
					        double ct;
							int c,p,tp,id;
					
					        cout << "Enter id to delete booking: ";
					        cin >> id_;
					
					        ofstream temp("temp.txt");
	        				ifstream bookinging("Booking.txt");
					
					        bookinging>>id>>c>>p>>ct>>tp;
					
					        while (!bookinging.eof())
					        {
					            if (id_ != id)
					            {
					                temp << id << " " << c << " " << p << " " << ct << " " << tp<< endl;
					            }
					            else
					            {
					                count = 1;
					            }
					
					            bookinging>>id>>c>>p>>ct>>tp;
					        }
					
					        if (count == 0)
					        {
					            cout << "ID not found" << endl;
					        }
					        else
					        {
					            cout << "booking with ID " << id_ << " deleted successfully." << endl;
					        }
					
					        bookinging.close();
					        temp.close();
					
					        remove("Booking.txt");
						    rename("temp.txt", "Booking.txt");
						}
						else if(braywhayt == 2)
						{
					        int count = 0;
					        int pid_,pid,ap;
							string pn,g,n,mail;
					
					        cout << "Enter id to delete passengers: ";
					        cin >> pid_;
					
					        ofstream temp("temp.txt");
        					ifstream passengering("passenger.txt");
        					
        					passengering>>pid>>pn>>g>>n>>ap>>mail;
					
					        while (!passengering.eof())
					        {
					            if (pid_ != pid)
					            {
					                temp << pid << " " << pn << " " << g << " " << n << " " << ap<< " " << mail << endl;
					            }
					            else
					            {
					                count = 1;
					            }
					
					            passengering>>pid>>pn>>g>>n>>ap>>mail;
					        }
					
					        if (count == 0)
					        {
					            cout << "ID not found" << endl;
					        }
					        else
					        {
					            cout << "Passengers with ID " << pid_ << " deleted successfully." << endl;
					        }
					
					        passengering.close();
					        temp.close();
					
					        remove("passenger.txt");
					        rename("temp.txt", "passenger.txt");
							
						}
						else
						{
							goto braywhaytss;
						}
					}
					goto update_delete;
				}
				else if(choose == 2)
				{
					reignsing:
					int reigns;
					cout<<endl<<endl;
					cout<<"Enter the choice whether you check: "<<endl;
					cout<<"1. Update."<<endl;
					cout<<"2. Delete."<<endl;
					cin>>reigns;
					
					if(reigns == 1)
					{
						int rollins;
						cout<<endl<<endl;
						cout<<"Enter the choice whether you check: "<<endl;
						cout<<"1. Booking Update."<<endl;
						cout<<"2. Insurance Update."<<endl;
						cin>>rollins;
						
						if(rollins == 1)
						{
       	 					int count = 0;
        					char choice;
        					int ms,noc,price,id,nocon,id_;
							string n;
							double w,l,width;

        					cout << "Enter the id you want to update data: ";
        					cin >> id_;
        					
        					ofstream temp("temp.txt");
        					ifstream cargo_bookinging("cargo_booking.txt");
        					
        					cargo_bookinging>>id>>ms>>n>>w>>width>>l>>noc>>price>>nocon;
        					while (!cargo_bookinging.eof())
      						{
      							if (id_ == id)
					            {
					                count = 1;
					
					                cout << "\nDo you want to name of product? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new name of product: ";
					                    cin >> n;
					                }
					
					                cout << "\nDo you want to update weight of product? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new weight of product: ";
					                    cin >> w;
					                }
									
									cout << "\nDo you want to update width of product? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new width of product: ";
					                    cin >> width;
					                }
					                
					                cout << "\nDo you want to update length of product? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new length of product: ";
					                    cin >> l;
					                }
					                
					                cout << "\nDo you want to update number of cartons of product? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new number of cartons of product: ";
					                    cin >> noc;
					                }
									
									cout << "\nDo you want to update price of product? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new price of product: ";
					                    cin >> price;
					                }					                
					                temp << id << " " << ms << " " << n << " " << w << " " << width<<  " " << l << " " << noc << " " << price << " " << nocon <<endl;
					            }
					            
					            else
					            {
					                temp << id << " " << ms << " " << n << " " << w << " " << width<<  " " << l << " " << noc << " " << price << " " << nocon <<endl;
					            }
								cargo_bookinging>>id>>ms>>n>>w>>width>>l>>noc>>price>>nocon;
							}
							if (count == 0)
					        {
					            cout << "ID not found" << endl;
					        }
					
					        cargo_bookinging.close();
					        temp.close();
					
					        remove("cargo_booking.txt");
					        rename("temp.txt", "cargo_booking.txt");
						}
						
						else if(rollins == 2)	
						{
							int count = 0;
        					char choice;
        					int t,insurancePrice,insuranceID,insuranceID_;
							string name;

        					cout << "Enter the id you want to update data: ";
        					cin >> insuranceID_;
        					
        					ofstream temp("temp.txt");
        					ifstream insuranceing("insurance.txt");
        					
        					insuranceing>>insuranceID>>name>>t>>insurancePrice;
        					while (!insuranceing.eof())
      						{
      							if (insuranceID_ == insuranceID)
					            {
					                count = 1;
					
					                cout << "\nDo you want to update  name of insurance applicable? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new name of insurance applicable: ";
					                    cin >> name;
					                }
				
									cout << "\nDo you want to update price of insurance? (Y/N)";
					                cin >> choice;
					                if (choice == 'y' || choice == 'Y')
					                {
					                    cout << "\nEnter new price of insurance: ";
					                    cin >> insurancePrice;
					                }					                
					                temp << insuranceID << " " << name << " " << insurancePrice <<endl;
					            }
					            
					            else
					            {
					                temp << insuranceID << " " << name << " " << insurancePrice <<endl;
					            }
							insuranceing>>insuranceID>>name>>t>>insurancePrice;
							}
							if (count == 0)
					        {
					            cout << "ID not found" << endl;
					        }
					
					        insuranceing.close();
					        temp.close();
					
					        remove("insurance.txt");
					        rename("temp.txt", "insurance.txt");
						}
						else
						{
							goto reignsing;
						}
					}
					else if(reigns == 2)
					{
						int braywhayt;
						cout<<endl<<endl;
						cout<<"Enter the choice whether you check: "<<endl;
						cout<<"1. Booking Delete."<<endl;
						cout<<"2. Passenger Delete."<<endl;
						cin>>braywhayt;
						
						if(braywhayt == 1)
						{
					        int count = 0;
					        int ms,noc,price,id,nocon,id_;
							string n;
							double w,l,width;
					
					        cout << "Enter id to delete booking: ";
					        cin >> id_;
					
					        ofstream temp("temp.txt");
        					ifstream cargo_bookinging("cargo_booking.txt");
        					
        					cargo_bookinging>>id>>ms>>n>>w>>width>>l>>noc>>price>>nocon;
					
					        while (!cargo_bookinging.eof())
					        {
					            if (id_ != id)
					            {
					                temp << id << " " << ms << " " << n << " " << w << " " << width<<  " " << l << " " << noc << " " << price << " " << nocon <<endl;
					            }
					            else
					            {
					                count = 1;
					            }
					
					            cargo_bookinging>>id>>ms>>n>>w>>width>>l>>noc>>price>>nocon;
					        }
					
					        if (count == 0)
					        {
					            cout << "ID not found" << endl;
					        }
					        else
					        {
					            cout << "booking with ID " << id_ << " deleted successfully." << endl;
					        }
					
					        cargo_bookinging.close();
					        temp.close();
					
					        remove("cargo_booking.txt");
					        rename("temp.txt", "cargo_booking.txt");
					    }
					        
						else if(braywhayt == 2)
						{
					        int count = 0;
					        int t,insurancePrice,insuranceID,insuranceID_;
							string name;

					        cout << "Enter id to delete Insurance: ";
					        cin >> insuranceID_;
					
					        ofstream temp("temp.txt");
        					ifstream insuranceing("insurance.txt");
        					
        					insuranceing>>insuranceID>>name>>t>>insurancePrice;
					
					        while (!insuranceing.eof())
					        {
					            if (insuranceID_ != insuranceID)
					            {
					                 temp << insuranceID << " " << name << " " << insurancePrice <<endl;
					            }
					            else
					            {
					                count = 1;
					            }
					
					            insuranceing>>insuranceID>>name>>t>>insurancePrice;
					        }
					
					        if (count == 0)
					        {
					            cout << "ID not found" << endl;
					        }
					        else
					        {
					            cout << "Insurance with ID " << insuranceID_ << " deleted successfully." << endl;
					        }
					
					        insuranceing.close();
					        temp.close();
					
					        remove("insurance.txt");
					        rename("temp.txt", "insurance.txt");
					    }
					}
					goto update_delete;
				}
				else
				{
					cout<<endl<<endl;
					cout<<"\t\t ______________________________________"<<endl;
					cout<<"\t\t|Exiting the update & delete officer   |"<<endl;
					cout<<"\t\t|______________________________________|"<<endl;
				}
					
			}
		    else if (officers == 3) 
			{
				
				cout<<endl<<endl;
				cout<<"\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
				cout<<"\t\t\t\t\t\t&      Finance Information of passengers and Cargos.         &"<<endl;
				cout<<"\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
				
				///////////////////////////////////////////////////////////////////////////////////////////////
		        double ct;
		        int c, p, tp, id;
		        int total_pricess = 0; // Initialize to 0
		         ifstream bookinging("Booking.txt");
		            
		        if (!bookinging.is_open()) {
		               cerr << "Error opening Booking.txt" << endl;
		        }
		            
		        while (bookinging >> id >> c >> p >> ct >> tp) {
		            total_pricess += tp;
		        }
		            
		        bookinging.close();
				cout<<endl<<endl;
		        cout << "\t\tTotal price of passengers Bookings: " << total_pricess << endl;
		        cout<<endl<<endl<<endl<<endl;
		    
		    	//////////////////////////////////////////////////////////////////////////////////////////////////
		        int ms, noc, price, ids, nocon;
		        double w, l, width;
		        string n;
		        int total_price = 0; // Initialize to 0
		        ifstream cargo_bookinging("cargo_booking.txt");
		            
		        if (!cargo_bookinging.is_open()) {
		            cerr << "Error opening cargo_booking.txt" << endl;
		        }
		            
		        while (cargo_bookinging >> ids >> ms >> n >> w >> width >> l >> noc >> price >> nocon) {
		            total_price += price;
		        }
		            
		        cargo_bookinging.close();
		        
		        cout << "\t\tTotal price of cargo booking: " << total_price << endl;
		        cout<<endl<<endl<<endl<<endl;
		        
		        ////////////////////////////////////////////////////////////////////////////////////
		        int t,insurancePrice,insuranceID,insuranceID_;
				string name;
				ifstream insuranceing;
				int total_prices = 0; // Initialize to 0
				insuranceing.open("insurance.txt");
				
				if (!insuranceing.is_open()) {
		               cerr << "Error opening Booking.txt" << endl;
		        }
		        
		        while (insuranceing>>insuranceID>>name>>t>>insurancePrice) {
		            total_prices += insurancePrice;
		        }
		            
		        cargo_bookinging.close();
		        cout << "\t\tTotal price of insurance : " << total_prices << endl;
		        cout<<endl<<endl<<endl<<endl;
		        ///////////////////////////////////////////////////////////////////////////////////
		    	
		    	e1.display();
		    
		    	cout<<endl<<endl;
		    	cout<<"The following  operation performed by finance officer also."<<endl;
		    	cout<<"1.  Get total amount calculated."<<endl;
		    	cout<<"2.  Get total amount after paying insurance amount & paying salary."<<endl;
		    	
		    	cout<<endl<<endl<<endl<<endl;
		    	int total_amount = (total_pricess + total_price + total_prices);
		    	cout<<"1.   Total Amount is =  "<< total_amount<<endl;
		    	
		    	
				cout<<endl<<endl<<endl<<endl;
		    	int total_revenue = ((total_pricess + total_price )-(e1.get_salary() + total_prices));
		   		cout<<endl<<"2.  Get total amount after paying insurance amount & paying salary.=  "<<total_revenue <<endl;
		   		cout<<endl;
		    		if(total_revenue>0)
		    		{
		    			cout<<endl;
		    			cout<<"Congratulations !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
		    			cout<<"Your cruise earned : "<<total_revenue<<"  revenue."<<endl;
		    			cout<<endl<<endl;
					}
					else
					{
						cout<<endl;
						cout<<"OOPs !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
						cout<<"Your cruise is in loss by : "<<total_revenue<<" amount"<<endl;
						cout<<endl;
					}
				
				ofstream store;
		    	store.open("store.txt",ios::app);
		    	store << total_amount << "  " << total_revenue << endl;
		    	store.close();
		    	
		    	cout<<endl<<endl;
				cout<<"\t\t ______________________________________"<<endl;
				cout<<"\t\t|Exiting the update & delete officer   |"<<endl;
				cout<<"\t\t|______________________________________|"<<endl;
		    }
			else
			{	
				goto management;
			}
		}
		
};
//Login
class Login {
private:
    string username;
    string password;
    int type;

public:
	Booking b1;
	Passenger p1;
	Cabintype c1;
	ShipSearch search;
	// for cargo
	Cargo_login cl1;
	Freight freight;
	CargoInsurance ci1;
	Menusss menuObj;
	
	
    void setusername(string i){
        username = i;
    }
    void setpass(string g){
        password = g;
    }

    string getuser(){
        return username;
    }

    string getpas(){
        return password;
    }
    
    

    void login() {
    	ahmad:
        string inputUsername, inputPassword;
        bool loginSuccess = false;

        // Ask user for login credentials
        cout<<"\t ________________"<<endl;
        cout<<"\t|Enter username: |"<<endl;
        cout<<"\t|________________|";  
        cout<<"\t\t";
        cin >> inputUsername;
        cout<<endl;
        
        cout<<"\t ________________"<<endl;
        cout<<"\t|Enter password: |"<<endl;
        cout<<"\t|________________|";  
        cout<<"\t\t";
        cin >> inputPassword;

        // Open the login file
        ifstream loginFile("login.txt");
        if (!loginFile) {
            cout << "Unable to open file login.txt";
        }

        // Read file and verify credentials
        while (loginFile >> username >> password >> type) {
            if (username == inputUsername && password == inputPassword) {
                loginSuccess = true;
                break;
            }
        }
        loginFile.close();

        // Open the respective menu based on type if login is successful
        if (loginSuccess) {
            switch (type) {
                case 1:
                    menuObj.Passengers();
                    break;
                case 2:
                    menuObj.Cargo();
                    break;
                case 3:
                    menuObj.Management();
                    break;
                default:
                	cout<<"\t _____________"<<endl;
                    cout<<"\t|Invalid type |"<<endl;
                    cout<<"\t|_____________|"<<endl;
                    break;
            }
        } else {
        	cout<<endl<<endl;
        	cout<<" _________________________________________________________________"<<endl;
            cout<<"|Invalid username or password. Please enter valid name or password|"<<endl;
            cout<<"|_________________________________________________________________|"<<endl;
            goto ahmad;
        }
    }
	void registerUser() {
        string newUsername, newPassword;
        int newType;

        cout<<" ________________"<<endl;
        cout<<"|Enter username: |"<<endl;
        cout<<"|________________|";  
        cout<<"\t\t";
        cin >> newUsername;
        cout<<endl;
        cout<<" ________________"<<endl;
        cout<<"|Enter password: |"<<endl;
        cout<<"|________________|";  
        cout<<"\t\t";
        cin >> newPassword;
        cout<<" _____________________________________________________________"<<endl;
        cout<<"|Enter type (1 for Passenger, 2 for Cargo, 3 for Management): |"<<endl;
        cout<<"|_____________________________________________________________|";
        cout<<"\t\t";
        cin>>newType;

        // Append new user details to the login file
        ofstream loginFile("login.txt", ios::app);
        if (!loginFile) {
            cerr << "Unable to open file login.txt";
            exit(1);   // Call system to stop
        }

        loginFile << newUsername << " " << newPassword << " " << newType << endl;
        loginFile.close();
        cout<<" _____________________________"<<endl;
        cout<<"|Registration successful!.....|"<<endl;
        cout<<"|_____________________________|"<<endl;
    }
};


int main() {
	srand(time(0));
	cout << "\t\t" << endl;
    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t\t\t\t@---------------------------------------------------------------------------------@" << endl;
    cout << "\t\t\t\t\t@---------------------------------------------------------------------------------@" << endl;
    cout << "\t\t\t\t\t@-------------   WELCOME TO SYMPHONY CRUISE MANAGEMENT SYSTEM   ------------------@" << endl;
    cout << "\t\t\t\t\t@---------------------------------------------------------------------------------@" << endl;
    cout << "\t\t\t\t\t@---------------------------------------------------------------------------------@" << endl;
    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t" << endl;
    cout << endl;
    cout << endl;

	rayyan:
    Login user;
    int choice;
    
    cout<<endl<<endl;
    time_t now = time(0);
    cout<<"\t __________________"<<endl;
    cout<<"\t| Date & Time is : |"<<endl;
    cout<<"\t|__________________|";
    cout<<"\t\t";
    cout<<ctime(&now);
    
    cout << "\t ___________________________________"<<endl;
    cout << "\t|Welcome! Please choose an option:  |"<<endl;
    cout << "\t|___________________________________|"<<endl;
    cout<<endl;
    cout<<"\t ___________"<<endl;
    cout<<"\t|1. Register|"<<endl;
    cout<<"\t|___________|"<<endl;
    cout<<"\t|2. Login   |"<<endl;
    cout<<"\t|___________|"<<endl;
    cout<<endl<<endl;
    
    cout<<"\t ___________________"<<endl;
    cout<<"\t|Enter your choice: |"<<endl;
    cout<<"\t|___________________|";
    cout<<"\t\t";
    cin >> choice;

    switch (choice) {
        case 1:
            user.registerUser();
            goto rayyan;
            break;
        case 2:
            user.login();
            break;
        default:
        	cout<<"\t\t\t\t ________________"<<endl;
            cout<<"\t\t\t\t|Invalid choice  |"<<endl;
            cout<<"\t\t\t\t|________________|"<<endl;
            break;
    }

}

