#ifndef HERGHELIE_EXCEPTII_H
#define HERGHELIE_EXCEPTII_H

#include <exception>
#include <string>

class ExceptieHerghelie : public std::exception {
protected:
    std::string mesaj;
public:
    ExceptieHerghelie(const std::string& mesaj);
    const char* what() const noexcept override;
};

class ExceptieCal : public ExceptieHerghelie {
public:
    ExceptieCal(const std::string& mesaj);
};

class ExceptieStareCal : public ExceptieCal {
public:
    ExceptieStareCal(const std::string& mesaj);
};

class ExceptieActivitate : public ExceptieHerghelie {
public:
    ExceptieActivitate(const std::string& mesaj);
};

class ExceptieCapacitate : public ExceptieActivitate {
public:
    ExceptieCapacitate(const std::string& mesaj);
};

#endif
