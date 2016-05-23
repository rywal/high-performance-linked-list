# High performance linked list

Developed a high performance linked list that avoids interacting with the memory manager on a per-operation basis. To do this, we reserved a fixed amount of memory, referred to here as a Memory Pool(MP). Based on the basic block size, given as an argument, a certain number of items can be stored in the list. Insertions beyond the maximum limit will be rejected. A Head Pointer, pointing to the head of the list is kept. A Free Pointer, pointing to the point of next insertion is also kept.

*Structure*
Each item contains a header and a payload. The header contains pointer information for the next item(and previous for a doubly linked list implementation). The payload consists of a key-value pair where the key is a 4 byte integer and the value is of variable length, so long as it is within the maximum allowable size.

### Part 1

Part 1 implements a singly linked list in C. The program is to be run using `testlist [-b <blocksize, in bytes (default: 128 bytes)>] [-s <memsize, in bytes (default: 512 kB)>]`

### Part 2

Part 2 implements a multi-tiered linked list that groups keys into a number of disjointed intervals and keeps numbers from those intervals in separate lists. The program is to be run using `testlist2 [-b <blocksize, in bytes (default: 128 bytes)>] [-s <memsize, in bytes (default: 512 kB)>] [-t <tiers>]`

_Created as part of CSCE 313 at Texas A&M University_

Contributors:
* Ryan Walters
* Garrett Haynes
