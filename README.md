(1) Create three files.

Playlist.h - Class declaration
Playlist.cpp - Class definition
main.cpp - main() function to run

(2) Build the PlaylistNode class.

Default constructor
Parameterized constructor

Public member functions:
InsertAfter() 
SetNext() - Mutator 
GetID() - Accessor
GetSongName() - Accessor
GetArtistName() - Accessor
GetSongLength() - Accessor
GetNext() - Accessor
PrintPlaylistNode()

Private data members:
string uniqueID - Initialized to "none" in default constructor
string songName - Initialized to "none" in default constructor
string artistName - Initialized to "none" in default constructor
int songLength - Initialized to 0 in default constructor
PlaylistNode* nextNodePtr - Initialized to 0 in default constructor

Ex. of PrintPlaylistNode output:

Unique ID: S123
Song Name: Peg
Artist Name: Steely Dan
Song Length (in seconds): 237

(2) In main(), prompt the user for the title of the playlist.

Ex:
Enter playlist's title:
JAMZ 

(3) Implement the PrintMenu() function. PrintMenu() takes the playlist title as a parameter and outputs a menu of options to manipulate the playlist. Each option is represented by a single character. Build and output the menu within the function.

If an invalid character is entered, continue to prompt for a valid choice.

Ex:
JAMZ PLAYLIST MENU
a - Add song
d - Remove song
c - Change position of song
s - Output songs by specific artist
t - Output total time of playlist (in seconds)
o - Output full playlist
q - Quit

Choose an option:

(4) Implement "Output full playlist" menu option. If the list is empty, output: Playlist is empty 

Ex:
JAMZ - OUTPUT FULL PLAYLIST
1.
Unique ID: SD123
Song Name: Peg
Artist Name: Steely Dan
Song Length (in seconds): 237

2.
Unique ID: JJ234
Song Name: All For You
Artist Name: Janet Jackson
Song Length (in seconds): 391

3.
Unique ID: J345
Song Name: Canned Heat
Artist Name: Jamiroquai
Song Length (in seconds): 330

(5) Implement the "Add song" menu item. New additions are added to the end of the list.

Ex:
ADD SONG
Enter song's unique ID:
SD123
Enter song's name:
Peg
Enter artist's name:
Steely Dan
Enter song's length (in seconds):
237

(6) Implement the "Remove song" function. Prompt the user for the unique ID of the song to be removed.

Ex:

REMOVE SONG
Enter song's unique ID:
JJ234
"All For You" removed

(7) Implement the "Change position of song" menu option. Prompt the user for the current position of the song and the desired new position. Valid new positions are 1 - n (the number of nodes). If the user enters a new position that is less than 1, move the node to the position 1 (the head). If the user enters a new position greater than n, move the node to position n (the tail). 6 cases will be tested:

Moving the head node 
Moving the tail node 
Moving a node to the head 
Moving a node to the tail 
Moving a node up the list 
Moving a node down the list

Ex:
CHANGE POSITION OF SONG
Enter song's current position:
3
Enter new position for song:
2
"Canned Heat" moved to position 2

(8) Implement the "Output songs by specific artist" menu option. 

Ex:
OUTPUT SONGS BY SPECIFIC ARTIST
Enter artist's name:
Janet Jackson

2.
Unique ID: JJ234
Song Name: All For You
Artist Name: Janet Jackson
Song Length (in seconds): 391

4.
Unique ID: JJ456
Song Name: Black Eagle
Artist Name: Janet Jackson
Song Length (in seconds): 197

(9) Implement the "Output total time of playlist" menu option. Output the sum of the time of the playlist's songs (in seconds).

Ex:
OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)
Total time: 1461 seconds
