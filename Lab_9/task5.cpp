#include <fstream>

int task5()
{
    std::ofstream file;
    file.open("Cat.txt");
   file<<" _ "<<'\n';
    file<<"( \\"<<'\n';
    file<<" ) ) "<<'\n';
    file<<"( (  .-''''-.  A.-.A"<<'\n';
    file<<" \\ \\/        \\/ , , \\"<<'\n';
    file<<"  \\  \\       =;  t  /="<<'\n';
    file<<"   \\  |''''.   ',--'"<<'\n';
    file<<"   / //    |  ||"<<'\n';
    file<<"  /_,))    |_,))"<<'\n';
    return 1;
}
