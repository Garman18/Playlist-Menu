#include <iostream>
#include <cmath>
#include <string>
#include "Playlist.h"



using namespace std;

void PrintMenu(string playlistTitle){
    cout << endl;
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;
}

int main(){
  Playlist list;
  string id;
  string song;
  string artist;
  int length;
//Getting title and selection
  string playlistTitle;
  bool prompt = true;
  char option;
//Asking for title from user input   
  cout << "Enter playlist's title:" << endl;
  getline (cin, playlistTitle);
  
  while (prompt == true){
    PrintMenu(playlistTitle);
    cin >> option;
    
  if(option == 'a'){
    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> id;
    cin.ignore();
    cout << "Enter song's name:" << endl;
    getline (cin, song);
    cout << "Enter artist's name:" << endl;
    getline (cin, artist);
    cout << "Enter song's length (in seconds):" << endl;
    cin >> length;
    list.AddSong(id, song, artist, length);
    }
    
  else if(option == 'd'){
    cout << "REMOVE SONG" << endl;
    string removedSong;
    cout << "Enter song's unique ID:" << endl;
    cin >> removedSong;
    list.RemoveSong(removedSong);
    }
  else if(option == 'c'){
    cout << "CHANGE POSITION OF SONG" << endl;
    int currentPos;
    int newPos;
    cout << "Enter song's current position:" << endl;
    cin >> currentPos;
    cout << "Enter new position for song:" << endl;
    cin >> newPos;
    list.ChangePosSong(currentPos, newPos);
    }
    
  else if(option == 's'){
    string artistName;
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    cout << "Enter artist's name:" << endl;
    cin.ignore();
    getline (cin, artistName);
    list.OutputSongs(artistName);
    }
  
  else if(option == 't'){
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
    cout << "Total time: " << list.OutputTotalTime() << " seconds" << endl;
    }
    
  else if(option == 'o'){
    cout << playlistTitle << " - OUTPUT FULL PLAYLIST";
    list.PrintPlaylist();
    }
  else if(option  == 'q'){
    prompt = false;
    }
  else{
    cout << "Invalid option" << endl;
    }
    }
  return 0;
}



  

  

