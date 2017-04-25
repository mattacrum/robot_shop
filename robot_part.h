#ifndef _ROBOT_PART
#define _ROBOT_PART 2017
#include <string>
#include <iostream>
using namespace std;

class Robot_part {
  public:
    Robot_part(string description, double cost, int model_number, string name)
        : _description{description}, _cost{cost}, _model_number{model_number}, _name{name} { }
    string name() const {return _name;}
    int model_number() const {return _model_number;}
    double cost() const {return _cost;}
    string description() const {return _description;}
    string to_string();
  protected:
    string _name;
    int _model_number;
    double _cost;
    string _description;
};

class Head : public Robot_part {
  public:
    Head(string name,
         int model_number,
         double cost,
         string description,
         double power)
       : Robot_part(description, cost, model_number, name),
         _power{power} { }
    double power() const {return _power;}
  private:
    double _power;
};

ostream& operator<< (ostream& ost, const Head& head) {
  ost << "Head " << head.name() << " (model " << head.model_number() << ") "
      << "costs $" << head.cost()
      << " and uses " << head.power() << " watts" << endl;
  ost << head.description();
  return ost;
}

class Locomotor : public Robot_part {
  public:
    Locomotor(string name,
              int model_number,
              double cost,
              string description,
              double max_power)
            : Robot_part(description, cost, model_number, name),
              _max_power{max_power} { }
    double max_power() const {return _max_power;}
  private:
    double _max_power;
};

ostream& operator<< (ostream& ost, const Locomotor& locomotor) {
  ost << "Locomotor " << locomotor.name() << " (model " << locomotor.model_number() << ") "
      << "costs $" << locomotor.cost()
      << " and uses up to " << locomotor.max_power() << " watts" << endl;
  ost << locomotor.description();
  return ost;
}

class Arm : public Robot_part {
  public:
    Arm(string name,
        int model_number,
        double cost,
        string description,
        double max_power)
      : Robot_part(description, cost, model_number, name),
        _max_power{max_power} { }
    double max_power() const {return _max_power;}
  private:
    double _max_power;
};

ostream& operator<< (ostream& ost, const Arm& arm) {
  ost << "Arm " << arm.name() << " (model " << arm.model_number() << ") "
      << "costs $" << arm.cost()
      << " and uses up to " << arm.max_power() << " watts" << endl;
  ost << arm.description();
  return ost;
}

class Torso : public Robot_part {
  public:
    Torso(string name,
          int model_number,
          double cost,
          string description,
          int max_arms,
          int battery_compartments)
        : Robot_part(description, cost, model_number, name),
          _max_arms{max_arms},
          _battery_compartments{battery_compartments} { }
    int max_arms() const {return _max_arms;}
    int battery_compartments() const {return _battery_compartments;}
  private:
    int _max_arms;
    int _battery_compartments;
};

ostream& operator<< (ostream& ost, const Torso& torso) {
  ost << "Torso " << torso.name() << " (model " << torso.model_number() << ") "
      << "costs $" << torso.cost()
      << " and can hold " << torso.max_arms() << " arms and "
      << torso.battery_compartments() << " batteries" << endl;
  ost << torso.description();
  return ost;
}

class Battery : public Robot_part {
  public:
    Battery(string name,
            int model_number,
            double cost,
            string description,
            double max_energy,
            double power_available)
          : Robot_part(description, cost, model_number, name),
            _max_energy{max_energy},
            _power_available{power_available} { }
    double max_energy() const {return _max_energy;}
    double power_available() const {return _power_available;}
  private:
    double _max_energy;
    double _power_available;
};

ostream& operator<< (ostream& ost, const Battery& battery) {
  ost << "Battery " << battery.name() << " (model " << battery.model_number() << ") "
      << "costs $" << battery.cost()
      << ", driving " << battery.power_available() << " watts "
      << "and containing " << battery.max_energy() << " kWh"  << endl;
  ost << battery.description();
  return ost;
}

#endif
