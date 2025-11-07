#include "check_update.hpp"
#include "download_bin.hpp"
int main() {
    if(check_update()){
	    download_bin();
    }
    return 0;
}
