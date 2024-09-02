# task10.5 
## MPU6050 Yaw Reading with Arduino
// this Arduino code reads yaw from an MPU6050 IMU using I2C without using any library for IMU except Wire.h
### Code Explanation:

1. **Initialize the MPU6050**: 
   - The code wakes up the MPU6050 by writing to the `PWR_MGMT_1` register, as the sensor is in sleep mode by default.

2. **Read Sensor Data**:
   - Raw accelerometer and gyroscope data are read from the MPU6050 registers using the I2C protocol.
   
3. **Calculate Yaw**:
   - The yaw angle is calculated by integrating the gyroscope's Z-axis data over time.
   
4. **Output Yaw**:
   - The calculated yaw angle is printed to the Serial Monitor for visualization.
### REfrences 
[MPU6050 datasheet](https://www.alldatasheet.com/datasheet-pdf/pdf/1132807/TDK/MPU-6050.html)
