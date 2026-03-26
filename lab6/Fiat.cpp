#include "Fiat.h"
using namespace std;

double Fiat::FuelCapacity() const {
    return 90.00;
}

double Fiat::FuelCost() const {
    return 90.00;
}

double Fiat::AverageSpeed(Weather weather) const {
    if (weather==Weather::Rain) return 90.00;
    if (weather==Weather::Snow) return 80.00;
    if (weather==Weather::Sunny) return 70.00;
}

const char* Fiat::Name() const {
    return "Fiat";
}
