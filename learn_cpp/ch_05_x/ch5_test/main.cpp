#include <iostream>
#include <string>
#include <string_view>

std::string_view getQuantityPhrase(int x)
{
    if (x == 2)
    {
        return ("a couple of");
    }
    if (x == 1)
    {
        return ("a single");
    }
    if (x < 0)
    {
        return ("negative");
    }
    if (x == 0)
    {
        return ("no");
    }
    if (x == 3)
    {
        return ("a few");
    }
    return ("many");
    
}

constexpr std::string_view getApplesPluralized(int x)
{
    return (x == 1) ? "apple" : "apples";
}

int main()
{
    constexpr int maryApples{ 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}

/*std::string getName(int num)
{
    std::cout << "Enter the name of person #" << num << ": ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    return name;
}

int getAge(std::string_view sv)
{
    std::cout << "Enter the age of " << sv << ": ";
    int age{};
    std::cin >> age;

    return age;
}

void printOlder(std::string_view name1, int age1, std::string_view name2, int age2)
{
    if (age1 > age2)
        std::cout << name1 << " (age " << age1 << ") is older than " << name2 << " (age " << age2 << ").\n";
    else
        std::cout << name2 << " (age " << age2 << ") is older than " << name1 << " (age " << age1 << ").\n";
}

int main()
{
    const std::string name1{ getName(1) };
    const int age1{ getAge(name1) };

    const std::string name2{ getName(2) };
    const int age2{ getAge(name2) };

    printOlder(name1, age1, name2, age2);

    return 0;
}*/