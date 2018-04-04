/***********************************************************************************************
 * Program description:  Play That Record is a C++ program has a menu to quit the program, and
 *  uses the Cd class. The lab also uses object arrays to  read and diplay the first 17 records
 *  of artist, title, and year.
 *
 *  The program calls a sorting and searching method to find a Cd array object with the same
 *  artist and title. Once the Cd is found (by linear search and recursion), the artist, title,
 *  and/or year may be edited.
 *
 * 	The MathBreaksubmenu to test for Even or Odd, test for Prime Numbers, reverse string, or go
 * 	back to main menu.
 *
 * Function descriptions: (see function heading below)
 **********************************************************************************************/
#include <iomanip>
#include<iostream>
#include <fstream>
using namespace std;

//Cd class declaration
class Cd
{
	private:
		//private variables
		string artist, title;
		string *tracks;
		int year, trackNum;
	public:
		//default constructor prototype
		Cd();
		//function prototypes
		void setNumTracks(int);
		int getNumTracks();
		string getTrackName(int);
		void setTrackName(int, string);
		void deleteTracks();
		void setArtist(string);
		string getArtist();
		void setTitle(string);
		string getTitle();
		void setYear(int);
		int getYear();
};

/********************************************************************************************
* Function:   Cd default constructor
* Inputs:     default values to artist, title, year, tracks, and trackNum.
* Outputs:    Variable artist and title is initialized to default artist and default title.
* 			  Variable year and trackNum is initialized to 0.
* 			  Variable pointer tracks is set to 0.
* Purpose:    Default constructor initialize variable artist, title, and year to default values
********************************************************************************************/
Cd::Cd()
{
	artist="default artist";
	title="default title";
	year=0;
	tracks=0;
	trackNum=0;
}

/********************************************************************************************
* Function:   setNumTracks
* Inputs:     int cdTrackSize
* Outputs:    sets an array of tracks with the size of cdTrackSize
* Purpose:   setNumTracks allocate memory of cdTrackSize for the array of tracks
********************************************************************************************/
void Cd::setNumTracks(int cdTrackSize)
{
	trackNum=cdTrackSize;
	tracks = new string[trackNum];
}

/********************************************************************************************
* Function:   getNumTracks
* Inputs:
* Outputs:    returns trackNum
* Purpose:   getNumTracks returns the value of the member variable trackNum
********************************************************************************************/
int Cd::getNumTracks()
{	return trackNum;}

/********************************************************************************************
* Function:   getTrackName
* Inputs:	  integer position of the array, "positionInTracksArray"
* Outputs:    returns the track name of tracks array at the index of "postitionInTracksArray"
* Purpose:   getNumTracks returns the a track from the tracks array at positionInTracksArray.
********************************************************************************************/
string Cd::getTrackName(int positionInTracksArray)
{	return tracks[positionInTracksArray];}

/********************************************************************************************
* Function:   setTrackName
* Inputs:     integer positionInTracksArray and string trackName
* Outputs:    takes the positionInTracksArray of the tracks array and sets to trackName
* Purpose:   sets trackname into the tracks array based on the index of positionInTracksArray
********************************************************************************************/
void Cd::setTrackName(int positionInTracksArray, string trackName)
{
	if(positionInTracksArray<trackNum)
		tracks[positionInTracksArray]=trackName;
}

/********************************************************************************************
* Function:   deleteTracks
* Inputs:	  pointer tracks
* Outputs:    deallocates the array of tracks
* Purpose:    checks if the pointer tracks contains value (has tracks), if there is an address to tracks,
* deallocate the array of tracks.
********************************************************************************************/
void Cd::deleteTracks()
{
	if(tracks)
		{
			delete [] tracks;
			tracks=0;
			trackNum=0;
		}
}
/********************************************************************************************
* Function:   setArtist
* Inputs:     String cdArtist
* Outputs:    sets artist to cdArtist
* Purpose:   setArtist sets the value of the member variable artist
********************************************************************************************/
void Cd::setArtist(string cdArtist)
{	artist=cdArtist;}

/********************************************************************************************
* Function:   getArtist
* Inputs:
* Outputs:    returns artist
* Purpose:   getArtist returns the value of the member variable artist
********************************************************************************************/
string Cd::getArtist()
{	return artist;}

/********************************************************************************************
* Function:   setTitle
* Inputs:     String cdTitle
* Outputs:    sets title to cdTitle
* Purpose:   setTitle sets the value of the member variable title
********************************************************************************************/
void Cd::setTitle(string cdTitle)
{	title=cdTitle;}

/********************************************************************************************
* Function:   getTitle
* Inputs:
* Outputs:    returns title
* Purpose:   getTitle returns the value of the member variable title
********************************************************************************************/
string Cd::getTitle()
{ 	return title;}

/********************************************************************************************
* Function:   setYear
* Inputs:     String cdYear
* Outputs:    sets year to cdYear
* Purpose:    setYear sets the value of the member variable year
********************************************************************************************/
void Cd::setYear(int cdYear)
{ 	year=cdYear;}

 /********************************************************************************************
 * Function:   getYear
 * Inputs:
 * Outputs:    returns year
 * Purpose:   getYear returns the value of the member variable year
 ********************************************************************************************/
int Cd::getYear()
{	return year;}

//global constant size for the max size to use in the array
const int SIZE = 17;
//global constants for menu options
const int READ_COLLECTION=1;
const int DISPLAY_COLLECTION=2;
const int SORT_COLLECTION=3;
const int FIND_CD=4;
const int FIND_RECUR=5;
const int EDIT_CD=6;
const int ADD_TRACK=7;
const int DELETE_TRACK=8;
const int MATHBREAK_CHOICE=9;
const int QUIT=10;

//mathbreak prototypes
void mathBreak();
bool isEven(int);
void evenOdd();
bool isPrime(int);
void primeNumber();
void reverseString(string, int);

//display and get prototypes to get, sort, edit, add tracks, delete tracks, and display the album
void displayCd(Cd[]);
bool getAlbum(Cd []);
void getSort(Cd []);
int getCd(Cd [], string, string);
void editCd(Cd *);
void addTrack(Cd[]);
bool findRecursive(Cd[], string, string, int);

/********************************************************************************************
*  Function:   main
*  Inputs:     Menu option number
*  Outputs:    displays Read Collection, Display Collection, Sort Collection, Find CD, Edit CD,
*   mathBreak, or ends program
*  Purpose:    Display menu for Read Collection, Display Collection, Sort Collection, Find CD,
*  Edit CD (linear search or recursively), Add Tracks, Delete Tracks, Math Break, or Quit.
*  Reads the option and runs a validation. loop and re-prompts user to enter a valid integer.
*  Main also enables users to test Cd, go to mathBreak(), or to end MathBreak.
*  User choose 1 to Read collection, 2 go to Display Collection, 3 to Sort Collection, 4 to
*  Find cd,5 to find CD *recursively 6 to Edit CD, 7 Add Tracks, 8 to Delete Tracks,
*  9 for Math Break, or 10 to end program
 ********************************************************************************************/
int main()
{
	//variables for menu options
	int option;
	//isRead used to verify if READ_COLLECTION  ran
	bool isRead=false;
	//findCd used to find the cd by locating the index in the array
	int findCd=-1;
	//editNew used to edit another cd
	//char editNew;
	//creates a Cd object array
	Cd album[SIZE];
	//user input artist and title to find cd
	string artist, title;

	//do while loop until user terminates when option is equal to QUIT
	do
	{
		//displays main menu
		cout<< "Main Menu\n";
		cout<< "---------\n";
		cout<< "1. Read Collection \n";
		cout<< "2. Display Collection \n";
		cout<< "3. Sort Collection \n";
		cout<< "4. Find a CD \n";
		cout<< "5. Find a CD * Recursive Version *\n";
		cout<< "6. Edit a CD \n";
		cout<< "7. Add Tracks for a CD \n";
		cout<< "8. Delete All Tracks for a Cd \n";
		cout<< "9. Math Break \n";
		cout<< "10. Quit \n";

		//read the option
		cout<< "Please enter a number to select a menu function. ";
		cin>>option;
		cin.ignore();

		//data validation loop for numbers that is greater than 7 and less than 1
		while(option<1 || option>10)
		{
			//displays error msg  and asks to re-enter a valid number.
			cout<< "Please try again.That was not a valid entry Please choose an integer from 1 to 9. ";
			cin>>option;
			cin.ignore();
		}

		 //switch statement to determine menu option
		switch(option)
		{
			//checks if records are read out of the file
			case READ_COLLECTION:
			{
				cout <<"\nLooking for file.... ";
				//if file reads then the array of Cd object album is passed to getAlbum() and set isRead to true
				isRead=getAlbum(album);
				if(isRead)
					cout<<"File read\n\n";
				//else display error msg
				else
				 	cout<<"FILE DID NOT READ. Please change file.\n\n";
				break;
			}
			//if file was not read before proceeding, and error message displays.
			//Displays the first 17 Records or less.
			case DISPLAY_COLLECTION:
			{
				if(isRead)
					displayCd(album);
				else
					cout<< "The collection was NOT READ. You need to read the collection before proceeding \n\n";
				break;
			}
			//if file was not read before proceeding, and error message displays.
			//sorts the the collection by Artist
			case SORT_COLLECTION:
			{
				//calls getSort and sorts cd object array in ascending order by Artist
				if(isRead)
				{
					cout<<"\nSorting by Artist\n\n";
					getSort(album);
				}
				else
					cout<< "The collection was NOT READ. You need to read the collection before proceeding \n\n";
				break;
			}
			//if file was not read before proceeding an error message displays.
			//locates a cd based on title and artist
			case FIND_CD:
			{
				if(isRead)
				{
					//asks user to for artist and title
					cout<<"\nPlease enter the Artist: ";
					getline(cin,artist);
					cout<<"\nPlease enter the Title: ";
					getline(cin,title);
					//calls getCd and returns the index of the cd object array
					findCd=getCd(album, artist, title);
					if(findCd!=-1)
						cout<<album[findCd].getArtist()<<" and "
						<<album[findCd].getTitle()<<" CD is in the collection \n\n";
					//if index returns -1, the cd was not found and displays error message
					else
						cout<<" CD is NOT in the collection \n\n";
				}
				else
				{
					cout<< "\nThe collection was NOT READ."<<
							" You need to read the collection before proceeding \n\n";
				}
				break;
			}
			//if file was not read before proceeding an error message displays.
			//locates a cd based on title, artist and displays CD if found, and returns true/false
			case FIND_RECUR:
			{
				if(isRead)
				{
					//asks user to for artist and title
					cout<<"\nPlease enter the Artist: ";
					getline(cin,artist);
					cout<<"\nPlease enter the Title: ";
					getline(cin,title);
					//passes title and artist to the fird recursive method
					findRecursive(album, artist, title, 17);
				}
				else
				{
					cout<< "\nThe collection was NOT READ."<<
						" You need to read the collection before proceeding \n\n";
				}
				break;
			}
			//if file was not read a error message displays.
			//once cd is found, the artist, title, and/ or year maybe edited
			case EDIT_CD:
			{
				if(isRead)
				{
					//calls edit cd and passes the album array object
					editCd(album);
				}
				else
					cout<< "The collection was NOT READ."<<
							"You need to read  and find the collection before proceeding \n\n";
				break;
			}
			//makes call to addTracks
			case ADD_TRACK:
			{
				if(isRead)
				{
					//calls edit cd and passes the album array object with the found index, "findCd"
					addTrack(album);
					//once tracks added, resets findCd to -1 to find another Cd
					findCd=-1;
					cout<<"Please find a new CD.\n\n";
				}
				else
					cout<< "The collection was NOT READ. "<<
						   "You need to read  and find the collection before proceeding \n\n";
				break;
			}
			//makes call to deleteTracks
			//once cd is found, and there are tracks, the tracks will be deleted
			case DELETE_TRACK:
			{
				if(isRead)
				{
					cout<< "\nBEFORE YOU DELETE YOU MUST FIND THE CD FIRST\n";
					//asks user to for artist and title
					cout<<"\nPlease enter the Artist: ";
					getline(cin,artist);
					cout<<"\nPlease enter the Title: ";
					getline(cin,title);
					//calls getCd and returns the index of the cd object array
					findCd=getCd(album, artist, title);
					if(findCd!=-1)
					{
						cout<<album[findCd].getArtist()<<" and "
						<<album[findCd].getTitle()<<" CD is in the collection \n\n";
						//if tracks are found, call deleteTracks() to remove tracks
						if(album[findCd].getNumTracks()>0)
						{
							album[findCd].deleteTracks();
							cout<<"\n\nTracks are deleted\n";
						}
					//error message no tracks to delete
					else
						cout<<"\n\nThere are no tracks to delete\n";
					}
				}
				else
				{
					cout<< "The collection was NOT READ. "<<
						"You need to read  and find the collection before proceeding \n\n";
				}
				break;
			}
			//makes call to mathBreak function
			case MATHBREAK_CHOICE:
			{
				mathBreak();
				break;
			}
			//terminates the program and displays Goodbye
			case QUIT:
			{
				cout<< "Goodbye. \n\n";
				option=QUIT;
				break;
			}
		}
	//ends Math Break when user quits to end.
	}while(option!=QUIT);
	return 0;
}

/********************************************************************************************
* Function:   reverseString
* Inputs:     string name to test
* Outputs:    displays string name in reverse order
* Purpose:    Reads the name at each position and reads out the name in reverse order
********************************************************************************************/
void reverseString(string name, int pos)
{
	//if the current location less than sting length call reverses tring and update the position.
	//once recursion complete print out name in reverse order
	if(pos<name.length())
	{
		reverseString(name, pos+1);
		cout<<name[pos];
	}
}

/********************************************************************************************
 * Function:  	findRecursive
 * Inputs:    	Cd array object find, string myartist, string mytitle, int size
 * Outputs:    	returns true (if found)/false(not found)
 * Purpose:    	Finds Cd  from the object array find based on artist and title and displays
 * artist, title, and year if found.   if not found display message cannot find CD.
********************************************************************************************/
bool findRecursive(Cd find[], string myartist, string mytitle, int size)
{
	//update for recursion
	size=size-1;
	//if cannot find from end to beginning, return false and display error msg
	if (size<0)
	{
		cout<<"\nArtist: "<< myartist<<" and Title: "<<mytitle<<" WAS NOT FOUND.\n\n";
		return false;
	}
	//if artist and title found, display the CD and return true
	else if(find[size].getArtist()==myartist &&find[size].getTitle()==mytitle)
	{
		cout<<"\nCD WAS FOUND: \n";
		cout<< setw(25) <<left << "\nARTIST"   << setw(33) <<left << "TITLE"   << setw(5) <<left <<"YEAR RELEASED"<<"\n";
		cout<< setw(25) <<left << "------"   << setw(33) <<left <<"-----"    << setw(5) <<left <<"-------------"<<"\n";
		cout<< setw(25) <<left << find[size].getArtist() << setw(33) <<left << find[size].getTitle()
			<< setw(5) <<left << find[size].getYear() <<endl;
		cout<< "-------------------------------------------------------------------------" <<endl<<endl;
		return true;
	}
	//if not found and not the end continue searching
	else
	{
		return findRecursive(find, myartist, mytitle, size);
	}
}

/********************************************************************************************
* Function:   addTrack
* Inputs:     Artist, title, size of track list, and tracks.
* Outputs:    Displays track list
* Purpose:    Function to find Cd. If Cd is found, asks user the size of the track list and
* the names of the track. Then display the tracks added to the track.
Displays an error message if the Cd cannot be found.
********************************************************************************************/
void addTrack(Cd add[])
{
	int index, size;
	string artist, title, track;
	//asks for artist and title to find cd, if found add tracks
	cout<< "\nBEFORE YOU EDIT YOU MUST FIND THE CD FIRST\n";
	cout<<"Enter Artist: ";
	getline(cin,artist);
	cout<<endl;
	cout<<"Enter Title: ";
	getline(cin,title);
	cout<<endl;

	index= getCd(add, artist, title);
	if(index!=-1)
	{
		cout<<"How many tracks do you want on album: "<<add[index].getArtist() << " and Title: "<<add[index].getTitle()<<"? ";
		cin>>size;
		cin.ignore();
		//sets track size
		add[index].setNumTracks(size);
		//set tracks to cd
		for(int x=0; x<size; x++)
		{
			cout<<"\nPlease enter the name of the "<<(x+1)<<" track ";
			getline(cin,track);
			add[index].setTrackName(x, track);
		}
		//displays the tracks added
		cout<<"\nThe follow tracks have been added to album: "<<add[index].getArtist() << " and Title: "<<add[index].getTitle()<<endl;
		for(int x=0; x<size; x++)
			cout<<"\t"<<(x+1)<< ". "<< add[index].getTrackName(x) <<endl;
	}
	//if cd not found displays error message
	else
		cout<<"CD artist: "<<artist<< " and title: "<<title<< " was not found."<<endl;
}

/********************************************************************************************
* Function:   editCd
* Inputs:     Menu option number and editArtist, editTitle, and/ or editYear
* Outputs:    Displays Edit Cd menu for Editing the Artist, Title, Year, or back to main menu.
* Purpose:    Function to display the Edit Cd Menu and enables user to edit the Artist, Title,
* and/ or Year. the function reads the option and runs a validation loop and re-prompts user
* to enter a valid integer.
*Edits Artist, Title, Year, or ends Edit Cd menu
*User choose 1 edit Artist, 2 edit Title, 3 edit Year, and 4 to end Edit Cd.
********************************************************************************************/
void editCd(Cd*edit)
{
	int option, index, editYear;
	string artist, title;
	//asks for artist and title to find cd before proceeding
	cout<< "\nBEFORE YOU EDIT YOU MUST FIND THE CD FIRST\n";
	cout<<"Enter Artist: ";
	getline(cin,artist);
	cout<<endl;
	cout<<"Enter Title: ";
	getline(cin,title);
	cout<<endl;

	//calls getCd to return index. if index>-1 (found) then edit CD. else return error message
	index= getCd(edit, artist, title);
	if(index>-1)
	{
		do
		{
			//displays Editing Cd menu
			cout<< "\nEDITING CD MENU\n";
			cout<<"------------------\n";
			cout<< "1. Edit Artist \n";
			cout<< "2. Edit Title \n";
			cout<< "3. Edit Year \n";
			cout<< "4. End my Editing Cd Menu \n\n";

			cout<< "Please enter a number to select a menu option. ";
			cin>>option;
			cin.ignore();

			//data validation loop for number that is greater than 4 and less than zero
			while(option<1 || option >4)
			{
				//displays error msg  and asks to re-enter a valid number.
				cout<< "Please try again.That was not a valid entry Please choose an integer from 1 to 4. ";
				cin>> option;
				cin.ignore();
			}

			//switch statement to determine menu option
			switch(option)
			{
				//sets a new value to Artist
				case 1:
				{
					cout<<"\nEnter New Artist Name ";
					getline(cin,artist);
					(edit+index)->setArtist(artist);
				}
				break;
				//sets a new value to Title
				case 2:
				{
					cout<<"\nEnter New Title Name ";
					getline(cin,title);
					(edit+index)->setTitle(title);
				}
				break;
				//set a new value to Year
				case 3:
				{
					cout<<"\nEnter New Year ";
					cin>>editYear;
					(edit+index)->setYear(editYear);
					cin.ignore(2, '\n');
				}
				break;
				//ends Editing
				case 4: option=4;
					cout << "Editing Cd ended.\n\n";
					break;
			}
		//ends Editing Cd when user enters 4 to end.
		}while(option!=4);
	}
	//error message if cd was not found
	else
		cout<<"CD artist: "<<artist<< " and title: "<<title<< "was not found."<<endl;
}

/********************************************************************************************
* Function:   getSort
* Inputs:     Cd object sort array
* Outputs:    sets the Cd sort object array in ascending order by artist
* Purpose:   gets the artist of each element in the array and sorts the artist in ascending
* order. The sorting algorthm is the bubble sort. If the artist is the same, then the the
* title will be compared and checks also in ascending order.
********************************************************************************************/
void getSort(Cd sort[])
{
	bool swap;
	//creates temp Cd object array for temporary storage
	Cd temp[SIZE];

	//starts bubble sort
	do
	{
		swap=false;
		//first for loop checks for the current element in the array to the next element of the array
		for(int count=0; count<(SIZE-1);count++)
		{
			//if the current artist is the same to the next artist proceed to check the title
			if(sort[count].getArtist()==sort[count+1].getArtist())
			{
				//compares the title by ascending order if the current title > the next title, swap
				if(sort[count].getTitle()>sort[count+1].getTitle())
				{
					temp[count]=sort[count];
					sort[count]=sort[count+1];
					sort[count+1]=temp[count];
					swap=true;
				}
			}
		//if the current artist > the next artist, swap
		else if(sort[count].getArtist()>sort[count+1].getArtist())
			{
				temp[count]=sort[count];
				sort[count]=sort[count+1];
				sort[count+1]=temp[count];
				swap=true;
			}
		}
	//once there are no more swaps the sorting is done
	}while(swap);
}

/********************************************************************************************
* Function:   getCd
* Inputs:     Cd object sort array
* Outputs:    sets the Cd sort object array in ascending order by artist and returns the index
* 			 if position is -1 then the cd was not found, else the cd was found and returns the index
* Purpose:   asks userfor artist and title and fuction performs a linear search to find the cd with
* matching title and artist. returns the index of the Cd array object.
********************************************************************************************/
int getCd(Cd cdAlbum[], string myArtist, string myTitle)
{


	cout<<"\nFinding CD..\n\n";

	int index=0, position=-1;
	bool found=false;

	//linear search to find CD
	while(index<SIZE &&!found)
	{
		//if the Artist and Title matches, the CD is found
		if(cdAlbum[index].getArtist()==myArtist &&cdAlbum[index].getTitle()==myTitle)
		{
			found=true;
			position=index;
		}
		//else check the next one
		index++;
	}
	//returns the index. -1: Not found. other value: found
	if(position!=-1)
		cout<<"CD was found"<<endl;
	else
		cout<<"CD was NOT found"<<endl;
	return position;
}

/********************************************************************************************
* Function:   getAlbum
* Inputs:     Cd object cdAlbum array
* Outputs:    sets artist, title, and year to the Cd cdAlbum object array
* Purpose:   opens a text file and creates a Cd object arrays for the albumArtist, albumTitle, and albumYear.
* then sets the array from the text file. The max size of the parallel array is 17 (SIZE).
********************************************************************************************/
bool getAlbum(Cd cdAlbum[])
{
	string albumArtist, albumTitle;
	int albumYear;
	bool open=false;
	fstream cdFile;
	cdFile.open("cd.txt");
	if(cdFile)
	{
	//gets and sets the  first 17 records for albumArtist, albumTile, and albumYear.
	for(int albumcount=0; albumcount<SIZE; albumcount++)
	{
		getline(cdFile, albumArtist);
		getline(cdFile, albumTitle);
		cdFile>> albumYear;
		cdFile.ignore(2, '\n');
		//setting the albumArtist, albumTile, and albumYear to the Cd cdAlbum object array
		cdAlbum[albumcount].setArtist(albumArtist);
		cdAlbum[albumcount].setTitle(albumTitle);
		cdAlbum[albumcount].setYear(albumYear);
	}
	open=true;
	cdFile.close();
	}
	return open;
}

/********************************************************************************************
* Function:   displayCd
* Inputs:    Passes Cd displayAlbum object array and calls cd function getArtist(), getTitle(), and getYear()
* Outputs:    displays Artist, Title, and Year information from the Cd displayAlbum object Array.
* Purpose:    Displays the Cd's data for the artist, title, and year.
 ********************************************************************************************/
void displayCd(Cd displayAlbum[])
{
	//displays the Artist, Title, and Year Released
	cout<< setw(25) <<left << "\nARTIST"   << setw(33) <<left << "TITLE"   << setw(5) <<left <<"YEAR RELEASED"<<"\n";
	cout<< setw(25) <<left << "------"   << setw(33) <<left <<"-----"    << setw(5) <<left <<"-------------"<<"\n";
	//displays the first 17 elements in the array
	for(int i=0; i<SIZE; i++)
	{
		cout<< setw(25) <<left << displayAlbum[i].getArtist()
			<< setw(33) <<left << displayAlbum[i].getTitle()
			<< setw(5) <<left << displayAlbum[i].getYear() <<endl;

			for(int tracks=0; tracks<displayAlbum[i].getNumTracks(); tracks++)
				cout<<"\t"<<(tracks+1)<<". "<<displayAlbum[i].getTrackName(tracks)<<endl;
	}
	cout<< "-------------------------------------------------------------------------" <<endl<<endl;
}

/********************************************************************************************
* Function:   isEven
* Inputs:     integer number to test
* Outputs:    1/true is even, 0/false is odd
* Purpose:    Reads number and checks if number is an even or odd by modular division.
* if number mod2==0 then even is odd. Else even is false. isEven(int number) returns true or false.
********************************************************************************************/
bool isEven(int number)
{
	bool even=false;
	//if number mod 2 is equal to 0 then number is even and isEven to true
	if((number%2)==0)
		even=true;
	return even;
}

/********************************************************************************************
 * Function:  	evenOdd
 * Inputs:    	integer >= 0
 * Outputs:    	Displays  the number as odd or even and repeats steps until enter 0. 0 enters
 * 				returns back to the MathBreak menu.
 * Purpose:    	Prompts user for an integer of 0 or larger and run a validation loop and
 *re-prompts user to enter a valid integer. The function uses a sentinel controlled while loop
 *using 0 to quit the function.
 *If number > 0, then function makes a call to isEven(number) to display the number as odd or even.
 *If number =0, evenOdd() ends and  the program goes back to mathBreak().
********************************************************************************************/
void evenOdd()
{
	int number;
	//prompts user to run odd even or quit
	cout << "Please enter a positive integer to continue EVEN OR ODD or 0 to quit ";
	cin>> number;
	cin.ignore();

	//sentinel controlled do while loop using 0 to decide when to quit the game.
	while(number!=0)
	{
		//validate input is greater than 0
		while(number<0)
		{
			//displays error msg  and asks to re-enter a valid number.
			cout<< "Please try again.That was not a positive integer. ";
			cin>> number;
			cin.ignore();
		}

		//calls isEven function and displays the number is odd or even
		if(isEven(number))
			cout << number <<" is an even number. \n\n";
		else
			cout << number << " is an odd number. \n\n";

		//Prompts user to check for prime numbers or quit
		cout << "Please enter a positive integer to continue EVEN OR ODD or 0 to quit ";
		cin>> number;
		cin.ignore();
	}
}

/********************************************************************************************
 * Function:   isPrime
 * Inputs:     integer to test
 * Outputs:    true/1 if number is Prime, false/0 if number is not Prime
 * Purpose:    Reads number and checks if number is a prime number by checking number
 * is not <2 and modular division. Sets prime to true. if number greater than 0 and less than
 * 2 prime is false.
 * If number >2 will use a for loop to check all valid prime cases.
 * inside the for loop, set testCase=2. If number mod testcase==0 then prime is false. Else
 * update testCase and continue the for loop until there are no more cases to test or Prime is false.
 *  Else isPrime is prime and true. isPrime(int number) returns true or false.
********************************************************************************************/
bool isPrime(int number)
{
	//set isPrime to true and test for all invalid prime cases.
	bool prime=true;

	//number >2 & number>0 then not prime and isPrime=false.
	if( number<2)
		prime=false;
	else
	{
		//max test case= number/2
		int maxcase=number/2;
		//for loop to test for invalid prime cases. testCase = value to modular divide with number.

		//run for loop until !prime or until there are no more test cases to test
		for(int testCase=2; testCase<=maxcase&&prime; testCase++)
		{
			//if number mod testCase==0 then number is not prime. prime=false
			if(number%testCase==0)
			 {
				testCase= number;
				prime=false;
			 }
		}
	}
	return prime;
}

/********************************************************************************************
* Function:   primeNumber
* Inputs:     Integer number >0
* Outputs:    Displays message if entered number is prime or not. repeats steps until 0 is entered.
* When 0 is entered goes to MathBreak menu.
* Purpose:   Prompts user for an integer of 0 or larger and run a validation loop and
*re-prompts user to enter a valid integer. The function uses a sentinel controlled while loop using 0
*to quit the function. If number > 0, then function makes a call to isPrime(number) to display the
*to number as prime or not prime. *If number =0, primeNumber() ends and  the program goes back to mathBreak().
********************************************************************************************/
void primeNumber()
{
	int number;
	//Prompts user for integer number >=0
	cout << "Please enter a positive integer to continue PRIME NUMBER or 0 to quit ";
	cin>> number;
	cin.ignore();

	//sentinel controlled do while loop using 0 to decide when to quit the game.
	while(number!=0)
	{
		//validates number greater than 0, if not asks user to re-enter input
		while(number<0)
		{
			//displays error msg  and asks to re-enter a valid number.
			cout<< "Please try again.That was not a valid positive integer. ";
			cin>> number;
			cin.ignore();
		}

		//calls isPrime function to determine prime or not
		if(isPrime(number))
			cout<< number << " is a prime number.\n\n";
		else
			cout << number << " is not a prime number.\n\n";

		//Prompts user to check for prime numbers or quit
		cout << "Please enter a positive integer to continue PRIME NUMBER or 0 to quit \n";
		cin>> number;
		cin.ignore();
	}while(number!=0);
}

/********************************************************************************************
* Function:   mathBreak
* Inputs:     Menu option number
* Outputs:    Displays mathBreak menu for Even or Odd, Prime Number, or back to main menu.
* Purpose:    Function to display the Math Break Menu and enables user to go to Even or Odd,
* Prime Number, or to end MathBreak. the function reads the option and runs a validation
* loop and re-prompts user to enter a valid integer.
*Goes to Even or Odd, Primes Numbers or ends Math Break menu
*User choose 1 go to Even or odd, 2 go to Prime Number, 3 to end Math Break.
********************************************************************************************/
void mathBreak()
{
	int option;
	string reverseword;
	do
	{
		//displays Math Break menu
		cout<< "MATH BREAK MENU\n";
		cout<<"------------------\n";
		cout<< "1. Even or Odd \n";
		cout<< "2. Prime Number \n";
		cout<< "3. String Reverse \n";
		cout<< "4. End my Math Break \n\n";

		cout<< "Please enter a number to select a menu option. ";
		cin>>option;
		cin.ignore();

		//data validation loop for number that is greater than 4 and less than zero
		while(option<1 || option >4)
		{
			//displays error msg  and asks to re-enter a valid number.
			cout<< "Please try again.That was not a valid entry Please choose an integer from 1 to 4. ";
			cin>> option;
			cin.ignore();
		}

		//switch statement to determine menu option
		switch(option)
		{
			//makes call to evenOdd function
			case 1: evenOdd();
					break;
			//makes call to primeNumber function
			case 2: primeNumber();
					break;
			//makes asks user for a word and passes the word to reverseString()
			case 3:
				{
				option=3;
				cout<<"Please Enter a String: ";
				getline(cin, reverseword);
				cout<<endl;
				reverseString(reverseword, 0);
				cout<<endl<<endl;
				}
					break;
			//ends Math Break
			case 4: option=4;
					cout << "Math Break ended.\n\n";
					break;
		}
	//ends Math Break when user enters 3 to end.
	}while(option!=4);
}
