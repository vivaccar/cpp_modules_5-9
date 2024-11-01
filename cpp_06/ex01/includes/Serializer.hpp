#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

struct Data;

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer &other);
        ~Serializer();

        Serializer &operator=(const Serializer &other);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif