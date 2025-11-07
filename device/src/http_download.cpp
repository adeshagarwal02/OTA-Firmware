#include "../header/http_download.hpp"
// Callback function to write received data to a file
size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

bool download(const char* url, const char* outfilename){
    CURL* curl;
    FILE* fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename, "wb"); // Open file in binary write mode
        if (fp == NULL) {
            std::cerr << "Error opening file for writing." << std::endl;
            return false;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); // Set the write callback
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp); // Pass the file pointer to the callback

        res = curl_easy_perform(curl); // Perform the download
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
	    return false;
        }

        curl_easy_cleanup(curl); // Clean up libcurl resources
        fclose(fp); // Close the file
    } else {
        std::cerr << "Error initializing libcurl." << std::endl;
        return false;
    }
    return true;
}
