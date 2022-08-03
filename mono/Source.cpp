#include <iostream>

#include <ostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
std::string rot13(std::string s)
{
	string const lower = "abcdefghijklmnopqrstuvwxyz",upper =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	string result;
	string::size_type pos;

	result.reserve(s.length());

	for (std::string::iterator it = s.begin(); it != s.end(); ++it)
	{
		if ((pos = lower.find(*it)) != std::string::npos)
			result.push_back(lower[(pos + 13) % 26]);
		else if ((pos = upper.find(*it)) != std::string::npos)
			result.push_back(upper[(pos + 13) % 26]);
		else
			result.push_back(*it);
	}

	return result;
}

int rot13_stream(std::istream& is)
{
	std::string line;
	while (std::getline(is, line))
	{
		if (!(std::cout << rot13(line) << "\n"))
			return false;
	}
	return is.eof();
}


int main(int argc, char* argv[])
{
	if (argc == 1) 
		return rot13_stream(std::cin) ? EXIT_SUCCESS : EXIT_FAILURE;

	std::ifstream file;
	for (int i = 1; i < argc; ++i)
	{
		file.open(argv[i], std::ios::in);
		if (!file)
		{
			std::cerr << argv[0] << ": could not open for reading: " << argv[i]
				<< "\n";
			return EXIT_FAILURE;
		}
		if (!rot13_stream(file))
		{
			if (file.eof())
				
				std::cerr << argv[0] << ": error writing to stdout\n";
			else
				std::cerr << argv[0] << ": error reading from " << argv[i]
				<< "\n";
			return EXIT_FAILURE;
		}
		file.clear();
		file.close();
		if (!file)
			std::cerr << argv[0] << ": warning: closing failed for " << argv[i]
			<< "\n";
	}
	return EXIT_SUCCESS;
}