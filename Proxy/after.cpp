#include<iostream>
//Protection Proxy
class ICar {
public:
	virtual void DriveCar() = 0;
};

class Car : public ICar {
private:
	void DriveCar(){
		std::cout << "El carro ha sido manejado!";
	}
};

class ProxyCar : public ICar {
private:
	ICar* realCar;
	int driverAge;
	
public:
	ProxyCar(int someDriverAge){
		this->driverAge = someDriverAge;
		this->realCar = new Car;
	}
	
	void DriveCar(){  
		if (driverAge >= 18)
			realCar->DriveCar();
		else
			std::cout << "Lo siento, usted es muy joven para manejar.";
	}
	
};

int main()
{
	int i;
	std::cout<<"Ingrese su edad: " << std::endl;
	std::cin >> i;
	ICar* car = new ProxyCar(i);
	car->DriveCar();
	
	delete car;
}
