/*
 * =====================================================================================
 *
 *       Filename:  wine.hpp
 *
 *    Description:  my description of wine class
 *
 *        Version:  1.0
 *        Created:  12/16/2018 12:57:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alex Klim
 *   Organization:  home
 *
 * =====================================================================================
 */

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
    std::string& label() const;
    int sum() const;
    void show() const;
    void showAge() const;
private:
    using ArrayIntT = std::valarray<int>;
    using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;
    std::string label_;
    PairArrayT year_bottles_;
    PairArrayT age_bottles_;
};
