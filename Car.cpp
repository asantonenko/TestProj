#include <vector>
#include <string>

class Car
{
  public:

    Car (const std::string& mark, const std::string& number, 
         int fuel, int engineVolume, int speed): 
      m_mark(mark), m_number(number), m_fuel(fuel),
      m_engineVolume (engineVolume), m_speed(speed)
    {}
    
    std::string getNumber() const {return m_number;}
    bool emptyFuel() const {return m_fuel==0;}
    int getFuel() const {return m_fuel;}
    void fuel (int fuel) {m_fuel+=fuel;}
    int getSpeed() const { return m_speed; }
    void setSpeed (int speed)
    {
       if(speed>=0)
         m_speed = speed;
    }
    std::string info()const
    {
       return mark + " " + number + " fuel: " + std::to_string(fuel);
    }

  private:
    std::string m_mark;
    std::string m_number; 
    int m_fuel; 
    int m_engineVolume;
    int m_speed;      
};


class AutoPark
{
  public:
    void addCar (const Car& car);
    bool removeCar (const std::string& number);
    void fuelCar (const std::string& number, int fuel);
    static void carInfo(const Car &car);
    Car* getCar(int distance);
    ~AutoPark()
    {
       for (Car*& car:m_cars)
       {
          delete car;
          car = nullptr;
       }
    }
    static AutoPark* createAutoPark (int count);
  private:
    std::vector<Car*> m_cars;
};

void Car::addCar(const Car& car)
{
   if (car.emptyFuel())
     m_cars.push_back(&car);
   else throw std::invalid_argument("Car is not empty");
}

bool Car::removeCar (const std::string& number)
{
   for (auto & it = storage.begin(); it != storage.end(); ++it) 
      if ((*it)->getNumber() == number)
      {
        storage.erase(it); return true;
      }
   return false; 
}

void Car::fuelCar (const std::string& number, int fuel)
{
   for (Car* car: m_cars)
   {
     if (car->getNumber() == number)
     {
        car->fuel (fuel);
        return;
     } 
   }
   std::cout << "No car found" <<std::endl; // better throw
}

Car* Car::getCar(int distance)
{
   for (Car* car: m_cars)
   {
     if (car->getNumber() == number)
     {
        car->fuel (fuel);
        return;
     } 
   }
   return nullptr;
}

AutoPark* AutoPark::createAutoPark (int count)
{
   AutoPark* park = new AutoPark;
   for (int i=0; i<count; i++)
   {
      Car * car = new Car("Volvo", std::to_string(i+1), 0, 100, 120);
      park.addCar (car);
   }
   return park;
}

//Читать: указатели и ссылки, геттеры и сеттеры