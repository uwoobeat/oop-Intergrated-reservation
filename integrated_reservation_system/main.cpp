#include <iostream>
#include "Reservation_Airplane.h"

using namespace std;

int main() 
{
	Reservation_Airplane *airplane_interface = new Reservation_Airplane();
	airplane_interface->run();

	return 0;
}
