# Putting Stuff In ✨C✨

## Putting stuff in C just to prove to myself that I can.

Personal project to learn more about low-level programming as well as increasing my understanding of object-oriented concepts.

Currently, only some basic data structures have been implemented, and my plan for this is to eventually add more complex things. My implementation of these data structures focuses more on flexibility than safety, so using them might be an issue. But, in general: 

## Data Structure Structure
The data structures I've implemented use void pointers so you can put anything in, and it stores a pointer to a copy of the data. So if you pass in strings, it'll store void pointers to strings in memory. Thus, it is up to the user to keep track of what they are passing in and the type they are passing in. I've implemented it this way because it is more flexible for the user despite being less safe, and also because I think it tests my low-level programming knowledge a little bit more.

## TO-DO
* Add trees (binary trees, self balancing trees)
* Add Heaps/Priority Queues
* Add graphs (eventually)
* Add event handling(?)
* More testing (Specifically on hash map)
