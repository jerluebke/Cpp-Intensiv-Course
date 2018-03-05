#include "Image.h"


int main() {


	Image image; // leeres Bild

	image.read("Lena.PGM");

	std::cout << image.get_height() <<  " * " << image.get_width() << std::endl;

	image.fillCircle(100, 100, 80, 510);
	image.fillTriangle(200, 200, 20, 80, 0);
	image.fill('200');
	image.write("Lena_3.PGM");

	system("pause");
	
	return 0;
}
