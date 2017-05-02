#ifndef _VIEW_H
#define _VIEW_H 201703
#include <string>
#include <iostream>

using namespace std;

class View {
  bool dirty = false;
  public:
    View(Shop& shop) : shop(shop) { }
    string get_menu();
    string get_part_list();
    string get_head_list();
    string get_locomotor_list();
    string get_torso_list();
    string get_battery_list();
    string get_arm_list();
    string get_model_list();


  private:
    Shop& shop;

};




#endif
