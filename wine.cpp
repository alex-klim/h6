#include "wine.hpp"

Wine::Wine() : label_("Default") {}

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) {
    if (l) {
        label_ = l;
    } else {
        label_ = "Default";
    }
    year_bottles_.first.resize(y);
    year_bottles_.second.resize(y);
    age_bottles_.resize(y);

    for (int i = 0; i < y; i++) {
        year_bottles_.first[i] = yr[i];
        year_bottles_.second[i] = bot[i];
    }
}

Wine::Wine(const char* l, int y) {
    if (l) {
        label_ = l;
    } else {
        label_ = "Default";
    }
    year_bottles_.first.resize(y);
    year_bottles_.second.resize(y);
    age_bottles_.resize(y);
}

void Wine::getBottles() {
    for (size_t i = 0; i < std::get<0>(year_bottles_).size(); i++) {
        int temp{0};
        std::cout << "Enter year of bottling: ";
        std::cin >> temp;
        year_bottles_.first[i] = temp;
        std::cout << "Enter number of bottles for " << temp << " year: ";
        std::cin >> temp;
        year_bottles_.second[i] = temp;
    }
}

void Wine::getAge() {
    for (size_t i = 0; i < age_bottles_.size(); i++) {
        int temp{0};
        std::cout << "Enter age of " << std::get<0>(year_bottles_)[i] << " year bottles: ";
        std::cin >> temp;
        age_bottles_[i] = temp;
    }
}

std::string Wine::label() const {
    return label_;
}

int Wine::sum() const {
    int sum = 0;
    for (auto bottles : std::get<1>(year_bottles_)) {
        sum += bottles;
    }
    return sum;
}

void Wine::show() const {
    size_t i = 0;
    while (i < std::get<0>(year_bottles_).size()) {
        std::cout << "{" << label_ << "}: "
            << std::get<1>(year_bottles_)[i] << " bottles of "
            << std::get<0>(year_bottles_)[i] << " year\n";
        i++;
    }
}

void Wine::showAge() const {
    for (size_t i = 0; i < age_bottles_.size(); i++) {
        std::cout << "{" << label_ << "}: "
            << std::get<0>(year_bottles_)[i] << " year wine is "
            << age_bottles_[i] << " years aged\n";
    }
}
