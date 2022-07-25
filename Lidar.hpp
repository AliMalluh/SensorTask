#include "header.h"
#include "Sensor.hpp"

class Lidar : public Sensor
{
  vector<double> scores_;

public:
  void readFromFile(string path)
  {
    ifstream inFile;
    string line;
    vector<double>::iterator it;
    inFile.open(path + "/LIDAR.txt");

    getline(inFile, line);
    string s = line;
    string delimiter = ",";

    size_t pos = 0;
    string token;
    while (pos != string::npos)
    {
      pos = s.find(delimiter);
      if (pos == string::npos)
      {
        break;
      }
      token = s.substr(0, pos);
      scores_.push_back(stod(token));
      s.erase(0, pos + delimiter.length());
    }
    scores_.push_back(stod(s));
    it = scores_.begin();
    set(*it);
    scores_.erase(it);
    inFile.close();
  }
  void Avg()
  {
    cout << "The Lidar Avarage is " << std::accumulate(scores_.begin(), scores_.end(), 0.0) / scores_.size() << endl;
  }
  void Max()
  {
    cout << "The Lidar Maximum Read is " << *max_element(scores_.begin(), scores_.end()) << endl;
  }
  void Min()
  {
    cout << "The Lidar Minmum Read is " << *min_element(scores_.begin(), scores_.end()) << endl;
  }
};