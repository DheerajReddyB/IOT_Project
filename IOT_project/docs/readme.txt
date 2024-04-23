1) Install the Thingspeak libray 
	https://www.arduinolibraries.info/libraries/thing-speak
	use zip uplaod option to load library in ide

2) Install all librares necessary ide components and prebuild libraries 

3) Structure the codebase 

	https://github.com/bremme/arduino-project
        https://github.com/asukiaaa/ThingSpeak_asukiaaa/blob/master/src/ThingSpeakWriter_asukiaaa.h
4) For developing own library  to structure the code create a folder library and under that create seperate 	folders for each of the new libaries 
	https://forum.arduino.cc/t/ide-cant-find-header-file-that-is-in-library-dir/599811/16
	
	+---Motor
	¦   ¦   .gitkeep
	¦   ¦   library.properties
	¦   ¦
	¦   +---src
	¦           Motor.cpp
	¦           Motor.h
	¦
	+---ThingspeakMine
	¦   ¦   library.properties
	¦   ¦
	¦   +---src
	¦           ThingspeakMine.cpp
	¦           ThingspeakMine.h
	
	
	Create a zip file of each of these libraries and load as mentioned in step 1
	Then include the .h header file in the ino files 

5) Other sensor integration 
https://randomnerdtutorials.com/esp32-thingspeak-publish-arduino/