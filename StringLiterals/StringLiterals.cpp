// String Literals in C++
//

#include <iostream>
#include <string>

int main()
{
    const char* name = "Standa"; //immutable literal in const area CONST SEGMENT of exe. Zero ended. const good practise.
    //name[2] = 'L'; nelze
    //
    char  name2[] = "Petr"; //interne vznikne kopie do pole
    name2[1] = 'i';

    const wchar_t*  wt = L"Wide"; //2bytes windows 4bytes linux, mac
    const char16_t* ch16 = u"Petr";
    const char32_t* ch32 = U"Johana";

    //std::string str = "Me " + "you"; // nelze str literals 2 pointers
    std::string str =  std::string("Me ") + "you"; // now ok

    using namespace std::string_literals;
    std::string str2 = "Me "s + "you"; // viz pripona 's'

    //multiline
    const char* t1 = R"(jedna
    dve
    tri)";




    
}
