#include <iostream>
#include <cstdio>
#include <fstream>
#include <limits>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<string> lines;

void readFile(char* name){
	FILE *fp;
	char data[1000];
	fp = fopen(name, "r");
	fseek(fp, 0L, SEEK_END);
	long sz = ftell(fp);
	rewind(fp);
	fread(data, sz, sizeof(char), fp);
	data[sz] = '\0';
	cout << data << endl;
	return;
}

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
				if(strlen(buffer) > 2){
					//Read an external file
					readFile(buffer+2);
				}else{
					//Read the contents of the file
					for(i=0; i<s; i++){
						cout << lines[i] << endl;
					}
				}
				break;
			case 'W':
				//Write
				if(!fileOpened){
					cout << "Where do you want to write? ";
					scanf("%256s", fname);
				}
				f.open(fname);
				for(int i = 0;i < s;i++){
					f << lines[i] << endl;
				}
				if(f.fail()){
					cout << "Error writing to " << fname << endl;
				}else{
					cout << "Successfully written to " << fname << endl;
				}
				break;
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
