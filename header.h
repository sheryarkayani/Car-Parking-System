
#include<iostream>
#include<vector>
#include <cstring>
#include <string.h>
using namespace std;


using namespace std;

// Car class definition
class Car {
    int regNo;
    int arrTime;
    int slotNo;

public:
    Car() : regNo(0), arrTime(0), slotNo(0) {}
    Car(int regNo, int arrTime, int slotNo) : regNo(regNo), arrTime(arrTime), slotNo(slotNo) {}

    int getRegNo() { return regNo; }
    int getArrTime() { return arrTime; }
    int getSlotNo() { return slotNo; }

    void setSlotNo(int newSlot) { slotNo = newSlot; }
    void setRegNo(int newRegNo) { regNo = newRegNo; }
    void setArrTime(int newArrTime) { arrTime = newArrTime; }
};
