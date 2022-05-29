#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <limits>


class Song
{
    friend std::ostream& operator<<(std::ostream& os, const Song& s);
    std::string name;
    std::string author;
    unsigned int rating;
public:
    Song()
        : name{"Unknown"}, author{"Uknown"}, rating{0} {}
    Song(const std::string& name, const std::string& author, const unsigned int& rating)
        : name{name}, author{author}, rating{rating} {}
    bool operator<(const Song& rhs)
    {
        return (this->name.compare(rhs.name)) < 0;
    }
    bool operator==(const Song& rhs)
    {
        return (this->name.compare(rhs.name)) == 0;
    }
};

std::ostream& operator<<(std::ostream& os, const Song& s)
{
    os << std::left 
        << std::setw(20) << s.name 
        << std::setw(30) << s.author 
        << std::setw(3) << s.rating;
    return os;
}

void display_list(const std::list<Song> l)
{
    std::cout << std::endl;
    std::for_each(l.begin(), l.end(),
        [](Song s){ std::cout << s << std::endl;});
}

void display_menu()
{
    std::cout << std::endl;
    std::cout << "F - Play First Song" << std::endl;
    std::cout << "N - Play Nest Song" << std::endl;
    std::cout << "P - Play Previous Song" << std::endl;
    std::cout << "A - Add and Play a new Song at curreny location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void display_playing(const Song& song)
{
    std::cout << "Playing:" << std::endl;
    std::cout << song << std::endl;
}

std::list<Song>::iterator& increment_iterator(
    std::list<Song>& songs, 
    std::list<Song>::iterator& it)
{
    if (++it == songs.end())
        it = songs.begin();
    return it;
}

std::list<Song>::iterator& decrement_iterator(
    std::list<Song>& songs, 
    std::list<Song>::iterator& it)
{
    if (it == songs.begin())
        it = songs.end();            
    it--;
    return it;
}

std::list<Song>::iterator& add_and_pay(
    std::list<Song>& songs, 
    std::list<Song>::iterator& it)
{
    std::string name;
    std::string author;
    unsigned int rating;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "\nAdding and playing the new the song";
    std::cout << "\nEnter the song name: ";
    std::getline(std::cin, name);
    std::cout << "Enter the song author: ";
    std::getline(std::cin, author);
    std::cout << "Enter the song rating: ";
    std::cin >> rating;
    songs.emplace(it, name, author, rating);
    return --it;
}

template <typename BaseIterator>
class CircularIterator
{
    BaseIterator begin;
    BaseIterator current;
    BaseIterator end;
public:
    CircularIterator(BaseIterator b, BaseIterator e, BaseIterator c)
        : begin{b}, current{c}, end{e} {}
    BaseIterator& get_current()
    {
        return this->current;
    }
    void operator++()
    {
        (this->current)++;        
        if (this->current == this->end)
            this->current = this->begin;
    }
    void operator++(int)
    {
        (this->current)++;
        if (this->current == this->end)
            this->current = this->begin;
    }
    void operator--()
    {        
        if (current == begin)
            current = end;
        current--;
    }
    void operator--(int)
    {
        if (current == begin)
            current = end;
        current--;
    
    }
    typename std::iterator_traits<BaseIterator>::value_type operator*()
    {
        return *(this->current);
    }
    void operator=(const BaseIterator& it)
    {
        this->current = it;
    }
};

int main()
{    
    std::list<Song> songs{
        {"New York", "Frank Sinatra", 5},
        {"God`s plan", "Drake", 4},
        {"Never be the same", "Camila Cabelo", 3},
        {"Pray for me", "The Weekend and K. Lamar", 4},
        {"Madonna", "Frozen", 5}
    };   
    display_list(songs);        

    while(1)
    {                
        // create iterator from list begin
        // static auto it = songs.begin();
        static CircularIterator<std::list<Song>::iterator> cIt {
            songs.begin(), 
            songs.end(), 
            songs.begin()};
        // display_playing(*it);
        display_playing(*cIt);
        display_menu(); 
        unsigned char cmd;
        std::cin >> cmd;
        // convert all to upper case
        cmd = std::toupper(cmd);
        switch(cmd)
        {
            case 'Q':
                return 0;
            case 'L':
                display_list(songs);
                break;
            case 'F':
                // it = songs.begin();                
                cIt = songs.begin();
                break;
            case 'N':
                // it = increment_iterator(songs, it);    
                cIt++;
                break;
            case 'P':
                // it = decrement_iterator(songs, it);
                cIt--;
                break;
            case 'A':
                // it = add_and_pay(songs, it);
                cIt = add_and_pay(songs, cIt.get_current());
                break;                
            default:
                std::cout << "Wrong command!" << std::endl;
                break;
        }
    }
    return 0;
}