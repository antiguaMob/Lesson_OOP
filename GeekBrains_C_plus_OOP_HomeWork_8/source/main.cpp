#include"main.h"

//*******************************************************************************************************************************************
// Создать класс Car (автомобиль) с полями company (компания) и model (модель). Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
// От этих классов наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. Создать объекты 
// для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз смерти».
//*******************************************************************************************************************************************

using namespace std;

//*******************************************************************************************************************************************
class  Car {
protected:
	string company;
	string model;
   
public:
	//Car() {
	//	company = "";
	//	model = "";
	//}
	Car (string name = "company", string nameID = "model" ): company(name) , model(nameID) {
		//company = name;
		//model = nameID;
		cout << "Parent constructor" << endl;
    }
    ~Car(){
		cout << "Parent distructor" << endl;
    }
     virtual string getCompany() const {
		// cout << company << endl << endl;
		return company;
	}

	virtual string getModel() const {
		//cout << model << endl << endl;
		return model;
	}
	
};
//*******************************************************************************************************************************************
class PassengerCar : virtual public Car {
protected:
	string type;
public:
	PassengerCar(string n , string m, string p) : Car(n, m), type(p) {
		cout << "Passenger Car constructor" << endl << endl;
	}

	~PassengerCar() {
		cout << "Passenger Car distructor" << endl << endl;
	}
	string getType() const {

		return type;
	}
};
//*******************************************************************************************************************************************
class Bus : virtual public Car {
protected:
	int seats;
public:
	Bus (string n, string m, int p) : Car(n, m), seats(p) {
		cout << "Bus constructor" << endl << endl;
	}

	~Bus() {
		cout << "Bus distructor" << endl << endl;
	}
	int getSeats() const {

   	return seats;
   }

};
//*******************************************************************************************************************************************
class  Minivan : public PassengerCar, public Bus {
private:

public:
	Minivan(string n, string m,string t, int p ) : PassengerCar(n, m, t), Bus(n, m, p), Car(n, m) {
		cout << "Minivan constructor" << endl << endl;
	}

	~Minivan() {
		cout << "Minivan distructor " << endl << endl;
	}

};
//*******************************************************************************************************************************************
int main(){

Bus bus("Mercedes"," Integro",45);
PassengerCar car("BMW", "X5 M","jeep");
Minivan van("Volkswagen", "Caravelle", "minivan", 12);

  cout << "My " << bus.getCompany() << " is " << bus.getModel() << " number of  seats "<<bus.getSeats()<< endl;
  cout << "My " << car.getCompany() << " is " << car.getModel() << " type of car "<<car.getType()<< endl;
  cout << "My " << van.getCompany() << " is " << van.getModel() << " type of car " << van.getType() << " number of  seats " << van.getSeats() << endl;

system("pause");
return 0;
}


