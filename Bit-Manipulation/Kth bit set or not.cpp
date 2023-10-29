// int bit = n >> k;: This line of code performs a right-shift operation on the integer variable n by k positions and stores the result in the variable bit. Let's break it down step by step:

// n is an integer variable.
// k is another integer variable, and it specifies the number of positions to shift n to the right.
// Right-shifting n by k positions means that you are moving each bit in the binary representation of n k positions to the right. 
//This is essentially a division by 2^k. For example, if n is 12 (binary: 1100) and k is 1, then bit will be 6 (binary: 0110).

// return bit & 1;: This line of code performs a bitwise AND operation between the variable bit and the constant 1. Here's what's happening:

// bit contains the result of the right-shift operation from step 1, which is effectively n shifted to the right by k positions.

// The binary representation of 1 is 0001.

// When you perform a bitwise AND operation between bit and 1, you are isolating the least significant bit (LSB) of bit. 
//This is because the AND operation with 1 will result in bit itself if its LSB is 1, and it will result in 0 if its LSB is 0.

// The return statement then returns the result of this bitwise AND operation.

    bool checkKthBit(int n, int k)
    {
        // Your code here
        // It can be a one liner logic!! Think of it!!
         int bit=n>>k;
        return bit&1;
    }
};
