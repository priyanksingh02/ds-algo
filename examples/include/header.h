#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <type_traits>
#include <utility>
#include <random>
// USAGE
// debug() << imie(v) imie(vp) imie(m);
// std:generate(begin(numbers),end(numbers), addon::rn(1, 100));
// std::generate_n(std::back_inserter(numbers), 100, addon::rn(1, 100));

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    std::enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(std::cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { std::cerr << std::endl;}
eni(!=) std::cerr << std::boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(std::pair <b,c > d) {
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
sim dor (const c&) { ris;}
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


namespace addon {
    // random number
    class rn {
        public:
        rn(int low, int high)
            : random_engine_{std::random_device {}()}
            , distribution_{low, high}
        { }

        int operator()() {
            return distribution_(random_engine_);
        }
        private:
        std::mt19937 random_engine_;
        std::uniform_int_distribution<int> distribution_;
    };
}

#endif //header.h
