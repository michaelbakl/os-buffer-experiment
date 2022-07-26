## Program for copying from standard input device to standard output device.

### The purpose of this program is to find out which buffer size is more appropriate for using in operational systems. 

### To run this program use:

First compile this program via `g++ main.cpp -o 'compiledFileName'` in command line

Second in command line run `time ./'compiledFileName' size < fileToRead > fileToWrite'`
where `size` is the buffer size (512, 1024 etc.), `fileToRead` is a file to read from for experiment, `fileToWrite` is a file which will be created (a copy of the `fileToRead`)

Note: `fileToRead` must be created and filled beforehand


By running `time ...` in command line you will find out the amount of cycles, clock time, user CPU time and system CPU time 