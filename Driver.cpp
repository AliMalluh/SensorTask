#include "header.h"
#include "IMU.hpp"
#include "GPS.hpp"
#include "Image.hpp"
#include "Lidar.hpp"
#include "Sensor.hpp"
int main(void)
{
  string path;
  cout << "Enter The path :\n";
  cin >> path;
  cout << "\n";
  vector<Sensor *> sen;
  sen.push_back(new Lidar());
  sen.push_back(new GPS());
  sen.push_back(new IMU());
  sen.push_back(new Image());

  for (auto i : sen)
  {
    i->init(path);
    i->Avg();
    i->Max();
    i->Min();
    cout << "----------------------------\n";
  }

  return 0;
}