#include "../header/http_download.hpp"
#include "../header/read_file.hpp"

bool check_update(void) {
    const char* url = "http://192.168.29.87:8000/version.json"; // Replace with your URL
    const char* outfilename = "../downloads/version.json"; // Replace with your desired local filename
    
    if(download(url,outfilename)){
	    std::cout << "File downloaded successfully (if no errors reported)." << std::endl;
	    std::string new_version {"../downloads/version.json"};
	    std::string present_version {"../manifest.json"};
	    present_version = read_file(present_version);
	    new_version = read_file(new_version);
	    if (present_version == new_version){
		    std::cout<<"No new update"<<std::endl;
		    return false;

	    }
	    else{
		    std::cout << "New update is present"<<std::endl;
	    }
    }
    return true;
}
