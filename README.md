
# Arduino MIDI controlled Glockenspiel
![Client Photo](https://github.com/bonnette/MIDI_Glockenspiel/blob/main/photos/IMG_3465.jpg)
<br/>
An automated Glockenspiel Arduino Project
Inspired by an Instructable
</br>
https://www.instructables.com/id/Making-the-Spielatron-Robotic-Glockenspiel/
</br>
See my AutoGlockenspiel repository for more information on my implementation of their project.</br>

This is a totally different interpretation.
</br></br>
This project uses a Windows PC to drive an Arduino which fires one of 32 solenoids that sit above each note.
</br></br>
The MIDI control of the solenoids is controlled by an Arduino Pro Mini. The serial connection between the Windows PC and the Arduino is accomplished through an FTDI interface. This interface allows music that has been converted to MIDI to be played on the Glockenspiel.
</br></br>
The Glockenspiel is a Pearl 32 note that I purchased off of Ebay for $45
</br></br>
There is only one Arduino software program. This program uses the Arduino midi library to decode each MIDI note received from the PC. Then using I2C it sets one of 32 pins distributed across two MCP23017 I/O expander boards to a "HIGH" which then fires a solenoid that then strikes a note on the glockenspiel.</br>
The current program allows only one note at a time to be played. The use of LMMS on the PC provides you with the opportunity to direct MIDI to the Arduino on one track while the other tracks play on the computer. This makes for a very pleasant experience in that, you can listen to the glockenspiel along with the accompanying instruments playing on the PC. 
</br></br>
I designed holders for the solenoids. These holders fit on the bottom rails of the glockenspiel and align the solenoids over the keys. There are five different holders. Each holder takes approximately 4 hours to print. The difference in the holders is their location on the glockenspiel. Three of the corner holders had to be modified in order to accommodate the glockenspiels support structure. 
</br></br>
A video of the glockenspiel playing a tune can be found here:</br>
https://youtu.be/QgNRVtduxMg
</br></br>
I used Fusion360 for the design of the solenoid holders and I thank Autodesk for allowing makers such as myself to use Fusion360 free of charge. Thanks Autodesk !</br>
I would also like to thank the developers of LMMS (https://lmms.io/) for their work.</br>
Thanks to hairless-midi (https://projectgus.github.io/hairless-midiserial/) for developing the Hairless MIDI Serial Bridge.</br>
and Tobias Erichsen for developing loopMIDI (https://www.tobias-erichsen.de/software/loopmidi.html).
