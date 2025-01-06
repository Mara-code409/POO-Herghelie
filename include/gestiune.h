#ifndef HERGHELIE_GESTIUNE_H
#define HERGHELIE_GESTIUNE_H

#include <vector>
#include <stdexcept>

template<typename T>
class Gestiune {
private:
    std::vector<T*> items;
    unsigned int capacitateMaxima;
    static int numarTotalGestiuni;

public:
    Gestiune(unsigned int capacitate);
    void adauga(T* item);
    void sterge(const std::string& nume);
    T* gaseste(const std::string& nume) const;
    static int getNumarTotalGestiuni();
    ~Gestiune();
};

#endif
