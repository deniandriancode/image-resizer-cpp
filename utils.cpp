#include <iostream>
#include <string>
#include <filesystem>
#include "CImg.h"
#include "resize.hpp"

namespace fs = std::filesystem;
using namespace cimg_library;

int printInfo(const char* const filename)
{
	std::string str_filename {};
	std::stringstream stream;
	fs::path filePath = filename;
	struct stat buffer;

	stream << filename;
	stream >> str_filename;
	if (!fileExists(str_filename)) {
		std::cerr << filename << ": No such file" << std::endl;
		return EXIT_FAILURE;
	} 

	CImg<unsigned char> image(filename);

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
	std::cout << "Size       : " << fileSize / 1000 << " KB " << "(" << fileSize << " byte)" << std::endl;
	std::cout << "Pixel Type : " << pxtype << std::endl;
	std::cout << "Width      : " << width << "px" << std::endl;
	std::cout << "Height     : " << height << "px" << std::endl;
	std::cout << "Dimension  : " << width << "x" << height << " pixel" << std::endl;
	std::cout << "Depth      : " << depth << std::endl;
	std::cout << "Spectrum   : " << depth << std::endl;
	std::cout << std::endl;

	return EXIT_SUCCESS;
}

int resize(const char* const filename, char* output, unsigned int width, unsigned int height)
{
	CImg<unsigned char> img(filename);
	img.resize(width, height);
    img.blur(0.65f, 0.65f, 1.0f);
	img.save(output);

	return EXIT_SUCCESS;
}

inline bool
fileExists(const std::string& name)
{
	struct stat buffer;
	return (stat (name.c_str(), &buffer) == 0);
}
