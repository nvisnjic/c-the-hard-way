#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // can I mess with the input
    //

    argv[2] = "million";

    // go through each string in argv
    // why am I skipping argv[0]?
    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    int num_states = 6;

    int blah = 20;
    int buffer = 870;
    char *secret = {"secrety"};

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}