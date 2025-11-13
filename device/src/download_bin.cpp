#include "computeSha256.hpp"
#include "http_download.hpp"
#include "read_file.hpp"

bool download_bin(void) {
    const char* url = "http://192.168.29.87:8000/firmware/firmware_v2.bin";
    const char* outfilename = "../bin/firmware.bin";
    const char* newVersion = "../downloads/version.json";
    
    if(download(url,outfilename)){
	    std::cout << "Bin file downloaded successfully checking for checksum" << std::endl;
	    std::string checksum = computeSHA256(outfilename);
	   // std::cout << "SHA256sum:" << checksum <<std::endl;
	    std::string new_version = read_file(newVersion);
	    if(new_version == checksum){
		    std::cout<<"Keep the bin file"<<std::endl;
	    }
	    else
	    {
		    std::cout<<"Remove the downloaded file and re-download it"<<std::endl;
	    }
    }
    return true;
}
