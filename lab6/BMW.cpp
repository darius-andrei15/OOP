#include "BMW.h"
using namespace std;

double BMW::FuelCapacity() const {
    return 3.0;
}

double BMW::FuelCost() const {
    return 4.0;
}

double BMW::AverageSpeed(Weather weather) const {
    if (weather==Weather::Rain) return 20.00;
    if (weather==Weather::Sunny) return 40.00;
    if (weather==Weather::Snow) return 60.00;
}

const char * BMW::Name() const {
    return "BMW";
}
