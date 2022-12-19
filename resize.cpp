#include <iostream>
#include <unistd.h>
#include <string>
#include <sstream>
#include <vector>
#include "resize.hpp"

int main(int argc, char *argv[])
{
	int iflag { 0 };
	unsigned int index {};
	int c {};
	char* rvalue { nullptr };
	char* output { nullptr };
	
	opterr = 0;

    if (argc == 1) {
            std::cerr << PROGNAME << ": file argument required" << std::endl;
            return EXIT_FAILURE;
    }

	while ((c = getopt (argc, argv, "ir:o:")) != -1) {
		switch (c) {
			case 'i':
				iflag = 1;
				break;
			case 'r':
				rvalue = optarg;
				break;
			case 'o':
				output = optarg;
				break;
		}
	}

	if (iflag) {
		for (index = optind; index < argc; ++index) {
			printInfo(argv[index]);
		}
	} else if (rvalue != nullptr) {
		std::string sizeNew(rvalue);
		std::stringstream ss(sizeNew);
		std::vector<std::string> tokens;
		std::string tmp;

		while (std::getline(ss, tmp, 'x')) {
			tokens.push_back(tmp);
		}

		int sizeX { std::stoi(tokens.at(0)) };
		int sizeY { std::stoi(tokens.at(1)) };

        resize(argv[optind], output, sizeX, sizeY);
	}

	return EXIT_SUCCESS;
}

