#include "Volvo.h"
using namespace std;

double Volvo::FuelCapacity() const {
    return 7.0;
}
double Volvo::FuelCost() const {
    return 7.0;
}
double Volvo::AverageSpeed(Weather weather) const {
    if (weather==Weather::Rain) return 40.00;
    if (weather==Weather::Sunny) return 20.00;
    if (weather==Weather::Snow) return 70.00;
}
const char* Volvo::Name() const {
    return "Volvo";
}

