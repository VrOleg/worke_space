

// We have a song machine with 10 songs. When the user uses the machine a random song is picked and
// a handle is executed. How would you implement it, what DS would you use?
// we want to make sure that every song is picked exactly once before we start again.How do we do it?

#include <iostream>
#include <vector>
#include <random>

class SongMachine
{
public:
    SongMachine(int capacity);
    void InsertSong(int song);
    int PlaySong();
    void PrintAllSongs();

private:
    std::vector<int> m_data;
    int m_size;
    int m_capacity;
    int m_playUpTo;

    void SwapeSongs(int &a, int &b);
};

SongMachine::SongMachine(int capacity) : m_size(0), m_capacity(capacity), m_playUpTo(-1)
{
}

void SongMachine::InsertSong(int song)
{
    if (m_capacity > m_size)
    {
        // m_data.push_back(song);
        m_data.insert(m_data.begin(), song);
        ++m_size;
        ++m_playUpTo;
    }
    else
    {
        std::cout << "the mashine is full and the song can't be insert!" << std::endl;
    }
}

int SongMachine::PlaySong()
{
    if (0 == m_size)
    {
        std::cout << " There is no song in machine!" << std::endl;
        return (-1);
    }

    if (0 == m_playUpTo)
    {
        std::cout << m_data[m_playUpTo];
        m_playUpTo = m_size - 1;
        return (m_data[0]);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, m_playUpTo);

    int randomValue = distrib(gen);

    // std::cout << "play song : " << m_data[randomValue] << std::endl;
    std::cout << m_data[randomValue];

    SwapeSongs(m_data[randomValue], m_data[m_playUpTo]);
    // --m_playUpTo;

    return (m_data[m_playUpTo--]);
}

void SongMachine::SwapeSongs(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SongMachine::PrintAllSongs()
{
    for (size_t i = 0; i < m_size; i++)
    {
        std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    SongMachine sm(10);

    sm.InsertSong(1);
    sm.InsertSong(2);
    sm.InsertSong(3);
    sm.InsertSong(4);
    sm.InsertSong(5);
    sm.InsertSong(6);
    sm.InsertSong(7);
    sm.InsertSong(8);
    sm.InsertSong(9);

    // sm.PrintAllSongs();

    for (size_t i = 0; i < 50; i++)
    {
        if (0 == i % 9)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << " ; ";
        }
        sm.PlaySong();
    }

    return (0);
}