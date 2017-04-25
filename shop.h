#ifndef _SHOP_H
#define _SHOP_H 201703
#include <string>
#include <iostream>

using namespace std;

class Shop {
  public:
    void create_head(Head head);
    void create_locomotor(Locomotor locomotor);
    void create_torso(Torso torso);
    void create_battery(Battery battery);
    void create_arm(Arm arm);

    Head get_head(int part_index);
    Locomotor get_locomotor(int part_index);
    Torso get_torso(int part_index);
    Battery get_battery(int part_index);
    Arm get_arm(int part_index);

    void create_model(Robot_Model robot);


    string part_to_string(string type,int part_index);
    string model_to_string(int model_index);

    int number_of_parts(string type);
    int number_of_models();



  private:
    string type;
    int num_parts,num_battery;
    vector<Head> heads;
    vector<Locomotor> locomotors;
    vector<Torso> torsos;
    vector<Battery> batteries;
    vector<Arm> arms;
    vector<Robot_Model> models;
};




#endif
