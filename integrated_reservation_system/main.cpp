#include <iostream>
#include "Reservation_Airplane.h"

using namespace std;

int main() 
{
	Reservation_Airplane* interface = new Reservation_Airplane();
	interface->run();
	return 0;
}
