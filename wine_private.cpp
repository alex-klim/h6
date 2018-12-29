#include "wine_private.hpp"

#include <iostream>

WinePrv::WinePrv() : std::string(kDefaultName) {

}

WinePrv::WinePrv(const char* l, int y, const int yr[], const int bot[]) :
    std::string(l),
    PairArrayT(std::make_pair(ArrayIntT(yr, y), ArrayIntT(bot, y))),
    ArrayIntT(y) 
{}

WinePrv::WinePrv(const char* l, int y) :
    std::string(l),
    PairArrayT(std::make_pair(ArrayIntT(y), ArrayIntT(y))),
    ArrayIntT(y)
{}

void WinePrv::getBottles () {
    for (size_t i = 0; i < std::get<0>(*this).size(); i++) {
        int temp{0};
        std::cout << "Enter year of bottling: ";
        std::cin >> temp;
        this->first[i] = temp;
        std::cout << "Enter number of bottles for " << temp << " year: ";
        std::cin >> temp;
        this->second[i] = temp;
    }
}

std::string WinePrv::label() const {
    return std::string(*this);
}

int WinePrv::sum() const {
    int sum = 0;
    for (size_t i = 0; i < std::get<0>(*this).size(); i++) {
        sum += this->second[i];
    }
    return sum;
}

void WinePrv::show() const {
    for (size_t i = 0; i < std::get<0>(*this).size(); i++) {
        std::cout << "{" << (std::string)*this << "}: " << this->second[i] << " bottles of " << this->first[i] << " year.\n";
    }
}

void WinePrv::showAge() const {

}
