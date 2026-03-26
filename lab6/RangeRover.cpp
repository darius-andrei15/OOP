#include "RangeRover.h"
using namespace std;

double RangeRover::FuelCapacity() const {
    return 30.00;
}

double RangeRover::FuelCost() const {
    return 30.00;
}

double RangeRover::AverageSpeed(Weather weather) const {
    if (weather==Weather::Rain) return 30.00;
    if (weather==Weather::Snow) return 50.00;
    if (weather==Weather::Sunny) return 70.00;
}

const char* RangeRover::Name() const {
    return "RangeRover";
}
