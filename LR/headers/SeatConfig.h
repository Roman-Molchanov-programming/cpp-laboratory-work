#pragma once

#include <compare>
#include <iostream>

class SeatConfig {
  protected:
    int lowerSeats;
    int upperSeats;

  public:
    SeatConfig(int lower = 0, int upper = 0);
    virtual ~SeatConfig() = default;

    int getLowerSeats() const;
    int getUpperSeats() const;
    virtual int getTotalSeats() const;

    void setLowerSeats(int lower);
    void setUpperSeats(int upper);

    auto operator<=>(const SeatConfig &other) const = default;
    bool operator==(const SeatConfig &other) const = default;

    friend std::ostream &operator<<(std::ostream &os, const SeatConfig &config);
    friend std::istream &operator>>(std::istream &is, SeatConfig &config);

    virtual void printInfo(std::ostream &os) const;
    virtual void inputData(std::istream &is);
};

class PlatskartSeatConfig : public SeatConfig {
  private:
    int sideLowerSeats;
    int sideUpperSeats;

  public:
    PlatskartSeatConfig(int mainLower = 18, int mainUpper = 18, int sideLower = 9,
                        int sideUpper = 9);

    int getSideLowerSeats() const;
    int getSideUpperSeats() const;
    int getTotalSeats() const override;

    void setSideLowerSeats(int sideLower);
    void setSideUpperSeats(int sideUpper);

    auto operator<=>(const PlatskartSeatConfig &other) const = default;
    bool operator==(const PlatskartSeatConfig &other) const = default;

    void printInfo(std::ostream &os) const override;
    void inputData(std::istream &is) override;
};