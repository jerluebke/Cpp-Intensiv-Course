#include "robot.h"

robot::robot()
{
	m_posX = 0;
	m_posY = 0;
	m_headDirection = 0;
	m_bodyDirection = 0;
	m_currentTarget = NULL;
	m_handCount = 0;
	m_cameraCalibrated = false;
    // <6>
    // save m_status on stack not on heap
	m_status = 1234567890;
}


void robot::moveHead(float degree)
{
	degree += m_headDirection;
	m_headDirection = float(static_cast<int>(degree) % 360);
}

void robot::openHand()
{
	for (unsigned int i = 0; i < m_handCount; i++)
	{
		moveFinger1();
		moveFinger2();
	};
}

void robot::moveRobot(int newPosX, int newPosY)
{
	std::cout << "Warnung: Positionsangabe ist ungenau \n";
	robot::moveRobot((float)newPosX, float(newPosY));
}

void robot::moveRobot(float newPosX, float newPosY)
{
	float degree;
	int speed = 100;
	const float pi = 3.14f;
	degree = (atan2(newPosY, newPosX) + pi) / (2*pi) * 360;
	turnRobot(degree);
	moveRobot(speed);
    // <5>
    // position wasn't initially changed by these methodes
    // doing that here
    m_posX = newPosX;
    m_posY = newPosY;
}

void robot::moveRobot(float degree, unsigned int speed)
{
	turnRobot(degree);
	std::cout << "Roboter bewegt sich mit " << speed << "% seiner Maximalgeschwindigkeit \n";
	std::cout << "Warnung: keine Geschwindigkeitsbegrenzung -> diese Funktion sollte nie aufgerufen werden!";
	std::cout << "Wenn sie doch aufgerufen wird, ist dies ein Fehler!";
}

// <1>
// removed `const` specifier of `int speed`
void robot::moveRobot(int speed)
{
	if (speed > 100) speed = 100;
	if (speed < 0) speed = 0;
	std::cout << "Roboter bewegt sich mit " << speed << "% seiner Maximalgeschwindigkeit \n";
}

void robot::turnRobot(const float degree)
{
	float newDegree = degree + m_bodyDirection;
	while(newDegree > 360)
	{
		newDegree -= 360;
	}
	m_bodyDirection = newDegree;
}

bool robot::locateTarget()
{
	if (!m_cameraCalibrated) return false;
    //changed `m_posX` to `getPosX()`
	float targetPosX = m_currentTarget->getPosX();
	float targetPosY;
	float direction;
	const float pi = 3.14f;
    //changed `m_posY` to `getPosY()`
	targetPosY = m_currentTarget->getPosY();
	direction = (atan2(targetPosY, targetPosX) + pi) / (2*pi) * 360;
	if ((direction - m_headDirection < 45) || (direction - m_headDirection > 45))
		return false;

	return true;
}

void robot::calibrateCamera()
{
	std::cout << "Kamera ist einsatzbereit \n";
	m_cameraCalibrated = true;
}

void robot::addHand()
{
	if (m_handCount >= 8) return;
	m_handCount++;
}

void robot::setTarget(target* newTarget)
{
	m_currentTarget = newTarget;
}

void robot::printStatusCode() const
{
	std::cout << "Aktueller Status: " << m_status << "\n";
	std::cout << "Alles ausser dem Status 1234567890 ist ein Fehler! \n";
}

void robot::moveFinger1()
{
	std::cout << "Bewege Finger1." << "\n";
}

void robot::moveFinger2()
{
	std::cout << "Bewege Finger2." << "\n";
}

// <3>
// Implementation of public methodes for retreiving position
const float robot::getPosX() const
{
	return m_posX;
}

const float robot::getPosY() const
{
	return m_posY;
}


// TODO:
// What is this operator supposed to do?
// In the case `robor c3po = hal + r2d2;` it adds the position of r2d2 to the
// postion of hal and returns a pointer to hal
// Is that the desiered behaviour?
robot robot::operator+(robot & rob)
{
	this->m_posX += rob.m_posX;
	this->m_posY += rob.m_posY;
	return *this;
}

int main()
{
	robot hal;
	robot r2d2;
    // <4>
    // set position of robots using `moveRobot()`
    hal.moveRobot(15, 10);
    r2d2.moveRobot(5, 10);
	robot c3po = hal + r2d2;
    // <3>
    // replaced accessing private attributes with calling public method to
    // retreive position
	std::cout << "c3po:" << c3po.getPosX() << "\n";
	std::cout << "hal:" << hal.getPosX() << "\n";
    std::cout << "r2d2:" << r2d2.getPosX() << "\n";
	hal.moveFinger1();
	hal.calibrateCamera();
	hal.moveRobot(10,10);
	target ball(15,15);
	hal.setTarget(&ball);
	hal.locateTarget();
	hal.printStatusCode();
	getchar();
    return 0;
}
