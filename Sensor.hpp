#pragma once
#include "header.h"

class Sensor
{

private:
  double timesTamp;

protected:
  virtual void readFromFile(string path) = 0;

public:
  void init(string path)
  {
    readFromFile(path);
  }
  virtual void Avg() = 0;
  virtual void Max() = 0;
  virtual void Min() = 0;

  void set(double a)
  {
    timesTamp = a;
  }
  double get()
  {
    return timesTamp;
  }
};