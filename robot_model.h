#ifndef _ROBOT_MODEL_H
#define _ROBOT_MODEL_H 201703
#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
//#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/fl_ask.H>

using namespace std;

class Robot_Model
{
  private:
    string name;
    int model_number;
    Head head;
    Locomotor locomotor;
    Torso torso;
    Battery battery;
    Arm arm;

  public:
    Robot_Model(string name, int model_number, Head head, Locomotor locomotor, Torso torso, Battery battery,
      Arm arm)
    : name(name), model_number(model_number), head(head), locomotor(locomotor), torso(torso), battery(battery)
    , arm(arm) { }

    string to_string();
    string get_description();

    double cost();
    double max_speed();
    double max_battery_life();
};

#endif
