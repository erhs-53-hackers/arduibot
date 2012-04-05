#include <arduino.h>
#include <Wire.h>
#define FACTOR 18.0 / 256.0
#define ZDRIFT -4.92 //-5.11 //-4.73
#define YDRIFT -4.58
#define XDRIFT -14.8//-14.8
#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24
#define L3G4200D_Address 105


class Gyro {
public:
  Gyro();
  double getZ();
  double getY();
  double getX();
  double tuneZDrift(int i);
  double tuneYDrift(int i);
  double tuneXDrift(int i);
  void configure();
  void reset();
private:
  double x, y, z, Ztime, Ytime, Xtime;
  int sign;
  double modAngle(double angle);
  double getSeconds();  
  int getGyroX();
  int getGyroY();
  int getGyroZ();
  int setupL3G4200D(int scale);
  void writeRegister(int deviceAddress, byte address, byte val);
  int readRegister(int deviceAddress, byte address);

};
