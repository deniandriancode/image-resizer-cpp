#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[])
{
	/* get i flag */
	int iflag { 0 };
	int index {};
	int c {};
	
	opterr = 0;

	while ((c = getopt (argc, argv, "i")) != -1) {
		if (c == 'i') {
			iflag = 1;
		}
	}

	if (iflag) {
		for (index = optind; index < argc; ++index) {
			std::cout << argv[index] << " has the following information." << std::endl;
		}
	} else {
		std::cout << argv[optind] << " is a file." << std::endl;
	}
	
	return 0;
}
