#pragma once

#include <iostream>
#include <string>
#include <string_view>

class Carriage {
  private:
    std::string type;
    int number;

  public:
    Carriage();
    Carriage(std::string_view t, int num);

    std::string getType() const;
    int getNumber() const;

    void setType(std::string_view t);
    void setNumber(int num);

    void inputData();
    void printInfo() const;
};