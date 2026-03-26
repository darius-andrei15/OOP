#include "Seat.h"
using namespace std;

double Seat::FuelCapacity() const {
    return 80.00;
}

double Seat::FuelCost() const {
    return 50.00;
}

double Seat::AverageSpeed(Weather weather) const {
    if (weather==Weather::Rain) return 80.00;
    if (weather==Weather::Snow) return 50.00;
    if (weather==Weather::Sunny) return 60.00;
}

const char* Seat::Name() const {
    return "Seat";
}
