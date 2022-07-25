#include "header.h"
#include "Sensor.hpp"

class IMU : public Sensor
{

public:
  vector<tuple<float, float, float, float>> scores_;

  void readFromFile(string path)
  {
    ifstream inFile;
    string line;
    inFile.open(path + "/IMU.txt");

    int i = 0;
    float first, second, third, fourth;
    while (!inFile.eof())
    {
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
        if (i == 0)
        {
          token = s.substr(0, pos);
          first = stof(token);
          s.erase(0, pos + delimiter.length());
          i++;
        }
        else if (i == 1)
        {
          token = s.substr(0, pos);
          second = stof(token);
          s.erase(0, pos + delimiter.length());
          i++;
        }
        else if (i == 2)
        {
          token = s.substr(0, pos);
          third = stof(token);
          s.erase(0, pos + delimiter.length());
        }
        fourth = stof(s);
      }
      scores_.push_back(make_tuple(first, second, third, fourth));
    }
    inFile.close();
  }

  void Avg()
  {
    float sum = 0;
    for (uint i = 0; i < scores_.size(); i++)
    {
      sum += std::get<1>(scores_[i]);
    }

    cout << "The IMU Yaw Avarage is " << sum / (scores_.size()) << endl;
    sum = 0;
    for (uint i = 0; i != scores_.size(); i++)
    {
      sum += std::get<2>(scores_[i]);
    }
    cout << "The IMU Pitch Avarage is " << sum / (scores_.size()) << endl;
    for (uint i = 0; i != scores_.size(); i++)
    {
      sum += std::get<3>(scores_[i]);
    }
    cout << "The IMU Roll Avarage is " << sum / (scores_.size()) << endl;
  }
  void Max()
  {
    float max = 0;
    for (uint i = 0; i != scores_.size(); i++)
    {
      if (std::get<1>(scores_[i]) > max)
        max = std::get<1>(scores_[i]);
    }
    cout << "The IMU Yaw Maximum is " << max << endl;
    max = 0;
    for (uint i = 0; i != scores_.size(); i++)
    {
      if (std::get<2>(scores_[i]) > max)
        max = std::get<2>(scores_[i]);
    }
    cout << "The IMU Pitch Maximum is " << max << endl;
    for (uint i = 0; i != scores_.size(); i++)
    {
      if (std::get<3>(scores_[i]) > max)
        max = std::get<3>(scores_[i]);
    }
    cout << "The IMU Roll Maximum is " << max << endl;
  }
  void Min()
  {
    float min = std::get<1>(scores_[0]);
    for (uint i = 0; i != scores_.size(); i++)
    {
      if (std::get<1>(scores_[i]) < min)
        min = std::get<1>(scores_[i]);
    }
    cout << "The IMU Yaw Minimum is " << min << endl;
    min = std::get<2>(scores_[0]);
    for (uint i = 0; i != scores_.size(); i++)
    {
      if (std::get<2>(scores_[i]) < min)
        min = std::get<2>(scores_[i]);
    }
    cout << "The IMU Pitch Minimum is " << min << endl;
    min = std::get<3>(scores_[0]);
    for (uint i = 0; i != scores_.size(); i++)
    {
      if (std::get<3>(scores_[i]) < min)
        min = std::get<3>(scores_[i]);
    }
    cout << "The IMU Roll Minimum is " << min << endl;
  }
};
