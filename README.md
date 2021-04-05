
# Arduino MIDI controlled Glockenspiel
![Client Photo](https://github.com/bonnette/MIDI_Glockenspiel/blob/main/photos/IMG_3465.jpg)
<br/>
An automated Glockenspiel Arduino Project
Inspired by an Instructable
</br>
https://www.instructables.com/id/Making-the-Spielatron-Robotic-Glockenspiel/
</br>
See my AutoGlockenspiel repository</br>

This is a totally different interpertation and code.
</br></br>
This project uses a Windows PC to drive an Arduino which fires one of 32 solenoids that sit above each note.
</br></br>
The MIDI control of the hammers is controlled by an Arduino Pro Mini. the serial connetion between the Pi and the Arduino is accomplished through an FTDI interface. This interface allows music that has been converted to a MIDI file to be played on the Glockenspiel.
</br></br>
The Glockenspiel is a Pearl 32 note that I purchased off of Ebay for $45
</br></br>
There are two Arduino programs.</br>
The Spielatron_V2.ino file is the original application off of Instructables</br>
The Spielatron_mod.ino file has modifications of the rotation table for the hammers. This was necessary because my Glockenspiel is a different physical size.</br></br>
My Glockenspiels is larger and also has more notes (32 vs 25). Right now the modified program only use 25 of my 32 notes. I will in the future add more information to the hammer table which will allow me to use all of the 32 notes available.
</br></br>
I designed a holder for the hammer servos. I used FreeCad for the design. I have provided the FreeCad sources as well as the .stl files for the holder. The design allows you to set the Glockenspiel into the holder and it lifts the Glockenspiel up off the table about 5mm. I may have to make a few tweaks to the design.
