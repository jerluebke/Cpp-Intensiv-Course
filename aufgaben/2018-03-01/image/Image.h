#include <string.h>
#include <algorithm>
#include<iostream>
#include "pgmIO.h"
#include <cmath>


class Image{

public:

	Image(): m_width(0), m_height(0), mp_data(nullptr) {}
	~Image() { delete[] mp_data; }

	 void resize(unsigned int width, unsigned int height)
	{
		m_width = width;
		m_height = height;
		delete[] mp_data;
		mp_data = new unsigned char[m_width * m_height];
	}

	void release()
	{
		delete[] mp_data;
		mp_data = nullptr;
		m_width = m_height = 0;
	}

	friend void swap(Image &lhs, Image &rhs) noexcept;

	Image(const Image &rhs) : m_width(rhs.m_width), m_height(rhs.m_height)
	{
		mp_data = new unsigned char[m_width*m_height];
		memcpy(mp_data, rhs.mp_data, m_width*m_height * sizeof(unsigned char));
	}

	Image& operator=(Image rhs)
	{
		swap(*this, rhs);
		return *this;
	}

	void fill(unsigned char value)
	{
		unsigned int sizeOfData = m_width * m_height;
		for (unsigned char* filler = mp_data; filler != mp_data + sizeOfData; filler++)
			*filler = value;
	}

	void set(unsigned int xPos, unsigned int yPos, unsigned char value)
	{
		if (m_isInImage(xPos, yPos))
			mp_data[m_index(xPos, yPos)] = value;
	}

	unsigned int get_width() {
		return m_width;
	}
	unsigned int get_height() {
		return m_height;
	}

	
	void fillRectangle(unsigned int x_1, unsigned int x_2, unsigned int y_1, unsigned int y_2, unsigned char v) 
	{
		
		unsigned int x_obenlinks ;
		unsigned int x_untenrechts;
		unsigned int y_obenlinks ;
		unsigned int y_untenrechts;

		if (x_1 < x_2) {

			  x_obenlinks = x_1;
			  x_untenrechts = x_2;
		}
		else {
			 x_obenlinks = x_2;
			 x_untenrechts = x_1;
		}
		if (y_1 < y_2) {

			 y_obenlinks = y_1;
			  y_untenrechts = y_2;
		}
		else {
			 y_obenlinks = y_2;
			  y_untenrechts = y_1;
		}

		if (m_isInImage(x_obenlinks, y_obenlinks) && m_isInImage(x_untenrechts, y_untenrechts) && m_isVvalid(v)) {


			unsigned int charPos = m_index(x_obenlinks, y_obenlinks); // Start an Eckpunkt oben links

			for (int y = 0; y <= (y_untenrechts - y_obenlinks); ++y) {

				charPos = m_index(x_obenlinks, y_obenlinks + y);

				for (unsigned char* filler = &mp_data[charPos]; filler <= &mp_data[charPos] + x_untenrechts- x_obenlinks; ++filler) {

					*filler = v;
				}
			}
		}
			
	}
		
	void fillCircle(unsigned int xCenter, unsigned int yCenter,
		unsigned int radius, unsigned char value)
	{
		unsigned int xMin = xCenter - radius;
		unsigned int xMax = xCenter + radius;
		unsigned int yMin = yCenter - radius;
		unsigned int yMax = yCenter + radius;
		if (m_isInImage(xMin, yCenter) && m_isInImage(xMax, yCenter)
			&& m_isInImage(xCenter, yMin) && m_isInImage(xCenter, yMin) && m_isVvalid(value))
		{
			for (int xRunner = xMin; xRunner <= xMax; xRunner++)
			{
				for (int yRunner = yMin; yRunner <= yMax; yRunner++)
				{
					unsigned int xCircle = (unsigned int)abs((int)xCenter - xRunner);
					unsigned int yCircle = (unsigned int)abs((int)yCenter - yRunner);
					if (xCircle*xCircle + yCircle * yCircle <= radius*radius)
						mp_data[m_index(xRunner, yRunner)] = value;
				}
			}
		}
	}


	void fillTriangle(unsigned int x_links, unsigned int y_links, signed int height, unsigned int width, unsigned char v)
	{
		if (m_isInImage(x_links, y_links) && m_isInImage(x_links + width / 2, y_links - height) && m_isInImage(x_links + width, y_links) && m_isVvalid(v)) {

			const float relation = abs(width / (2.0 * height)); //fuer Strahlensatz
			unsigned int actual_halfwidth = 0; // Breite in Hochpunkt
			unsigned int actual_y = y_links - height; // Start in Hochpunkt
			unsigned int actual_x = x_links + width / 2;
			unsigned int y_height = y_links - height;
			int actual_height = actual_y - y_height;

			unsigned int charPos = m_index(actual_x, actual_y); // Start beim Hochpunkt
			//mp_data[charPos] = v; //setze Spitze

			for (int h = 1; h <= abs(height); h++) {

				if (height < 0) {
					actual_y--;
				}
				else {
					actual_y++;
				}
				actual_height = (actual_y - y_height);
				actual_halfwidth = relation * abs(actual_height);
				actual_x = x_links + (width/2 - actual_halfwidth);

				charPos = m_index( actual_x , actual_y);

				for (unsigned char* filler = &mp_data[charPos]; filler <= &mp_data[charPos] + 2*actual_halfwidth; ++filler) {

					*filler = v;
				}
			}
			

		}
		else {
			std::cout << " gewaehltes Dreieck nicht in Bild!" << std::endl;
		}
	}

	void read(const char* filename) {

		readPGM(filename, &mp_data, &m_width, &m_height);
	}
	
	void write(const char* filename) {

		writePGM(filename, mp_data, m_width, m_height);
	}


private:

	unsigned int m_width;
	unsigned int m_height;
	unsigned char * mp_data;

	unsigned int m_index(unsigned int xPos, unsigned int yPos) const {
		return (yPos * m_width + xPos);
	}

	bool m_isInImage(unsigned int x, unsigned int y)
	{
		if (x < m_width && y < m_height)
		{
			return true;
		}

			std::cout << "Gewuenschte Flaeche ist nicht im Bild" << std::endl;
			return false;
			
	}

	bool m_isVvalid(unsigned char v)
	{
		//unsigned int x = v - '0';
		unsigned int x = v;

		if (x > 255)
		{
			std::cout << "Kein gueltiger Wert v!";
			return false;
		}
		
		return true;
	}
};

void swap(Image &lhs, Image &rhs) noexcept
{
	using std::swap;
	swap(lhs.m_width, rhs.m_width);
	swap(lhs.m_height, rhs.m_height);
	swap(lhs.mp_data, rhs.mp_data);

}




