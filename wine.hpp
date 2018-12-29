#include <iostream>
#include <utility>
#include <valarray>
#include <vector>

class Wine {
public:
    Wine();
    Wine(const char* l, int y, const int yr[], const int bot[]);
    Wine(const char* l, int y);

    void getBottles();
    void getAge();
    std::string label() const;
    int sum() const;
    void show() const;
    void showAge() const;
private:
    using ArrayIntT = std::valarray<int>;
    using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;
    std::string label_;
    PairArrayT year_bottles_;
    ArrayIntT age_bottles_;
};
