# UnsortedArrayGenerator

C++'s built-in randomization isn't exactly real randomization. While I'm still relatively new to learning the language, I wanted to create a program that properly generates random values, using runtime variation (which should vary based on the computer's performance, cpu usage, ram, etc.) in order to generate its seeds for randomization.

Ideally a proper randomization would be done using entropy measurements, since that's one of the best variable values we can extract from a computer in general, but I don't know enough about the language and how it interacts with OSs to extract values like that yet. Another easy improvement that I'm not familiar enough with the language to implement would be getting the current time, in milliseconds, since epoch, rather than the milliseconds since the start of the program's runtime- if you know how to get the epoch value in milliseconds, feel free to replace that initial time value for a better randomization form!

The intent of this program, other than providing a means of proper randomization, is to provide supplemental arrays and values to test cases of data structures that accept int input. The values are all nonnegative and unique, so test cases for negatives, duplicates, and extremely large values should still be implemented separately. Feel free to use for building your own test cases, or for any other use you want!
-Lucinder
