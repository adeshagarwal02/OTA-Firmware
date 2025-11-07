#include "../header/http_download.hpp"
//#include "../header/read_file.hpp"

bool download_bin(void) {
    const char* url = "http://192.168.29.87:8000/firmware/firmware_v2.bin"; // Replace with your URL
    const char* outfilename = "../bin/firmware.bin"; // Replace with your desired local filename
    
    if(download(url,outfilename)){
	    std::cout << "Bin file downloaded successfully" << std::endl;
    }
    return true;
}
