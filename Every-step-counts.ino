#include <Wire.h>

// MPU6050 I2C address
const int MPU6050_ADDR = 0x68;

// MPU6050 registers
const int PWR_MGMT_1 = 0x6B;
const int ACCEL_XOUT_H = 0x3B;
const int GYRO_XOUT_H = 0x43;

int accelX, accelY, accelZ;
int gyroX, gyroY, gyroZ;
float yaw = 0.0;

const float GYRO_SENSITIVITY = 131.0;   //sensitivity scale factor for the gyroscope assuming the gyroscope is operating in the default ±250°/s range

unsigned long previousTime = 0;

void setup() {
    Wire.begin();
    Serial.begin(9600);
    
    // Wake up the MPU6050
    Wire.beginTransmission(MPU6050_ADDR);
    Wire.write(PWR_MGMT_1);
    Wire.write(0x00); 
    Wire.endTransmission();

    delay(100);
}

void loop() {
    unsigned long currentTime = millis();
    float elapsedTime = (currentTime - previousTime) / 1000.0; // Time in seconds
    previousTime = currentTime;

    // Read raw accelerometer and gyroscope data
    readMPU6050();

    // Convert gyroscope raw data to degrees per second
    float gyroZ_dps = gyroZ / GYRO_SENSITIVITY;

   
    yaw += gyroZ_dps * elapsedTime;

    // Print the yaw angle
    Serial.print("Yaw: ");
    Serial.println(yaw);

    delay(100);
}

void readMPU6050() {
  
    Wire.beginTransmission(MPU6050_ADDR);
    Wire.write(ACCEL_XOUT_H); 
    Wire.endTransmission(false);
    Wire.requestFrom(MPU6050_ADDR, 14, true);

    accelX = (Wire.read() << 8 | Wire.read());
    accelY = (Wire.read() << 8 | Wire.read());
    accelZ = (Wire.read() << 8 | Wire.read());

   
    Wire.read();
    Wire.read();

    gyroX = (Wire.read() << 8 | Wire.read());
    gyroY = (Wire.read() << 8 | Wire.read());
    gyroZ = (Wire.read() << 8 | Wire.read());
}
