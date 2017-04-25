#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/fl_ask.H>
#include "robot_part.h"
#include "robot_model.h"
#include "shop.h"
#include "view.h"
#include "controller.h"
#include "utility.h"

using namespace std;

Fl_Window *win;
Fl_Menu_Bar *menubar;

// Robot_Parts

string Robot_part::to_string()
{

  //  string part = name;

  //  return part;
}

// Robot_Model

string Robot_Model::to_string()
{
  //  string model = name;

  //  return model;
}

double Robot_Model::cost()
{
  //  double cost;
    //cost = head.get_cost() + locomotor.get_cost() + torso.get_cost() + battery.get_cost() + arm.get_cost();
    //cost += 0.5 * cost;
  //  return cost;
}



double Robot_Model::max_speed()
{

}

double Robot_Model::max_battery_life()
{

}
// Shop


void Shop::create_head(Head head)
{
  //  type = "Head";
  //  heads.push_back(head);
}

void Shop::create_locomotor(Locomotor locomotor)
{
  //  type = "Locomotor";
  //  locomotors.push_back(locomotor);
}
void Shop::create_torso(Torso torso)
{
  //  type = "Torso";
  //  torsos.push_back(torso);
}
void Shop::create_battery(Battery battery)
{
  //  type = "Battery";
  //  batteries.push_back(battery);
}
void Shop::create_arm(Arm arm)
{
  //  type = "Arm";
  //  arms.push_back(arm);
}


Head Shop::get_head(int part_index)
{
  //return heads[part_index];
}

Locomotor Shop::get_locomotor(int part_index)
{
  //return locomotors[part_index];
}

Torso Shop::get_torso(int part_index)
{
  //return torsos[part_index];
}

Battery Shop::get_battery(int part_index)
{
//  return batteries[part_index];
}

Arm Shop::get_arm(int part_index)
{
  //return arms[part_index];
}


void Shop::create_model(Robot_Model robot)
{
  //  models.push_back(robot);
}


string Shop::part_to_string(string type, int part_index)
{
  /*  if(type == "Head") return heads[part_index].to_string();
    else if(type == "Locomotor") return locomotors[part_index].to_string();
    else if(type == "Torso") return torsos[part_index].to_string();
    else if(type == "Battery") return batteries[part_index].to_string();
    else if(type == "Arm") return arms[part_index].to_string();
    */
}

int Shop::number_of_parts(string type)
{
  /*
    if(type == "Head") return heads.size();
    else if(type == "Locomotor") return locomotors.size();
    else if(type == "Torso") return torsos.size();
    else if(type == "Battery") return batteries.size();
    else if(type == "Arm") return arms.size();
    */
}

int Shop::number_of_models()
{
//  return models.size();
}
string Shop::model_to_string(int model_index)
{
/*
    return models[model_index].to_string() + '\n'
    + std::to_string(models[model_index].cost()) + models[model_index].get_description();
    */
}

// View

string View::get_menu()
{
    string menu = R"(
#################
Robbie Robot Shop
#################

PARTS
------------------
(1) Create Part
(2) View Parts

Models
------------------
(3) Create Models
(4) Browse Models
(5) Purchase Models

Utility
------------------
(0) Exit

    )";

    return menu;
}

string View::get_head_list()
{
  string list = R"(
----------------------
List of Heads
----------------------

  )";
/*  string type = "Head";
  for(int i = 0; i < shop.number_of_parts(type); i++)
  {
      list += std::to_string(i) + ") " + shop.part_to_string(type,i) + '\n';
  }
*/

  return list;
}

string View::get_locomotor_list()
{
  string list = R"(
----------------------
List of Locomotors
----------------------

  )";
  /*
  string type = "Locomotor";
  for(int i = 0; i < shop.number_of_parts(type); i++)
  {
      list += std::to_string(i) + ") " + shop.part_to_string(type,i) + '\n';
  }
*/

  return list;
}

string View::get_torso_list()
{
  string list = R"(
----------------------
List of Toros
----------------------

  )";
  /*
  string type = "Torso";
  for(int i = 0; i < shop.number_of_parts(type); i++)
  {
      list += std::to_string(i) + ") " + shop.part_to_string(type,i) + '\n';
  }
*/

  return list;
}

string View::get_battery_list()
{
  string list = R"(
----------------------
List of Batteries
----------------------

  )";
  /*
  string type = "Battery";
  for(int i = 0; i < shop.number_of_parts(type); i++)
  {
      list += std::to_string(i) + ") " + shop.part_to_string(type,i) + '\n';
  }
*/

  return list;
}

string View::get_arm_list()
{
  string list = R"(
----------------------
List of Arms
----------------------

  )";
  /*
  string type = "Arm";
  for(int i = 0; i < shop.number_of_parts(type); i++)
  {
      list += std::to_string(i) + ") " + shop.part_to_string(type,i) + '\n';
  }
*/

  return list;
}

string View::get_part_list()
{
    string list = R"(
----------------------
Robot Parts
----------------------
1) Heads
2) Locomotors
3) Torsos
4) Batteries
5) Arms

0) Back
    )";

    return list;
}

string View::get_model_list()
{
  string list = R"(
----------------------
Robot Models
----------------------

  )";
/*
  for(int i = 0; i < shop.number_of_models(); i++)
  {
      list += std::to_string(i) + ") " + shop.model_to_string(i) + '\n';
  }
*/
  return list;
}

// Controller

void Controller::gui()
{
    Fl_JPEG_Image *jpg = new Fl_JPEG_Image("icon.jpg");
    string menu = view.get_menu() + "\nCommand? ";
    string no_label = "";
    int cmd = -1;
    while (cmd != 0)
    {
        fl_message_title("Robbie Robot Shop");
        fl_message_icon()->label(no_label.c_str());
        fl_message_icon()->labelsize(1);
        fl_message_icon()->image(*jpg);
        cmd = atoi(fl_input(menu.c_str(), 0));
        fl_message_icon()->image(0);
        execute_cmd(cmd);
    }
}
/*
string Controller::get_string(string name, string prompt)
{
    fl_message_title(name.c_str());
    fl_message_icon()->label("S");
    string result{fl_input(prompt.c_str(), 0)};
    return result;
}

int Controller::get_int(string name, string prompt)
{
    int res;
    cout << prompt << endl;
    cin >> res;

    return res;
}
double Controller::get_double(string name, string prompt)
{
    double res;
    cout << prompt << endl;
    cin >> res;

    return res;
}
*/
void Controller::execute_cmd(int cmd)
{
    if(cmd == 1)
    {
        Head *head;
        Arm *arm;
        Torso *torso;
        Locomotor *locomotor;
        Battery *battery;
        string name;
        int type;

        type = get_int("Part Type", "0 - Head\n1 - Locomotor\n2 - Torso\n3 - Battery\n4 - Arm\n");

        if(type == 0)
        {
          name = get_string("Head Name","Enter this head's name: ");
          head = new Head(
            name,
            get_int(name,"Enter this head's model number: "),
            get_double(name,"Enter this head's cost: "),
            get_string(name,"Enter description: "),
            get_double(name,"Enter this head's power: ")
          );
        }
        else if(type == 1)
        {
          name = get_string("Locomotor Name","Enter this locomotor's name: ");
          locomotor = new Locomotor(
            name,
            get_int(name,"Enter this locomotor's model number: "),
            get_double(name,"Enter this locomotor's cost: "),
            get_string(name,"Enter description: "),
            get_double(name,"Enter maximum power: ")
          );
        }
        else if(type == 2)
        {
          name = get_string("Torso Name","Enter this torso's name: ");
          torso = new Torso(
            name,
            get_int(name,"Enter this torso's model number: "),
            get_double(name,"Enter this torso's cost: "),
            get_string(name,"Enter description: "),
            get_int(name,"Enter maximum # of arms (0 to 2): ", 0, 2),
            get_int(name,"Enter maximum # of batteries (1 to 3): ", 1, 3)
          );
        }
        else if(type == 3)
        {
          name = get_string("Battery Name","Enter this battery's name: ");
          battery = new Battery(
            name,
            get_int(name,"Enter this battery's model number: "),
            get_double(name,"Enter this battery's cost: "),
            get_string(name,"Enter description: "),
            get_double(name,"Enter maximum energy: "),
            get_double(name,"Enter power available: ")
          );
        }
        else if(type == 4)
        {
          name = get_string("Arm Name","Enter this arm's name: ");
          arm = new Arm(
            name,
            get_int(name,"Enter this arm's model number: "),
            get_double(name,"Enter this arm's cost: "),
            get_string(name,"Enter description: "),
            get_double(name,"Enter maximum power: ")
          );
        }


    }
    else if(cmd == 2)
    {
      int s = -1;

        cout << view.get_part_list();
        cout << "Command?\n";
        cin >> s;
        if (s == 1) { cout << view.get_head_list() << endl;}
        else if(s == 2) { cout << view.get_locomotor_list() << endl;}
        else if(s == 3) { cout << view.get_torso_list() << endl;}
        else if(s == 4) { cout << view.get_battery_list() << endl;}
        else if(s == 5) { cout << view.get_arm_list() << endl;}

    }
    else if(cmd == 3)
    {
      string name;
      int number,h,l,t,b,num_arms,a;

      name = get_string("Model Name", "\nRobot name: ");
      number = get_int(name, "Model Number: ");
      cout << view.get_head_list() << endl;
      cin >> h;
      cout << view.get_locomotor_list() << endl;
      cin >> l;
      cout << view.get_torso_list() << endl;
      cin >> t;
      cout << view.get_battery_list() << endl;
      cin >> b;
      cout << view.get_arm_list() << endl;
      cin >> a;
      cout << "Number of arms: " << endl;
      cin >> num_arms;

      shop.create_model(Robot_Model(name, number, shop.get_head(h), shop.get_locomotor(l)
      , shop.get_torso(t), shop.get_battery(b), shop.get_arm(a)));
    }
    else if(cmd == 4)
    {
      int o;
      cout << view.get_model_list() << endl;
      cout << "Command?" << endl;
      cin >> o;

    }
}

// /////////////////////////////////////
//          C a l l   B a c k s
// /////////////////////////////////////
Controller *controller;

void CloseCB(Fl_Widget* w, void* p)
{
    win->hide();
}

void New_ShopCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(1);
}
void Load_ShopCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(2);
}
void Save_ShopCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(3);
}
void CutCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(4);
}
void CopyCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(5);
}
void PasteCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(6);
}
void PreferencesCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(9);
}
void C_OrderCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(9);
}
void C_CustomerCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(9);
}
void C_SACB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(9);
}
void C_ModelCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(9);
}
void C_PartCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(9);
}
void V_OrderCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(9);
}
void V_CustomerCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(9);
}
void V_SACB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(9);
}
void V_ModelCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(9);
}
void V_PartCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(9);
}

void HelpCB(Fl_Widget* w, void* p)
{
    controller->execute_cmd(9);
}


Fl_Menu_Item menuitems[] = {
  { "&File",0,0,0, FL_SUBMENU },
      { "&New Shop", FL_ALT + 'n', (Fl_Callback *)New_ShopCB},
      { "&Load Shop", FL_ALT + 'l', (Fl_Callback *)Load_ShopCB},
      { "&Save Shop", FL_ALT + 's', (Fl_Callback *)Save_ShopCB},
      { "&Exit", FL_ALT + 'q', (Fl_Callback *)CloseCB},
      { 0 },
  { "&Edit", 0,0,0, FL_SUBMENU },
      { "&Cut", FL_CTRL + 'x', (Fl_Callback *)CutCB},
      { "&Copy", FL_CTRL + 'c', (Fl_Callback *)CopyCB},
      { "&Paste", FL_CTRL + 'v', (Fl_Callback *)PasteCB},
      { "&Preferences", FL_ALT + 'p', (Fl_Callback *)PreferencesCB},
      { 0 },
  { "&Create", 0, 0, 0, FL_SUBMENU},
      { "&Order", FL_ALT + 'o', (Fl_Callback *)C_OrderCB},
      { "&Customer", 0, (Fl_Callback *)C_CustomerCB},
      { "&Sales Associate", 0, (Fl_Callback *)C_SACB},
      { "&Robot Model", FL_ALT + 'm', (Fl_Callback *)C_ModelCB},
      { "&Robot Part", FL_ALT + 'n', (Fl_Callback *)C_PartCB},
      { 0 },
  { "&View", 0, 0, 0, FL_SUBMENU},
      { "&Orders", 0, (Fl_Callback *)V_OrderCB},
      { "&Customers", 0, (Fl_Callback *)V_CustomerCB},
      { "&Sales Associates", 0, (Fl_Callback *)V_SACB},
      { "&Robot Models", 0, (Fl_Callback *)V_ModelCB},
      { "&Robot Parts", 0, (Fl_Callback *)V_PartCB},
      { 0 },
  { "&Help", 0, 0, 0, FL_SUBMENU},
      { "&Get Help", FL_ALT + 'h', (Fl_Callback *)HelpCB},
      { 0 },
  { 0 }
};


// /////////////////////////////////////
//               M A I N
// /////////////////////////////////////

int main() {
  const int X = 640;
  const int Y = 480;

  win = new Fl_Window(X,Y, "Robbie Robot Shop");

  menubar = new Fl_Menu_Bar(0,0,X,30);
  menubar->menu(menuitems);


  win->callback(CloseCB);
  win->end();
  win->show();
  return(Fl::run());





}
