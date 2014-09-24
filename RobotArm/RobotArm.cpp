#include <iostream>
#include <fstream>
#include <vector>

#define WIDTH 400
#define HEIGHT 250
#define SEGMENT_WIDTH 10
#define SEGMENT_HEIGHT 4
#define CIRCLE_RADIUS 1

using namespace std;

int main(int argc, char* argv[]){
	ofstream outFile;
	int originX;
	int originY;
	vector<int> *angles = new vector<int>();
	cout << "Enter X cooridnate for first segment: ";
	cin >> originX;

	cout << "Enter Y cooridnate for first segment: ";
	cin >> originY;

	cout << "Enter rotations in degrees (360 to stop): ";
	while(true){
		int temp;
		cin >> temp;
		if (temp == 360)
			break;
		else
			angles->push_back(temp);
	}
	

#if defined _WIN32
	system("del /f output.svg"); //Kill old svg if it exists
#elif defined __unix
	system("rm -f output.svg");
#endif

	streambuf *coutbuf = std::cout.rdbuf(); //Save old buffer
	outFile.open("output.svg", ofstream::out); //Open file
	cout.rdbuf(outFile.rdbuf()); //change cout to point to our file buffer

	//Grabbed this from SVGs posted on assignment page and modified for my variables to fit

	cout << "<svg xmlns=\"http:\57/www.w3.org/2000/svg\" xmlns:xlink=\"http:\57/www.w3.org/1999/xlink\" width=\"" << WIDTH << "px\" height=\"" << HEIGHT << "px\" viewBox=\"-50 -50 100 75\">" << endl;
	cout << "<defs>\n\t<rect id=\"segment\" x=\"" << originX << "\" y=\"" << originY - (SEGMENT_HEIGHT / 2) << "\" height=\"" << SEGMENT_HEIGHT << "\" width=\"" << SEGMENT_WIDTH << "\" stroke=\"black\" fill=\"white\"/>" << endl;
	cout << "\t<circle id=\"dot\" cx=\"" << originX << "\" cy=\"" << originY << "\" r=\"" << CIRCLE_RADIUS << "\" stroke=\"black\" stroke-width=\".5\" fill=\"#CCC\"/>" << endl;
	cout << "</defs>" << endl << endl;

	//I really wanted that nice coordinate graph, so I borrowed that too
	cout << "<rect x=\"-50\" y=\"-50\" height=\"75\" width=\"100\" stroke=\"black\" fill=\"#EEE\"/>" << endl;
	cout << "<line x1=\"0\" y1=\"-50\" x2=\"0\" y2=\"25\" stroke=\"#888\" stroke-width=\".5\"/>" << endl;
	cout << "<line x1=\"-50\" y1=\"0\" x2=\"50\" y2=\"0\" stroke=\"#888\" stroke-width=\".5\"/>" << endl;
	
	cout << "</svg>";
	return 0;
}