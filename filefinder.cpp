#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
using namespace std;
using namespace boost::filesystem;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Usage: tut3 path\n";
		return 1;
	}

	path p(argv[2]);
	cout << p.filename().string() << endl;
	try
	{
		if (exists(p))
		{
			if (is_regular_file(p))
				cout << p << " size is " << file_size(p) << '\n';

			else if (is_directory(p))
			{
				cout << p << " is a directory containing:\n";
				for (auto x : recursive_directory_iterator(p)) {
					if (x.path().filename() == argv[1]) {
						cout << "There is " << x.path() << endl;
					}
				}
			}
			else
				cout << p << " exists, but is not a regular file or directory\n";
		}
		else
			cout << p << " does not exist\n";
	}

	catch (const filesystem_error& ex)
	{
		cout << ex.what() << '\n';
	}

	return 0;
}
