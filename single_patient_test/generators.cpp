
#include <random>
#include <ctime>
#include "generators.h"


//Generators attempt to simulate vitals signs for testing purposes

Generators::Generators()
{}

std::string Generators::time_gen()
{
	time_t now = time(0); // Get current time
	char buffer[26];

	if (ctime_s(buffer, sizeof(buffer), &now) == 0) {
		return buffer;
	}
	else
	{
		std::string error = "Error recording time.";
		return error;
	}
}