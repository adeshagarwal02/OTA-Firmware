#include "read_file.hpp"

std::string read_file(std::string file_name)
{
	std::string  data{};
	std::fstream fp;
	fp.open(file_name);
	std::getline(fp,data);
	fp.close();
	std::cout<<data<<std::endl;
	return data;
}
