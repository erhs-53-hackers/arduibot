#include "Gyro.h"


Gyro::Gyro() { 
  reset();
}

void Gyro::reset() {
  x = 0;
  y = 0;
  z = 0;
  Ztime = 0;
  Ytime = 0;
  Xtime = 0;    
  sign = 1;
}
void Gyro::configure() {
  setupL3G4200D(2000);
  delay(150);
  
}
double Gyro::getZ() {
  double last = Ztime;
  Ztime = getSeconds();
  double delta = Ztime - last;
  z += (getGyroZ() - ZDRIFT) * delta;
  
  return modAngle(z * FACTOR);
}

double Gyro::getY() {
  double last = Ytime;
  Ytime = getSeconds();
  double delta = Ytime - last;
  y += (getGyroY() - YDRIFT) * delta;
  
  return modAngle(y * FACTOR);
}

double Gyro::getX() {
  double last = Xtime;
  Xtime = getSeconds();
  double delta = Xtime - last;
  x += (getGyroX() - XDRIFT) * delta;
  
  return modAngle(x * FACTOR);
}

double Gyro::modAngle(double angle) {
  while(angle > 360) { 
    angle -= 360;    
  }
  while(angle < -360) {
    angle += 360;    
  }
  return angle;
}

double Gyro::getSeconds() {
  return millis() / 1000.0;
}

double Gyro::tuneZDrift(int i) {
  double sum = 0;  
  for(int a=0;a<i;a++) {
    Serial.print("Mean:");
    Serial.print(sum/double(a+1));
    Serial.print("| ");
    Serial.print(a/double(i) * 100.0); 
    Serial.println("% Done");
    delay(1000);    
    sum += getGyroZ();    
  }
  return sum / i;
}

double Gyro::tuneYDrift(int i) {
  double sum = 0;  
  for(int a=0;a<i;a++) {
    Serial.print("Mean:");
    Serial.print(sum/double(a+1));
    Serial.print("| ");
    Serial.print(a/double(i) * 100.0);   
    Serial.println("% Done");
    delay(1000);    
    sum += getGyroY();    
  }

  return sum / i;
}

double Gyro::tuneXDrift(int i) {
  double sum = 0;  
  for(int a=0;a<i;a++) {
    Serial.print("Mean:");
    Serial.print(sum/double(a+1));
    Serial.print("| ");
    Serial.print(a/double(i) * 100.0);   
    Serial.println("% Done");
    delay(1000);    
    sum += getGyroX();    
  }

  return sum / i;
}


int Gyro::getGyroX() {
  byte xMSB = readRegister(L3G4200D_Address, 0x29);
  byte xLSB = readRegister(L3G4200D_Address, 0x28);
  return ((xMSB << 8) | xLSB);
}

int Gyro::getGyroY() {
  byte yMSB = readRegister(L3G4200D_Address, 0x2B);
  byte yLSB = readRegister(L3G4200D_Address, 0x2A);
  return ((yMSB << 8) | yLSB);  
}

int Gyro::getGyroZ() {
  byte zMSB = readRegister(L3G4200D_Address, 0x2D);
  byte zLSB = readRegister(L3G4200D_Address, 0x2C);
  return ((zMSB << 8) | zLSB);
}

int Gyro::setupL3G4200D(int scale){
  //From  Jim Lindblom of Sparkfun's code

    // Enable x, y, z and turn off power down:
  writeRegister(L3G4200D_Address, CTRL_REG1, 0b00001111);

  // If you'd like to adjust/use the HPF, you can edit the line below to configure CTRL_REG2:
  writeRegister(L3G4200D_Address, CTRL_REG2, 0b00000000);

  // Configure CTRL_REG3 to generate data ready interrupt on INT2
  // No interrupts used on INT1, if you'd like to configure INT1
  // or INT2 otherwise, consult the datasheet:
  writeRegister(L3G4200D_Address, CTRL_REG3, 0b00001000);

  // CTRL_REG4 controls the full-scale range, among other things:

  if(scale == 250){
    writeRegister(L3G4200D_Address, CTRL_REG4, 0b00000000);
  }
  else if(scale == 500){
    writeRegister(L3G4200D_Address, CTRL_REG4, 0b00010000);
  }
  else{
    writeRegister(L3G4200D_Address, CTRL_REG4, 0b00110000);
  }

  // CTRL_REG5 controls high-pass filtering of outputs, use it
  // if you'd like:
  writeRegister(L3G4200D_Address, CTRL_REG5, 0b00000000);
}

void Gyro::writeRegister(int deviceAddress, byte address, byte val) {
  Wire.beginTransmission(deviceAddress); // start transmission to device 
  Wire.write(address);       // send register address
  Wire.write(val);         // send value to write
  Wire.endTransmission();     // end transmission
}

int Gyro::readRegister(int deviceAddress, byte address){

  int v;
  Wire.beginTransmission(deviceAddress);
  Wire.write(address); // register to read
  Wire.endTransmission();
  Wire.requestFrom(deviceAddress, 1); // read a byte
  while(!Wire.available()) {
    // waiting
  }
  v = Wire.read();
  return v;
}    


