#ifndef COMPUTESHA256_HPP
#define COMPUTESHA256_HPP

#include <openssl/sha.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

std::string computeSHA256(const std::string &); 

#endif
