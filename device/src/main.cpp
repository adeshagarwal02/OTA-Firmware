//#include "../header/http_download.hpp"
//#include "../header/read_file.hpp"
#include "../header/check_update.hpp"
#include "../header/download_bin.hpp"
int main() {
    if(check_update()){
	    download_bin();
    }
    return 0;
}
