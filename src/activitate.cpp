#include "activitate.h"

Activitate::Activitate()
    : nume(""), data(""), ora(""), durata(0), capacitateMaxima(0) {}

Activitate::Activitate(const std::string& nume, const std::string& data, const std::string& ora,
                       int durata, int capacitateMaxima)
    : nume(nume), data(data), ora(ora), durata(durata), capacitateMaxima(capacitateMaxima) {}

Activitate::Activitate(const Activitate& other)
    : nume(other.nume), data(other.data), ora(other.ora),
      durata(other.durata), capacitateMaxima(other.capacitateMaxima) {}

const std::string& Activitate::getNume() const { return nume; }
const std::string& Activitate::getData() const { return data; }
const std::string& Activitate::getOra() const { return ora; }
int Activitate::getDurata() const { return durata; }
int Activitate::getCapacitate() const { return capacitateMaxima; }

std::ostream& operator<<(std::ostream& out, const Activitate& act) {
    out << "Nume: " << act.nume
        << "\nData: " << act.data
        << "\nOra: " << act.ora
        << "\nDurata: " << act.durata << " minute"
        << "\nCapacitate maxima: " << act.capacitateMaxima << " cai";
    return out;
}

std::istream& operator>>(std::istream& in, Activitate& act) {
    std::cout << "Nume: ";
    std::getline(in >> std::ws, act.nume);

    std::cout << "Data (YYYY-MM-DD): ";
    std::getline(in >> std::ws, act.data);

    std::cout << "Ora (HH:MM): ";
    std::getline(in >> std::ws, act.ora);

    std::cout << "Durata (minute): ";
    in >> act.durata;

    std::cout << "Capacitate maxima: ";
    in >> act.capacitateMaxima;

    return in;
}
