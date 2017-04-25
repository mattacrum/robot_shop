#ifndef _CONTROLLER_H
#define _CONTROLLER_H 201703
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
#include <climits>

using namespace std;


class Controller
{
  public:
    Controller(Shop& shop, View& view) : shop(shop), view(view) { }
    void cli();
    void gui();
    void execute_cmd(int cmd);
    //
    // Return any string from the user, including a simple \n
    //
    string get_string(string name, string prompt) {
      fl_message_title(name.c_str());
      fl_message_icon()->label("S");
      string result{fl_input(prompt.c_str(), 0)};
      return result;
    }

    //
    // Skip all characters in the STDIN buffer up to and including the next newline
    // For use after a cin stream operation, to clear invalid text and the newline
    //
    void skip() {
      if (cin.fail())
        cin.clear();
      cin.ignore(INT_MAX, '\n');
    }

    //
    // Return any valid integer from the user
    //
    int get_int(string name, string prompt) {
      int result = 0;
      while (true) {
        fl_message_title(name.c_str());
        fl_message_icon()->label("S");
        string res{fl_input(prompt.c_str(), 0)};
        result = atoi(res.c_str());
        bool success = cin.good();
        skip();
        if (success) return result;
        cerr << "### Not an integer!" << endl;

      }
    }

    //
    // Return any valid integer between min_int and max_int, inclusive
    //
    int get_int(string name,string prompt, int min_int, int max_int) {
      int result = min_int - 1;
      while (true) {
        fl_message_title(name.c_str());
        fl_message_icon()->label("S");
        string res{fl_input(prompt.c_str(), 0)};
        result = atoi(res.c_str());
        if (min_int <= result && result <= max_int) return result;
        cerr << "### Integer must be between " << min_int << " and " << max_int << "!\n";
      }
    }

    //
    // Return any valid double from the user
    //
    double get_double(string name, string prompt) {
      double result = 0.0;
      while (true) {
        fl_message_title(name.c_str());
        fl_message_icon()->label("S");
        string res{fl_input(prompt.c_str(), 0)};
        result = atof(res.c_str());
        bool success = cin.good();
        skip();
        if (success) return result;
        cerr << "### Not a number!" << endl;
      }
    }
  private:
    //int get_int(string name, string prompt);
  //  string get_string(string name, string prompt);
  //  double get_double(string name, string prompt);
    Shop& shop;
    View& view;


};

#endif
