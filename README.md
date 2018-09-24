# Music

This is a short program I wrote that accepts chords as input from the user. 
The program then outputs the possible keys that the set of chords it is in. 
Since it is possible to interpret which key the chords completely different than someone else, the code output all possible keys. 
A possible way to distinguish which key the chords are in is to list the degrees in the scale.
For example, if the user enters in EMajor, AMajor, and BMajor, the most likely key is EMjaor because the degrees in the scale are 1 4 5. And unlikey in the key of F#Minor with a 3 7 degree match.

This is useful for both transcribing music and writing your own. 

For example, you like two chords that go together, but do not know what key to play in. You enter the chords into this program and the code will give you many possible ways to use those chords in a key.


Instructions:
- Download the source code and compile it
- Entering Input
  - Enter the number of chords you have
  - The screen will prompt you for the chords
  - You must enter the chord in the follwing way: (Capital Letter of chord)(Major/Minor/Diminished)
  - for example all forms of the e chord would be entered like: EMajor, EMinor, EDim 
- Interpretting Data
  - The program will spit out all of the possible keys
  - The keys will also have the degrees of the chord in the current scale
  
