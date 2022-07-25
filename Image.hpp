#include "header.h"
#include "Sensor.hpp"

class Image : public Sensor
{
  vector<vector<int>> scores_;

public:
  void readFromFile(string path)
  {
    ifstream inFile;
    string line;
    int i = 0, j = 0, x = 0;
    inFile.open(path + "/Image.txt");

    while (!inFile.eof())
    {

      if (x == 0)
      {
        getline(inFile, line);
        set(stod(line));
        x++;
      }
      else
      {
        getline(inFile, line);
        string s = line;
        string delimiter = ",";

        size_t pos = 0;
        string token;
        vector<int> temp;
        while (pos != string::npos)
        {
          pos = s.find(delimiter);
          token = s.substr(0, pos);

          temp.push_back(stoi(token));

          s.erase(0, pos + delimiter.length());
          if (j >= 5)
          {
            j = 0;
          }
          else
            j++;
        }
        i++;
        scores_.push_back(temp);
      }
    }

    inFile.close();
  }

  void Avg()
  {
    int sum = 0, num = 0;
    for (auto i : scores_)
    {
      for (auto j : i)
      {
        sum += j;
        num++;
      }
    }
    cout << "The Image Average is " << sum / num << endl;
  }
  void Max()
  {
    int max = 0;

    for (auto i : scores_)
    {
      for (auto j : i)
      {
        if (j > max)
          max = j;
      }
    }
    cout << "The Image Maximum Read is " << max << endl;
  }
  void Min()
  {
    int min = scores_.front().front();
    for (auto i : scores_)
    {
      for (auto j : i)
      {
        if (j < min)
          min = j;
      }
    }
    cout << "The Image Minimum Read is " << min << endl;
  }
};