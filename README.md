# MP3-Module

This library works for MP3 module sold @ [www.continentalee.com.sg](www.continentalee.com.sg).

**NOTE: SD card / USB must be plugged in before power on.**

**NOTE: Speaker must be connected before power on.**

## Functions:
```
void begin();						// Begin function
void send_cmd(uint8_t *cmd);		// Send command function
void select_file(uint16_t file);	// Select file
void play();						// Play
void pause();						// Pause
void next();						// Next track
void previous();					// Previous track
void stop();						// Stop track
void volume_up();					// Increase volume
void volume_down();					// Decrease volume
void volume(uint8_t vol);			// Set volume (0 - 30)
void eq(uint8_t eq);				// Set EQ (0 - NONE, 1 - POP, 2 - ROCK, 3 - JAZZ, 4 - CLASSIC, 5 - BASS)
void set_mode(uint8_t mode);		// Set mode (0 - ALL, 1 - FOLDER, 2 - ONE, 3 - RANDOM, 4 - ONE STOP)

int get_status();					// Get current status (0 - STOP, 1 - PLAY, 2 - PAUSE)
int get_volume();					// Get current volume (0 - 30)
int get_eq();						// Get current EQ (0 - NONE, 1 - POP, 2 - ROCK, 3 - JAZZ, 4 - CLASSIC, 5 - BASS)
int get_mode();						// Get current play mode (0 - ALL, 1 - FOLDER, 2 - ONE, 3 - RANDOM, 4 - ONE STOP)
int get_current_track_time();		// Get current playing track timing
int get_track_time();				// Get current total track timing
int get_response();
```

**All works developed by continentalee.**

**Please credit when you use this library in your project.**
