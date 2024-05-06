
TITLE: Two Wheel Drive with Multiple Sensors 

OBJECTIVE:  To implement two wheel drive with multiple sensors.

COMPONENTS REQUIRED ALONG WITH THEIR SPECIFICATIONS:


S.no	Name of the component/specifications	Quantity
1.	Arduino NANO ESP32	1
2.	Ultrasonic Sensors 	1
3.	IR Sensor	1
4.	Bluetooth – BLE	1
5.	Tilt Sensors	1
6.	Motor	2
7.	L298N bridge	1


MOTIVATION/SOCIATAL/INDUSTRIAL IMPACT:   To understand the mechanism of two wheel drive using  multiple sensors.

OBSERVATION TABLE:

Sensor Data	Action Taken	Vehicle Response
Ultrasonic: Distance=50 cm	NONE	No obstacles detected
Edge detection: Edge detected	Brake applied	Vehicle stops to prevent fall
Tilt detection: Tilt angle=15°	Steering adjustment	Vehicle corrects its orientation
Reverse assist: Obstacle detected	Reverse initiated	Vehicle backs up safely


RESULT ANALYSIS:  The Two-wheel drive with multiple sensors with Bluetooth low energy gives various types of data collected from the sensors and with edge detection, tilt detection and Reverse Assit.


CONCLUSION:
A two-wheel drive vehicle, enhanced with Bluetooth Low Energy connectivity, integrates sensors for edge detection, tilt sensing, and reverse assistance. These sensors collect data on orientation, obstacles, and distances to ensure safe navigation. Bluetooth enables wireless communication for remote control and data transfer. This adaptable platform finds utility in robotics and autonomous systems, providing stability control, obstacle avoidance, and the capacity to navigate varied environments. Real-time feedback and remote operation capabilities empower users to monitor and control the vehicle remotely, facilitating applications ranging from hobbyist projects to industrial automation and beyond.


PROBLEMS FACED DURING THE IMPLEMENTATION (IF ANY):
1.	Some jumper wires were not providing supply to the Arduino.
2.	The connections between Sensors and the Arduino IP address were difficult to make.
3.	The Bluetooth connection’s power supply was low.

PROBLEMS RESOLVED USING SOLUTIONS (IF ANY):
1.	We had to use wire connectivity tester to check the jumper wires.
2.	Looked into many codes to make the connections between sensors and Arduino IP addresses.
3.	Connected the Bluetooth directly to a supply.

FUTURE SCOPE:
Future enhancements may include LiDAR integration for precise obstacle detection, machine learning algorithms for intelligent decision-making, and expansion of communication protocols for extended range. Optimization of power efficiency, component miniaturization, and robustness features would further enhance autonomy, versatility, and reliability for diverse applications in robotics and transportation. 
