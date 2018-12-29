#include <valarray>
#include <utility>
#include <string>

class WinePrv : private std::string,
                private std::pair<std::valarray<int>, std::valarray<int>>,
                private std::valarray<int> {
public:
    WinePrv();
    WinePrv(const char* l, int y, const int yr[], const int bot[]);
    WinePrv(const char* l, int y);

    void getBottles();
    std::string label() const;
    int sum() const;
    void show() const;
    void showAge() const;
private:
    using ArrayIntT = std::valarray<int>;
    using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;
    static constexpr auto kDefaultName = "Default";
};
