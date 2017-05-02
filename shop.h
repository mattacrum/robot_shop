#ifndef _SHOP_H
#define _SHOP_H 201703
#include <string>
#include <iostream>

using namespace std;

class Robot_Model
{
  private:
    string _name;
    int _model_number;
    Head _head;
    Locomotor _locomotor;
    Torso _torso;
    Battery _battery;
    Arm _arm;
    double _cost;
    string _description;

  public:
    Robot_Model(string name, int model_number, Head head, Locomotor locomotor, Torso torso, Battery battery,
      Arm arm, double cost, string description)
    : _model_number(model_number), _head(head), _locomotor(locomotor), _torso(torso), _battery(battery)
    , _arm(arm), _cost(cost), _description(description) { }


    string to_string();
    string get_description();

    double cost();
    double max_speed();
    double max_battery_life();
    void save(ostream& os);
};

/*istream& operator>> (istream& st, const Robot_Model& model) {
  ist >>  model.name() >> model.model_number() >> model.
      << " and uses " << head.power() << " watts" << endl;
  ost << head.description();
  return ost;
*/
class Customer
{
  private:
    string name;
    int customer_number;
    int phone_number;
    string email_address;
  public:
    void save(ostream& os);
};

class Sales_Associate
{
  private:
    string name;
    int employee_number;
  public:
    void save(ostream& os);
};

class Order
{
  private:
    int _order_number;
    string _date;
    Customer _customer;
    Sales_Associate _associate;
    Robot_Model _model;
    int _status;
  public:
    Order(int order_number, string date, Customer customer
    , Sales_Associate associate, Robot_Model model, int status)
    : _order_number{order_number}, _date{date}, _customer{customer}
    , _associate{associate}, _model{model}, _status{status} { }
  /*  Order(istream& ist)
    {
       ist >> _order_number >> _date >> _customer >> _associate >> _model >> _status;
    }*/
    int order_number() {return _order_number;}
    string date() {return _date;}
    Customer customer() {return _customer;}
    Sales_Associate associate() { return _associate;}
    Robot_Model model() { return _model;}
    int status() { return _status;}
    double robot_cost();
    double extended_price();
    void save(ostream& os);

};


class Shop {
  bool dirty = false;
  public:

    void create_new_robot_part();
    void create_new_robot_model();
    void create_new_customer();
    void create_new_sales_associate();
    void create_new_order();


    string part_to_string(int part_index);
    //string model_to_string(int model_index);

    int number_of_parts();
    string get_part_list();
  //  int number_of_models();
  /*  void create_new_robot_part(istream& is);
    void create_new_robot_model(istream& is);
    void create_new_customer(istream& is);
    void create_new_sales_associate(istream& is);
    void create_new_order(istream& is); */
    void new_shop();
    void open_shop(istream& is);
    void save_shop(ostream& os);
    void load_shop(istream& is);
    bool saved();

  private:
    string type;
    int num_parts,num_battery;
    vector<Order> orders;
    vector<Head> heads;
    vector<Robot_part> parts;
    vector<Robot_Model> models;
    vector<Customer> customers;
    vector<Sales_Associate> associates;
};





#endif
