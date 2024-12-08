
//  We have have a function that returns a random number with 32 bits.
//  We want to use that function to get a number up to ‘n’. How to do it?

#include <iostream>
#include <random>

uint32_t GenerateRandom32Bit();
uint32_t RandomNumberUpToN(uint32_t n, uint32_t &rand);


int main(int argc, char *argv[])
{
    uint32_t rand;
    uint32_t result;
    std::string status;
    uint32_t n = 150;
    for (size_t i = 0; i < 50; i++)
    {
        result = RandomNumberUpToN(n,rand); 
       
       if(result < n)
       {
            status = "Success";
       }
       else
       {
            status = "Failed";
       }
       
        std::cout << "Rand 32 bit : " << rand << " Random up to n : " << result << " n: " << n << " " << status <<std::endl;  
    }
    

    return (0);
}


uint32_t RandomNumberUpToN(uint32_t n, uint32_t &rand)
{
    if(n == 0)
    {
        std::cout << "n can't be Zero!!!"<< std::endl;
        return (0);
    }
    
    do
    {
        rand = GenerateRandom32Bit();
    } while (rand >= UINT32_MAX - (UINT32_MAX % n));
    
    return (rand % n);
}

uint32_t GenerateRandom32Bit()
{
    // Use a random device to seed the generator
    std::random_device rd;

    // Create a 32-bit mersenne twister engine
    std::mt19937 gen(rd());

    // Define the range for 32-bit numbers
    std::uniform_int_distribution<uint32_t> dist(0, UINT32_MAX);

    // Generate and return the random number
    return dist(gen);
}

