#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include "Playlist.h"

using namespace std;

PlaylistNode::PlaylistNode(){
  uniqueID = "none";
  songName = "none";
  artistName = "none";
  songLength = 0;
  nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string id, string sName, string aName, int sLength){
  uniqueID = id;
  songName = sName;
  artistName = aName;
  songLength = sLength;
}
void PlaylistNode::InsertAfter(PlaylistNode* ptr){
  ptr-> SetNext(this->GetNext());
  this->SetNext(ptr);
}
void PlaylistNode::SetNext(PlaylistNode* ptr){
  this->nextNodePtr = ptr;
}
string PlaylistNode::GetID(){
  return uniqueID;
}
string PlaylistNode::GetSongName(){
  return songName;
}
string PlaylistNode::GetArtistName(){
  return artistName;
}
int PlaylistNode::GetSongLength(){
  return songLength;
}
PlaylistNode* PlaylistNode::GetNext(){
  return this->nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode(){
  cout << "Unique ID: " << uniqueID << endl;
  cout << "Song Name: " << songName << endl;
  cout << "Artist Name: " << artistName << endl;
  cout << "Song Length (in seconds): " << songLength << endl;
}

void Playlist::AddSong(string id, string song, string artist, int length){
  PlaylistNode *newNode;
  newNode = new PlaylistNode(id,song,artist,length);
  if(head == nullptr){
    head = newNode;
    tail = head;
  }
  else{
    tail->InsertAfter(newNode);
    newNode-> SetNext(nullptr);
    tail = newNode;
  }
}

bool Playlist::RemoveSong(string removedSong){
  bool nodeFound = false;
  
  PlaylistNode *prev = nullptr;
  PlaylistNode *curr = head;
  
  if(head == nullptr){
    cout << "Playlist is empty." << endl;
    return false;
    }
  
while (nodeFound == false){
  if(curr -> GetID() == removedSong){
    break;
    }
  prev = curr;
  curr = curr -> GetNext();
  }
  
  if(curr == nullptr){
    cout << "\"" << curr -> GetSongName() << "\" is not found" << endl;
    return false;
    }
  else{
    if(prev == nullptr){
      head = curr -> GetNext();
      }
    else{
      prev -> SetNext(curr -> GetNext());
      }
    if (tail == curr){
      tail = prev;
  }
  delete curr;
  cout << "\"" << curr -> GetSongName() << "\" removed." << endl;
  return true;
}                    
}

bool Playlist::ChangePosSong(int currentPos, int newPos){
    PlaylistNode *prev = nullptr;
    PlaylistNode *curr = head;
  
  
  if(head == nullptr){
    cout << "Playlist is empty." << endl;
    return false;
    }
  if(head == nullptr || head == tail){
    return false;
    }

  //locate old position
  for(int i = 1; i < currentPos; i++){
      prev = curr;
      curr = curr -> GetNext();
  }
  //
  string currSong = curr -> GetSongName();
  if(curr != nullptr){
      if (prev == nullptr){
        head = curr -> GetNext();
      }
      else{
          prev -> SetNext(curr -> GetNext());
        }
  if(curr == tail){
    tail = prev;
    }
    //locate new position
    PlaylistNode* reinsert = curr;
    prev = nullptr;
    curr = head;

  for(int i = 1; i < newPos; i++){
    prev = curr;
    curr = curr -> GetNext();
    }
  if (prev == nullptr){
    reinsert -> SetNext(head);
    head = reinsert;
   }
  else{
    prev -> InsertAfter(reinsert);
   }
  if(curr == nullptr){
      tail = reinsert;
    }
    cout << "\"" << currSong << "\"" << " moved to position " << newPos << endl;
    return true;
    }
  
  else{
  cout << "Not a valid input" << endl;
  return false;
    }
}

void Playlist::OutputSongs(string artistName){
  if(head == nullptr)
  {
    cout << "Playlist is empty." << endl;
    }
unsigned int i = 1;
PlaylistNode *curr = head;
 while (curr != nullptr){
    if (curr -> GetArtistName() == artistName){
      cout << endl << i << "." << endl;
      curr->PrintPlaylistNode();
    }
    curr = curr -> GetNext();
    i++;
}
}

int Playlist::OutputTotalTime(){
int totalTime = 0;
PlaylistNode *curr = head;
while (curr != nullptr){
    totalTime += curr -> GetSongLength();
    curr = curr -> GetNext();
}
  return totalTime;
}

void Playlist::PrintPlaylist(){
if (head == nullptr){
    cout << endl;
    cout << "Playlist is empty" << endl;
 }
else{
    int i = 1;
    PlaylistNode *curr = head;
    while (curr != nullptr){
        cout << endl;
        cout << i++ << "." << endl;
        curr -> PrintPlaylistNode();
        curr = curr -> GetNext();
    }
}
}

