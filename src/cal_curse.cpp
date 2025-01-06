#include "cal_curse.h"
#include <algorithm>
#include <numeric>

CalCurse::CalCurse() : Cal(), numarCurse(0), victorii(0), vitezaMaxima(0.0) {}

CalCurse::CalCurse(const std::string& nume, const std::string& rasa, int varsta,
                   const std::string& stare, double greutate, char gen, bool pedigree,
                   int numarCurse, int victorii, double vitezaMaxima)
    : Cal(nume, rasa, varsta, stare, greutate, gen, pedigree),
      numarCurse(numarCurse), victorii(victorii), vitezaMaxima(vitezaMaxima) {}

std::string CalCurse::getTip() const {
    return "Cal de curse";
}

void CalCurse::adaugaCursa(bool castigata, double timp, const std::string& adversar) {
    numarCurse++;
    if (castigata) victorii++;

    timpiiCurse.push_back(timp);

    adversari.push_back(adversar);
    if (adversari.size() > 5) {  // Pãstrãm doar ultimii 5 adversari
        adversari.pop_front();
    }
}

double CalCurse::getRataVictorii() const {
    if (numarCurse == 0) return 0.0;
    return (double)victorii / numarCurse * 100;
}

double CalCurse::getTimeMediu() const {
    if (timpiiCurse.empty()) return 0.0;
    return std::accumulate(timpiiCurse.begin(), timpiiCurse.end(), 0.0) / timpiiCurse.size();
}

std::vector<double> CalCurse::getTopTimpi(int n) const {
    std::vector<double> timpi = timpiiCurse;
    std::sort(timpi.begin(), timpi.end());
    if (n > timpi.size()) n = timpi.size();
    timpi.resize(n);
    return timpi;
}

std::ostream& operator<<(std::ostream& out, const CalCurse& cal) {
    out << static_cast<const Cal&>(cal)
        << "\nNumar curse: " << cal.numarCurse
        << "\nVictorii: " << cal.victorii
        << "\nRatã victorii: " << cal.getRataVictorii() << "%"
        << "\nVitezã maxima: " << cal.vitezaMaxima << " km/h"
        << "\nUltimii adversari: ";

    for (const auto& adversar : cal.adversari) {
        out << adversar << ", ";
    }

    out << "\nTimp mediu: " << cal.getTimeMediu() << " minute";
    return out;
}

std::istream& operator>>(std::istream& in, CalCurse& cal) {
    in >> static_cast<Cal&>(cal);

    std::cout << "Numar curse: ";
    in >> cal.numarCurse;

    std::cout << "Numar victorii: ";
    in >> cal.victorii;

    std::cout << "Viteza maxima (km/h): ";
    in >> cal.vitezaMaxima;

    return in;
}
