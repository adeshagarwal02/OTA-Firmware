#include "computeSha256.hpp"

std::string computeSHA256(const std::string &filename) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);

    std::ifstream file(filename, std::ifstream::binary);
    if (!file) {
        throw std::runtime_error("Unable to open file for hashing: " + filename);
    }

    const size_t bufferSize = 1 << 12; // 4KB buffer
    char *buffer = new char[bufferSize];
    while (file.good()) {
        file.read(buffer, bufferSize);
        SHA256_Update(&sha256, buffer, file.gcount());
    }
    file.close();
    delete[] buffer;

    SHA256_Final(hash, &sha256);

    std::ostringstream result;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        result << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return result.str();
}
