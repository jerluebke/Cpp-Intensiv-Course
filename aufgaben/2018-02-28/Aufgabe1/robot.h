#ifndef ROBOT_H_
#define ROBOT_H_

#include "target.h"
#include <string>
#include <iostream>
#include <cmath>

class robot
{
	public:
		robot();

		void moveHead(float degree);
		void openHand();
		void moveRobot(int newPosX, int newPosY);
		void moveRobot(float newPosX, float newPosY);
		void moveRobot(float degree, unsigned int speed = 1000);
        // <1>
        // removed `const` specifier of `int speed`
		void moveRobot(int speed);
		void turnRobot(const float degree);
		bool locateTarget();

		void calibrateCamera();
		void addHand();
		void setTarget(target* newTarget);
		void printStatusCode() const;

        // <2>
        // moved these two methodes from `private` to `public`
        // no special treatment needed, since they don't modify anything
		void moveFinger1();
		void moveFinger2();

        // <3>
        // added public methods to retreive position
		const float getPosX() const;
		const float getPosY() const;

		robot operator+(robot & rob);

  private:
		float m_posX;
		float m_posY;
		float m_headDirection;      // in Grad (relativ zur x-Achse des Koordinatensystems)
		float m_bodyDirection;      // in Grad (relativ zur x-Achse des Koordinatensystems)
		unsigned int m_handCount;   // Anzahl der montierten Hände
		target* m_currentTarget;    // Informationen zum (einzigen) aktuellen Zielobjekt
		bool m_cameraCalibrated;
		long int* m_status;
};

#endif /* ROBOT_H_ */
