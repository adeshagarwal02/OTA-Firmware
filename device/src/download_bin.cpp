#include "computeSha256.hpp"
#include "http_download.hpp"


bool download_bin(void) {
    const char* url = "http://192.168.29.87:8000/firmware/firmware_v2.bin";
    const char* outfilename = "../bin/firmware.bin";
    
    if(download(url,outfilename)){
	    std::cout << "Bin file downloaded successfully" << std::endl;
	    std::cout << "SHA256sum:" << computeSHA256(outfilename)<<std::endl;

    }
    return true;
}
