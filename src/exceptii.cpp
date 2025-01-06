#include "exceptii.h"

ExceptieHerghelie::ExceptieHerghelie(const std::string& mesaj) : mesaj(mesaj) {}

const char* ExceptieHerghelie::what() const noexcept {
    return mesaj.c_str();
}

ExceptieCal::ExceptieCal(const std::string& mesaj)
    : ExceptieHerghelie("Eroare cal: " + mesaj) {}

ExceptieStareCal::ExceptieStareCal(const std::string& mesaj)
    : ExceptieCal("Stare invalida: " + mesaj) {}

ExceptieActivitate::ExceptieActivitate(const std::string& mesaj)
    : ExceptieHerghelie("Eroare activitate: " + mesaj) {}

ExceptieCapacitate::ExceptieCapacitate(const std::string& mesaj)
    : ExceptieActivitate("Capacitate depasita: " + mesaj) {}
