# Putting-Stuff-In-C

## Putting stuff in C just to prove to myself that I can.

Silly 'lil personal project to test my knowledge of object oriented stuff I've learned as well as learning more about how C gets compiled and libraries and all that good stuff.

Currently, only some basic data structures have bene implemented, and my plans for this are generally "If I think something is cool and I think that I can add it to C, I probably will for fun." My implementation of these data structures focuses more on flexibility than safety, so using them might be an issue. But, in general: 

## Data Structure Structure
The data structures I've implemented use void pointers so you can put anything in, and it stores a pointer to a copy of the data. So if you pass in strings, it'll store void pointers to strings in memory. Thus, it is up to the user to keep track of what they are passing in and the type they are passing in. I've implemented it this way because it is more flexible for the user despite being less safe.

##TO-DO
* Make function names less tragic
* Finish hash map
* Add event handling
