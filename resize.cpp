#include <iostream>
#include <unistd.h>
#include <string>
#include <sstream>
#include <filesystem>
#include "CImg.h"

namespace fs = std::filesystem;
using namespace cimg_library;

int printInfo(const char* const filename);
int resize(const char* const filename, unsigned int width, unsigned int height);

inline bool fileExists(const std::string& name);

int main(int argc, char *argv[])
{
	int iflag { 0 };
	int rflag { 0 };
	int index {};
	int c {};
	char* rvalue = nullptr;
	
	opterr = 0;

	while ((c = getopt (argc, argv, "ir:")) != -1) {
		if (c == 'i') {
			iflag = 1;
		}
	}

	if (iflag) {
		for (index = optind; index < argc; ++index) {
			printInfo(argv[index]);
		}
	} else if (rflag) {
		rvalue = optarg;
		int sizeX {};
		int sizeY {};
		for (index = optind; index < argc; ++index) {
			resize(argv[index], sizeX, sizeY);
		}
	}

	return EXIT_SUCCESS;
}

int printInfo(const char* const filename)
{
	std::string str_filename {};
	std::stringstream stream;
	fs::path filePath = filename;

	stream << filename;
	stream >> str_filename;
	if (!fileExists(str_filename)) {
		std::cerr << filename << ": No such file" << std::endl;
		return EXIT_FAILURE;
	} 

	CImg<unsigned char> image(filename);

	struct stat buffer;
	stat (static_cast<const char*>(filename), &buffer);

	static const char* pxtype = image.pixel_type();
	off_t fileSize = buffer.st_size;
	filePath = fs::absolute(filePath);
	fs::path extension = filePath.extension();
	int width = image.width();
	int height = image.height();
	int depth = image.depth();
	int spectrum = image.spectrum();


	std::cout << "File Name  : " << filename << std::endl;
	std::cout << "Location   : " << filePath << std::endl;
	std::cout << "Extension  : " << extension << std::endl;
	std::cout << "Size       : " << fileSize << " byte" << std::endl;
	std::cout << "Pixel Type : " << pxtype << std::endl;
	std::cout << "Width      : " << width << "px" << std::endl;
	std::cout << "Height     : " << height << "px" << std::endl;
	std::cout << "Dimension  : " << width << "x" << height << std::endl;
	std::cout << "Depth      : " << depth << std::endl;
	std::cout << "Spectrum   : " << depth << std::endl;
	std::cout << std::endl;

	return EXIT_SUCCESS;
}

int resize(const char* const filename, unsigned int width, unsigned int height)
{
	CImg<unsigned char> img(filename);
	img.resize(width, height);
	img.save("output.jpg");

	return EXIT_SUCCESS;
}

inline bool
fileExists(const std::string& name)
{
	struct stat buffer;
	return (stat (name.c_str(), &buffer) == 0);
}