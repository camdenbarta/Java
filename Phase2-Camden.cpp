#include<iostream>
#include<cstring>
#include<string.h>
#include<fstream>
#include<cstdlib>
#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include <sys/dir.h>
using namespace std;
#define PATH_LENGTH 256
//Pre - parse will get each character from the line that the user inputed. 
//Post - It will then store it into an array.
void parse(char **commands, int &n){
	char word;
	int i = 0, j = 0;
	cin.get(word);		// read character by character
	while(word != '\n'){ // read until new line
		if(word != ' '){ // checks for space
			commands[i][j++] = word;
			cin.get(word); // get next character
		}
		else{
			commands[i][j] = '\0'; // terminate word
			i++; // next word
			j = 0;
			cin.get(word); // get next character
		while(word == ' '){ // ignore extra spaces
			cin.get(word);
		}
		}
	}
	commands[i][j] = '\0'; // terminate last word
	n = i + 1;
}
//Pre - It will ask the user for a file that they want to copy. Then it will ask the user
// for the name of the file they want to copy it to. It will give them a warning saying that
// the file they wish to copy it to will be over written.
//Post - The file will be created with the contents from the file the user selected
void copy(){
	string myFile;
    ifstream inFile;
    string fileName;
    ofstream outFile;
    char ch; 
	cout << "Enter the file you want to copy: ";  //asks the user to enter a file
    cin >> myFile;
    inFile.open(myFile);
    if(inFile.fail()){          // Checks if the file was opened correctly
        cout<< "There was a problem opening the file"<<endl;
        exit(EXIT_FAILURE);
    }
    cout << "WARNING: This will over write whatever is currently in this file.\nEnter the file you want to copy to:"; 
    cin >> fileName;
    outFile.open(fileName);
    while(!inFile.eof()){		//copying the file
    	inFile.get(ch);
    	outFile<<ch;
   	cout<<"Copy Successful"<<endl;
    }
    inFile.close();     //closing the input file
    outFile.close(); 	// closing the output file
}
//Pre - This will ask the user what directory they want to change to
//Post - It will either change the that directory or it will give an error

//Pre - The user will type list in the command prompt and it will show the current directory
//Post - It will then leave the list function and ask if the user wants to continue
void list(){
	int argc;
	char** argv;
	char olddir[PATH_LENGTH + 1];
	char newdir[PATH_LENGTH + 1];
	if( getcwd(olddir, PATH_LENGTH) == NULL ){  // Error in text
   	perror("Unable to get current directory");
  	exit(1);
  	cout << "pwd: " << olddir << endl;
  	if( argc != 2 ){
  	cerr << "No directory specified." << endl;
  	exit(1);
  	}
  	if( chdir(argv[1]) == -1 ){
  	perror("Unable to change directories");
  	exit(1);
  	}
  	cout << "cd: " << argv[1] << endl;
  	if( getcwd(newdir, PATH_LENGTH) == NULL ){
   	perror("Unable to get current directory");
  	exit(1);
  	}
  	cout << "pwd: " << newdir << endl;
  	}
	
}
//Pre - This will show all the files within a directory
//Post - 
void show(){
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("c:\\src\\")) != NULL) {	//print all the files and directories within directory
  		while ((ent = readdir (dir)) != NULL) {
    		printf ("%s\n", ent->d_name);
  		}
  		closedir (dir);
	} else {
  		cout<<"could not open directory";
	}
}
//Pre - This will check what command the user types. This also has the help and quit
// method built into it. The help method will show the options the user has and quit 
// method terminates the program
//Post - Loops through until the program is terminated
int main(){   
	int i, n;
	char input[] = "null";
	char choice[10], **command;
	command = new char*[20];
	for(i = 0; i < 20; i++)
		command[i] = new char[30];
	do{
		cout<<"Enter a command: ";
		cin>>input;
		parse(command, n);
		if ((strcmp(input, "help") ==0))
			cout<<"The valid commands are:\nlist\ncopy\nshow\ncd\nhelp\nquit";
		if((strcmp(input, "copy") ==0))
			copy();
		if((strcmp(input, "cd") ==0))
			cd();
		if((strcmp(input, "list") ==0))
			list();
		if((strcmp(input, "show") ==0))
			list();
		//cout<<"\nThe command is: ";	// displays the commands 
		//for(i = 0; i < n; i++)
			//cout<<command[i]<<" ";	// displays how many words there are
			//cout<< "\nThe array has a size of: " << i << endl; // displays size of array
		cout<<"\n\nType anything to continue or quit to stop: ";	//
		cin>>choice;
		cin.ignore();	//ignores the input from asking if you want to quit
						// wont count it as a command and store it in an array
 	}
	while(strcmp(choice, "quit") != 0); // checks if user typed quit
		return 0;
}

