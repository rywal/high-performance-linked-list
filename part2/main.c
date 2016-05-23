#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include "linked_list2.h"

//
// Machine Problem 2
// CSCE 313-501
// Base code provided by Texas A&M University
// Edited by Ryan Walters and Garrett Haynes
// September 20, 2015
//

int main(int argc, char ** argv) 
{
	int b = 128;
	int M = b * 16;  // so we have space for 4 items in each of the lists
	int t = 16;		// 4 tiers
    int opt;
    
    while ((opt = getopt(argc, argv, "b:s:t:")) != -1) {
        switch (opt) {
            case 'b':
                b = atoi(optarg);
                break;
            case 's':
                M = atoi(optarg);
                break;
            case 't':
                t = atoi(optarg);
                if(t <= 0){
                    printf("Number of tiers must be 1 or more. Using default of 16\n");
                    t = 16;
                }

                break;
            default:
                b = 128;
                M = b*1024;
                t=16;
        }
    }
	
	char buf [1024];
	memset (buf, 1, 1024);		// set each byte to 1
	
	char * msg = "a sample message";
	
	Init (M, b, t); // initialize
	// test operations
	int testnums [] = {0, 1<<29, (1<<29) + 5, 50, (1<<30) + 5, (1<<30) - 500};
	int i = 0;
	// some sample insertions
	for (i=0; i < 10; i ++)
	{
		Insert (testnums [i], buf, 50);   // insert 50 bytes from the buffer as value for each of the insertions
	}
    printf("\n\nList:\n");
	PrintList ();
		
	// end test operations	
	Destroy ();
	
}
