#include "write_file.hpp"
void write_file(const std::string file_path, const std::string data){
	std::fstream file;
	file.out(file_path);
	file<<data<<std::endl;

}
