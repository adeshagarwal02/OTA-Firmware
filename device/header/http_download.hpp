
#ifndef HTTPDOWN
#define HTTPDOWN

#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>

size_t write_data(void *,size_t,size_t,FILE *);
bool download (const char*, const char*);

#endif
