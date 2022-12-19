#ifndef RESIZE_HPP
#define RESIZE_HPP

#define PROGNAME "resize"

int printInfo(const char* const filename);
int resize(const char* const filename, char *output, unsigned int width, unsigned int height);
inline bool fileExists(const std::string& name);

#endif
