#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <string>

using namespace std;

vector<string> lines;

int main(int argc, char *argv[]){
	char buffer[100];
	string bufferString;
	signed char notDone = 1;
	int s = 0;
	string filename;
	signed char fileOpened = 0;
	ofstream f;
	if(argc > 1){
		fileOpened = 1;
		filename = argv[1];
	}
	
	while(notDone){
		cin.get(buffer, 100);
		char* l;
		int i;
		char fname[255];
		switch(buffer[0]){
			case 'X':
				//eXit
				notDone = 0;
				break;
			case 'L':
				//Line
				l = buffer+1;
				bufferString = l;
				lines.push_back(bufferString);
				s++;
				break;
			case 'C':
				//Cat
				for(i=0; i<s; i++){
					cout << lines[i] << endl;
				}
			case 'W':
				//Write
				if(!fileOpened){
					cout << "Where do you want to write? ";
					cin.get(fname, 255);
					filename = fname;
				}
				f.open(filename);
				for(int i = 0;i < s;i++){
					f << lines[i] << endl;
				}
			default:
				break;
		}
		//cout << (int) notdone << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if(fileOpened){
		f.close();
	}

	return 0;
}
