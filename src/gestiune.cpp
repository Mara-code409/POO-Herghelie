#include "gestiune.h"
#include "cal.h"
#include "activitate.h"
#include <algorithm>

template<typename T>
int Gestiune<T>::numarTotalGestiuni = 0;

template<typename T>
Gestiune<T>::Gestiune(unsigned int capacitate) : capacitateMaxima(capacitate) {
    numarTotalGestiuni++;
}

template<typename T>
void Gestiune<T>::adauga(T* item) {
    if (items.size() >= capacitateMaxima) {
        throw std::runtime_error("Capacitate maxima atinsa");
    }
    items.push_back(item);
}

template<typename T>
void Gestiune<T>::sterge(const std::string& nume) {
    auto it = std::find_if(items.begin(), items.end(),
        [&nume](const T* item) { return item->getNume() == nume; });
    if (it != items.end()) {
        delete *it;
        items.erase(it);
    }
}

template<typename T>
T* Gestiune<T>::gaseste(const std::string& nume) const {
    auto it = std::find_if(items.begin(), items.end(),
        [&nume](const T* item) { return item->getNume() == nume; });
    return (it != items.end()) ? *it : nullptr;
}

template<typename T>
int Gestiune<T>::getNumarTotalGestiuni() {
    return numarTotalGestiuni;
}

template<typename T>
Gestiune<T>::~Gestiune() {
    for (auto item : items) {
        delete item;
    }
    numarTotalGestiuni--;
}

// Instanțieri explicite
template class Gestiune<Cal>;
template class Gestiune<Activitate>;
