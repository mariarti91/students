#include <cstdio>
#include <unistd.h>
#include <cstdlib>

#include "format.h"

int main(int argc, char** argv)
{
	string text;
	unsigned int lineLength;
	int opt;
	while((opt = getopt(argc, argv, "n:t:")) != -1)
		switch(opt)
		{
			case 'n':
				lineLength = atoi(optarg);
				break;
			case 't':
				text = string(optarg);
				break;
			case '?':
				printf("ooops!\n");
				exit(1);
		}
	Base* b = new Left(lineLength, text);
	printf("Left:\n%s\n\n", b->getText().c_str());
	b = new Right(lineLength, text);
	printf("Right:\n%s\n\n", b->getText().c_str());
	b = new Center(lineLength, text);
	printf("Center:\n%s\n\n", b->getText().c_str());
	delete b;
	return 0;
}
