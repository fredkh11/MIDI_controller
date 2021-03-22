/*
This is an example of the "ButtonMatrix" class of the MIDI_controller library.
Connect a 4 × 3 matrix of buttons with the rows to pins 2, 3, 4 and 5, 
and the columns to pins 6, 7 and 8.
Pull-up resistors are not necessary, because the internal ones will be used. 

If you want to be able to press multiple buttons at once, add a diode 
in series with each button, as shown in the schematic on the Wiki:
https://github.com/tttapa/MIDI_controller/wiki/Hardware

The note numbers are specified in the 'addresses' array.
Map accordingly in your DAW or DJ software.

Written by tttapa, 24/09/2017
https://github.com/tttapa/MIDI_controller
*/

#include "MIDI_Controller.h" // Include the library

const uint8_t velocity = 0b1111111; // Maximum velocity (0b1111111 = 0x7F = 127)
const uint8_t addresses[14][8] = {   // the note numbers corresponding to the buttons in the matrix
  {1,2,3,4,5,6,7,8,9,10,11,12,13,14},
  {15,16,17,18,19,20,21,22,23,24,25,26,27,28},
  {29,30,31,32,33,34,35,36,37,38,39,40,41,42},
  {43,44,45,46,47,48,49,50,51,52,53,54,55,56},
  {57,58,59,60,61,62,63,64,65,66,67,68,69,70},
  {71,72,73,74,75,76,77,78,79,80,81,82,83,84},
  {85,86,87,88,89,90,91,92,93,94,95,96,97,98}
}

// Create a new instance of the class 'ButtonMatrix', called 'buttonmatrix', with dimensions 4 rows and 3 columns, with the rows connected to pins 2, 3, 4 and 5
// and the columns connected to pins 6, 7 and 8, that sends MIDI messages with the notes specified in 'addresses' on MIDI channel 1, with velocity 127
ButtonMatrix<14, 8> buttonmatrix({2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, {15, 16, 17, 18, 19, 20, 21}, addresses, 1, velocity);

void setup() {}

void loop() {
  // Refresh the buttons (check whether the states have changed since last time, if so, send it over MIDI)
  MIDI_Controller.refresh();
}
