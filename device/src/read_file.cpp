#include "read_file.hpp"

std::string read_file(std::string file_name)
{
	std::string version {};
	std::fstream fp;
	fp.open(file_name);
	std::getline(fp,version);
	fp.close();
	std::cout<<version<<std::endl;
	return version;
}
