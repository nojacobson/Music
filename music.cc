#include <iostream>
#include <string>

using namespace std;

int main()
{
    // contains the intervals for the major, minor
    int majorKeyInts[12][7];
    int minorKeyInts[12][7];

    // contain the notes with whther they are major or minor
    string majorScales[12][7];
    string minorScales[12][7];

    // initializing the arrs
    for(int x = 0; x < 12; x++) {
        majorKeyInts[x][0] = x;
        minorKeyInts[x][0] = x;
    }

    // building intervals
    for(int x = 0; x < 12; x++) {
        for(int y = 1; y < 7; y++) {

        // MAJOR
            if(y == 3 || y == 7) { // semi tones 
                majorKeyInts[x][y] = majorKeyInts[x][y - 1] + 1;
            }
            else {
                majorKeyInts[x][y] = majorKeyInts[x][y - 1] + 2;   
            }
            
            if(majorKeyInts[x][y] >= 12) {
                majorKeyInts[x][y] -= 12;
            }
        // MINOR
            if(y == 2 || y == 5) { // semi tones 
                minorKeyInts[x][y] = minorKeyInts[x][y - 1] + 1;
            }
            else {
                minorKeyInts[x][y] = minorKeyInts[x][y - 1] + 2;   
            }
            
            if(minorKeyInts[x][y] >= 12) {
                minorKeyInts[x][y] -= 12;
            }
        }
    }

    // converting to letters
    for(int x = 0; x < 12; x++) {
        for(int y = 0; y < 7; y++) {
            
            //major
            switch(majorKeyInts[x][y]) {
                case 0: 
                    majorScales[x][y] = "A";
                break;
                case 1:
                    majorScales[x][y] = "A#";
                break;
                case 2:
                    majorScales[x][y] = "B";
                break;
                case 3:
                    majorScales[x][y] = "C";
                break;
                case 4:
                    majorScales[x][y] = "C#";
                break;  
                case 5:
                    majorScales[x][y] = "D";
                break;
                case 6:
                    majorScales[x][y] = "D#";
                break;
                case 7:
                    majorScales[x][y] = "E";
                break;
                case 8:
                    majorScales[x][y] = "F";
                break;
                case 9:
                    majorScales[x][y] = "F#";
                break;
                case 10:
                    majorScales[x][y] = "G";
                break;
                case 11:
                    majorScales[x][y] = "G#";
                break;                   
            }
            // minor
            switch(minorKeyInts[x][y]) {
                case 0: 
                    minorScales[x][y] = "A";
                break;
                case 1:
                    minorScales[x][y] = "A#";
                break;
                case 2:
                    minorScales[x][y] = "B";
                break;
                case 3:
                    minorScales[x][y] = "C";
                break;
                case 4:
                    minorScales[x][y] = "C#";
                break;  
                case 5:
                    minorScales[x][y] = "D";
                break;
                case 6:
                    minorScales[x][y] = "D#";
                break;
                case 7:
                    minorScales[x][y] = "E";
                break;
                case 8:
                    minorScales[x][y] = "F";
                break;
                case 9:
                    minorScales[x][y] = "F#";
                break;
                case 10:
                    minorScales[x][y] = "G";
                break;
                case 11:
                    minorScales[x][y] = "G#";
                break;                   
            }
        }
    }

    // assigning the scales major, minor, or diminshed chords based on the degree
    for(int x = 0; x < 12; x++) {
        for(int y = 0; y < 7; y++) {
            switch(y) { // MAJOR
                case 0:
                case 3:
                case 4:
                    majorScales[x][y] += "Major";
                break;
                
                case 6:
                    majorScales[x][y] += "Dim";
                break;

                default:
                    majorScales[x][y] += "Minor";
            }
            switch(y) { // MINOR
                case 2:
                case 5:
                case 6:
                    minorScales[x][y] += "Major";
                break;

                case 1:
                    minorScales[x][y] += "Dim";
                break;

                default:
                    minorScales[x][y] += "Minor";
            }
        }
    }

    int numChords = -1;

    // getting the chords from the user
    cout << "How many chords do have?\n\t# chords = ";
        cin >> numChords; 

    // creating an array based on the chords
    cout << "Enter the chords one at a time. Indicate whether the chord is major, minor, or diminshed..." << endl;
    cout << "\tFor example E minor would be entered like EMinon, EMajor, EDiminsihed" << endl;
    cout << "You must enter more than two chords to get an accurate Key" << endl;
    
    int counter = 0;
    string userChords[numChords];

    // Getting users chords
    while(counter < numChords) {
        cout << "Chord: ";
            cin >> userChords[counter];
        counter++;  
    }
    
    // Displaying results
    cout << endl << endl << "Possible Keys...\n\n";

    int key_countMajor = 0;        // occurance counters for major and minor
    int key_countMinor = 0; 
    int minor_intTrack[numChords]; // keeps track of degrees in minor
    int major_intTrack[numChords];

    // going thru each major key
    for(int x = 0; x < 12; x++) {
        key_countMajor = 0;
        key_countMinor = 0;
        
        // re-initalizing so it is fresh 
        for(int w = 0; w < numChords; w++) {
            minor_intTrack[w] = -1;
            major_intTrack[w] = -1;
        }

        // iterating the scale degrees
        for(int y = 0; y < 7; y++) {

            // iterating each scale over the users info
            for(int z = 0; z < numChords; z++) {
                // MAJOR occurance found
                if(userChords[z] == majorScales[x][y]) {
                    major_intTrack[key_countMajor] = y + 1;
                    key_countMajor++;
                }
                // MINOR occurance found
                if(userChords[z] == minorScales[x][y]) {
                    minor_intTrack[key_countMinor] = y + 1;
                    key_countMinor++;
                }
            }
        }

        // if there is more than one match in each key we display the key with the degrees 
        if(key_countMajor > 1) {
            cout << "\t" << majorScales[x][0]  << " occurances: " << key_countMajor << endl << "\t\tDegrees: ";

            for(int w = 0; w < numChords; w++) {
                if(major_intTrack[w] != -1) {
                    cout << major_intTrack[w] << " ";
                }
            }
            cout << endl;
        }
        if(key_countMinor > 1) {
            cout << "\t" << minorScales[x][0]  << " occurances: " << key_countMinor << endl << "\t\tDegrees: ";

            for(int w = 0; w < numChords; w++) {
                if(minor_intTrack[w] != -1) {
                    cout << minor_intTrack[w] << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}