#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

#define WIDTH 400
#define HEIGHT 250
#define SEGMENT_WIDTH 10
#define SEGMENT_HEIGHT 4
#define CIRCLE_RADIUS 1
#define PI 3.14159265

void recurseSegs(int, vector<int>*);


int main(int argc, char* argv[]){
	ofstream outFile;
	int originX;
	int originY;
	vector<int> *angles = new vector<int>();
	vector<int> *xCoords = new vector<int>();
	vector<int> *yCoords = new vector<int>();

	cout << "Enter X cooridnate for first segment: ";
	cin >> originX;
	xCoords->push_back(originX);

	cout << "Enter Y cooridnate for first segment: ";
	cin >> originY;
	yCoords->push_back(originY);

	cout << "Enter rotations in degrees (360 to stop): ";
	while(true){
		int temp;
		cin >> temp;
		if (temp == 360)
			break;
		else
			angles->push_back(-temp);
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
	cout << "\t<rect id=\"redbox\" x=\"-3\" y=\"-3\" height=\"6\" width=\"6\" fill=\"red\" opacity=\".5\" stroke=\"red\"/>" << endl;
	cout << "</defs>" << endl << endl;

	//I really wanted that nice graph, so I borrowed that
	cout << "<rect x=\"-50\" y=\"-50\" height=\"75\" width=\"100\" stroke=\"black\" fill=\"#EEE\"/>" << endl;
	cout << "<line x1=\"0\" y1=\"-50\" x2=\"0\" y2=\"25\" stroke=\"#888\" stroke-width=\".5\"/>" << endl;
	cout << "<line x1=\"-50\" y1=\"0\" x2=\"50\" y2=\"0\" stroke=\"#888\" stroke-width=\".5\"/>" << endl;

	//Now the calculation code begins
	for (int i = 1; i < angles->size(); i++){
		xCoords->push_back(xCoords->at); //Build our coordinates here

	}
	//Build the SVG
	recurseSegs(0, angles);
	

	cout << "</svg>"; //End our file
	return 0;
}

void recurseSegs(int i, vector<int> *angles){
	if (i == angles->size())
		//Add redbox and last dot stuff here
		return;
		

	for (int j = 0; j < i; j++){ //Indenting
		cout << "\t";
	}
	if (i != 0)
		cout << "<g transform=\"translate(" << SEGMENT_WIDTH << ",0) rotate(" << angles->at(i) << ")\">" << endl; //We want to translate and rotate relative to the previous segment
	else
		cout << "<g transform=\"rotate(" << angles->at(i) << ")\">" << endl; //This is for the first box

	for (int j = 0; j < i + 1; j++){
		cout << "\t";
	}
	cout << "<use xlink:href=\"#segment\"/>" << endl;

	for (int j = 0; j < i + 1; j++){
		cout << "\t";
	}

	cout << "<use xlink:href=\"#dot\"/>" << endl;
	recurseSegs(i + 1, angles);

	for (int j = 0; j < i; j++){
		cout << "\t";
	}
	cout << "</g>" << endl;
}