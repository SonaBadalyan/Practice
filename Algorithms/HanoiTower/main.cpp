#include <iostream>
#include <cmath>

void tower_of_hanoi(int disks_number,   char from_rod,
                                        char to_rod, 
                                        char mid_rod )
{
    if (disks_number == 1) 
    { 
        std::cout << "Move disk 1 from rod " << from_rod << 
                            " to rod " << to_rod << std::endl; 
        return; 
    } 

    tower_of_hanoi(disks_number - 1, from_rod, mid_rod, to_rod); 

    std::cout << "Move disk " << disks_number << " from rod " << from_rod <<
                                " to rod " << to_rod << std::endl; 

    tower_of_hanoi(disks_number - 1, mid_rod, to_rod, from_rod);
}
int main()
{
    int disks_number = 3;
    int steps_count = std::pow(2, disks_number) - 1;

    std::cout << "Number of steps is " << steps_count << std::endl;

    tower_of_hanoi(disks_number, 'A', 'B', 'c');

    return 0;
}
