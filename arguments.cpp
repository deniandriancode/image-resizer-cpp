#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[])
{
	/* get i flag */
	int iflag { 0 };
	int rflag { 0 };
	int index {};
	int c {};
	char* cvalue = nullptr;
	
	opterr = 0;

	while ((c = getopt (argc, argv, "ir:")) != -1) {
		switch (c) {
			case 'i':
				iflag = 1;
				break;
			case 'r':
				cvalue = optarg;
				break;
		}
	}

	if (iflag) {
		for (index = optind; index < argc; ++index) {
			std::cout << argv[index] << " has the following information." << std::endl;
		}
	} else {
		std::cout << cvalue << std::endl;
		std::cout << argv[optind] << std::endl;
	}

	return 0;
}
