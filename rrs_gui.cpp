#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <exception>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/fl_ask.H>
#include "robot_part.h"
#include "shop.h"
#include "view.h"
#include "controller.h"
#include "utility.h"

using namespace std;


// Robot_Model

/*  My apologies, I have spent many hours trying to catch up on this project,
    but other priorities have gotten in the way.
*/

double Robot_Model::cost()
{
}


double Robot_Model::max_speed()
{

}

double Robot_Model::max_battery_life()
{

}
// Shop


void Shop::create_new_robot_part()
{
  Controller *controller;
  Head *head;
  Arm *arm;
  Torso *torso;
  Locomotor *locomotor;
  Battery *battery;
  string name;

  //while(true) {
    switch (controller->get_int("Robot Parts", R"(
   Which type of part?

(1) Create Head
(2) Create Arm
(3) Create Torso
(4) Create Locomotor
(5) Create Battery
(0) Exit

Selection? )", 0, 5)) {

      case 0: // Exit
        Fl::wait();
      case 1: // Head
        name = controller->get_string("Part Name","Enter this head's name: ");
        head = new Head{
          name,
          controller->get_int(name,"Enter this head's model number: "),
          controller->get_double(name,"Enter this head's cost: "),
          controller->get_string(name,"Enter description: "),
          controller->get_double(name,"Enter this head's power: ")
        };
        parts.push_back(*head);
        break;
      case 2:
        name = controller->get_string("Part Name","Enter this arm's name: ");
        arm = new Arm{
          name,
          controller->get_int(name,"Enter this arm's model number: "),
          controller->get_double(name,"Enter this arm's cost: "),
          controller->get_string(name,"Enter description: "),
          controller->get_double(name,"Enter maximum power: ")
        };
        parts.push_back(*arm);
        break;
      case 3:
        name = controller->get_string("Part Name","Enter this torso's name: ");
        torso = new Torso{
          name,
          controller->get_int(name,"Enter this torso's model number: "),
          controller->get_double(name,"Enter this torso's cost: "),
          controller->get_string(name,"Enter description: "),
          controller->get_int(name,"Enter maximum # of arms (0 to 2): ", 0, 2),
          controller->get_int(name,"Enter maximum # of batteries (1 to 3): ", 1, 3)
        };
        parts.push_back(*torso);
        break;
      case 4:
        name = controller->get_string("Part Name","Enter this locomotor's name: ");
        locomotor = new Locomotor{
          name,
          controller->get_int(name,"Enter this locomotor's model number: "),
          controller->get_double(name,"Enter this locomotor's cost: "),
          controller->get_string(name,"Enter description: "),
          controller->get_double(name,"Enter maximum power: ")
        };
        parts.push_back(*locomotor);
        break;
      case 5:
        controller->get_string("Part Name","Enter this battery's name: ");
        battery = new Battery{
          name,
          controller->get_int(name,"Enter this battery's model number: "),
          controller->get_double(name,"Enter this battery's cost: "),
          controller->get_string(name,"Enter description: "),
          controller->get_double(name,"Enter maximum energy: "),
          controller->get_double(name,"Enter power available: ")
        };
        parts.push_back(*battery);
        break;

      default:
        break;
    }
  //}

}

/*void Shop::create_new_robot_part(istream& ist)
{
    parts.push_back(Robot_part(ist));
}
*/
int Shop::number_of_parts()
{
    return parts.size();
}
string Shop::part_to_string(int part_index)
{
    return parts[part_index].name();
}

string Shop::get_part_list()
{
  string list = R"(
--------------------
List of Parts
--------------------
)";
  for (int i = 0; i < number_of_parts(); i++)
  {
      list += std::to_string(i) + ") " + part_to_string(i) + "\n";
  }
  return list;
}

void Shop::create_new_robot_model()
{
    Controller *controller;
    Robot_Model *robot_model;
    //int model_number;
    //double cost;
  //  string description;
    string name = controller->get_string("Model Name", "Enter the name of the robot model: ");
  /*  robot_model = new Robot_Model(
      name,
      controller->get_int(name, "Model Number: "),
      parts[controller->get_int(name, get_part_list() + "\nHead: ")],
      parts[controller->get_int(name, get_part_list() + "\nLocomotor: ")],
      parts[controller->get_int(name, get_part_list() + "\nTorso: ")],
      parts[controller->get_int(name, get_part_list() + "\nArm(s):")],
      parts[controller->get_int(name, get_part_list() + "\nBattery: ")],
      robot_model->cost(), robot_model->get_description());

    models.push_back(*robot_model);
    */
}
/*
void Shop::create_new_robot_model(istream& ist)
{
    models.push_back(Robot_Model(ist));
}
*/
void Shop::create_new_customer()
{

}
/*
void Shop::create_new_customer(istream& ist)
{
    customers.push_back(Customer(ist));
}
*/
void Shop::create_new_sales_associate()
{

}
/*
void Shop::create_new_sales_associate(istream& ist)
{
    associates.push_back(Sales_Associate(ist));
}
*/
void Shop::create_new_order()
{

}
/*
void Shop::create_new_order(istream& ist)
{
    orders.push_back(Order(ist));
}
*/


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

string View::get_part_list()
{
  string list = R"(
--------------------
List of Parts
--------------------
)";
  for (int i = 0; i < shop.number_of_parts(); i++)
  {
      list += std::to_string(i) + ") " + shop.part_to_string(i) + "\n";
  }
  return list;
}

/*string View::get_head_list()
{
  string list = R"(
----------------------
List of Heads
----------------------

  )";
  string type = "Head";
  for(int i = 0; i < shop.number_of_parts(type); i++)
  {
      list += std::to_string(i) + ") " + shop.part_to_string(type,i) + '\n';
  }

  return list;
}

string View::get_locomotor_list()
{
  string list = R"(
----------------------
List of Locomotors
----------------------

  )";
  string type = "Locomotor";
  for(int i = 0; i < shop.number_of_parts(type); i++)
  {
      list += std::to_string(i) + ") " + shop.part_to_string(type,i) + '\n';
  }

  return list;
}

string View::get_torso_list()
{
  string list = R"(
----------------------
List of Toros
----------------------

  )";
  string type = "Torso";
  for(int i = 0; i < shop.number_of_parts(type); i++)
  {
      list += std::to_string(i) + ") " + shop.part_to_string(type,i) + '\n';
  }

  return list;
}

string View::get_battery_list()
{
  string list = R"(
----------------------
List of Batteries
----------------------

  )";
  string type = "Battery";
  for(int i = 0; i < shop.number_of_parts(type); i++)
  {
      list += std::to_string(i) + ") " + shop.part_to_string(type,i) + '\n';
  }

  return list;
}

string View::get_arm_list()
{
  string list = R"(
----------------------
List of Arms
----------------------

  )";
  string type = "Arm";
  for(int i = 0; i < shop.number_of_parts(type); i++)
  {
      list += std::to_string(i) + ") " + shop.part_to_string(type,i) + '\n';
  }

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
*/

void Shop::new_shop()
{
    if(parts.size() > 0){
    parts.clear();
    models.clear();
    customers.clear();
    associates.clear();
    orders.clear();
  }
    dirty = false;
}

void Shop::save_shop(ostream& os)
{
  /*  for(Robot_part p : parts)
    {
      p.save(os);

    }
    for(Robot_Model m : models)
    {
      m.save(os);

    }
    for(Customer c : customers)
    {
      c.save(os);

    }
    for(Sales_Associate sa : associates)
    {
      sa.save(os);

    }
    for(Order o : orders)
    {
      o.save(os);

    }
    */
    dirty = false;
}

void Shop::open_shop(istream& is)
{
    //Robot_part* p {0,0,0,0};
  //  while(cin >> p) { parts.push_back(p);}          // Need to do load data for things below
  /*  Robot_Model m;
    while(cin >> m) { models.push_back(m);}
    Customer c;
    while(cin >> c) { customers.push_back(c);}
    Sales_Associate sa;
    while(cin >> sa) { associates.push_back(sa);}
    Order o;
    while(cin >> o) { orders.push_back(o);}
    */
}

void Shop::load_shop(istream& is)
{
    while(is) open_shop(is); dirty = false;
}

bool Shop::saved()
{
  return !dirty;
}



// Controller


void Controller::execute_cmd(int cmd)
{
    if(cmd == 1) // Create part
    {
        //shop.create_new_robot_part();

    }
    else if(cmd == 2) // Load shop
    {
    /*    string filename;

        filename = get_string("Load File", "Enter the name of file: ");
        ifstream ist {filename};

        if(!ist) throw runtime_error("Can't open file " + filename);

        shop.load_shop(ist);*/
    }
    else if(cmd == 3) // Save Shop
    {
      /*string filename;

      filename = get_string("Saving File", "Enter name of file: ");
      ofstream ost {filename};

      if(!ost) throw runtime_error("Can't open file " + filename);

      shop.save_shop(ost);
*/
    }
    else if(cmd == 4) // Create Model
    {
        string list = view.get_part_list();
        fl_message_title("List of All Parts");
        fl_message_icon()->label("P");
        fl_message(list.c_str());
      //  shop.create_new_robot_model();

    }
}

void Controller::gui()
{
    string menu = view.get_menu() + "\nCommand? ";
    int cmd = -1;
    while(cmd != 0)
    {
        cmd = atoi(fl_input(menu.c_str(), 0));
        execute_cmd(cmd);
    }

}

// /////////////////////////////////////
//          C a l l   B a c k s
// /////////////////////////////////////
Controller *controller;
Shop shop;
Fl_Window *win;
Fl_Menu_Bar *menubar;

void CloseCB(Fl_Widget* w, void* p)
{
    win->hide();
}

void New_ShopCB(Fl_Widget* w, void* p)
{
  win->label("New selected");
  shop.new_shop();

    Fl::check();
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
    win->label("Cut selected");
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
    controller->execute_cmd(4);
}
void C_PartCB(Fl_Widget* w, void* p)
{
    shop.create_new_robot_part();

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
    controller->execute_cmd(2);
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
  Shop shop;
  View view{shop};
  //Fl_Window beacon(1,1);
  //beacon.show();
  Controller controller(shop,view);

  //controller.gui();

  const int X = 640;
  const int Y = 480;

  win = new Fl_Window(X,Y, "Robbie Robot Shop");
  win->color(FL_WHITE);
  menubar = new Fl_Menu_Bar(0,0,X,30);
  menubar->menu(menuitems);
  //controller.gui();


  win->callback(CloseCB);
  win->end();
  win->show();

  return(Fl::run());

}
