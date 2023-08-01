// Tower of Hanoi Solver in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>

// Function to solve the Tower of Hanoi puzzle
void towerOfHanoi(int n, char source, char destination, char auxiliary) 
{
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", source, destination);
        return;
    }

    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from peg %c to peg %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int numDisks;
    printf("Enter the number of disks in the Tower of Hanoi: ");
    scanf("%d", &numDisks);

    towerOfHanoi(numDisks, 'A', 'C', 'B');

    return 0;
}
