#include<stdio.h>

// a little bit of masking and byte printing
#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBINARY(byte)  \
  (byte & 0x80 ? 1 : 0), \
  (byte & 0x40 ? 1 : 0), \
  (byte & 0x20 ? 1 : 0), \
  (byte & 0x10 ? 1 : 0), \
  (byte & 0x08 ? 1 : 0), \
  (byte & 0x04 ? 1 : 0), \
  (byte & 0x02 ? 1 : 0), \
  (byte & 0x01 ? 1 : 0) 

int main(int argc, char *argv[])
{
    int numbers[4] = {0, 'g'};
    char name[4] = {'a', 9, 'a', 'a'};

    // first, print them out raw
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);

    printf("name each: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);

    printf("name: %s\n", name);

    // setup the numbers
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    // setup the name
    name[0] = 'Z';
    name[1] = 'e';
    name[2] = 'd';
    name[3] = '\0';
    
    // alternate name as integer (4 bytes = 4 chars)

    //name[0] = 

    // then print them out initialized
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);

    
    // then print them out initialized
    printf("name in nums: %d %d %d %d\n",
            name[0], name[1],
            name[2], name[3]);

    int i = 0;
    // then print them out initialized
    printf("name in bits\n");
    for(; i < 4; i++){
        printf("name[%d]: "BYTETOBINARYPATTERN"\n", 
            i, BYTETOBINARY(name[i]));
    }
   
    // print the string Zed/0 as a integer
    // address pointer pointing to name[0] cast as an integer pointer
    printf("dat integer = %d \n", *((int *) &name[0]));

    printf("name each: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);

    // print the name like a string
    printf("name: %s\n", name);

    // another way to use name
    char *another = "Zed";

    printf("another: %s\n", another);

    printf("another each: %c %c %c %c\n",
            another[0], another[1],
            another[2], another[3]);

    return 0;
}
