#include <cstdio>
#include <stdexcept>

struct CyberdyneSeries800 {
    CyberdyneSeries800(){
        printf("I'm a friend of Sarah Corner\n");
    }
    ~CyberdyneSeries800(){
        throw std::runtime_error {"I'll be back."};
    }
};

int main(){
    try{
        CyberdyneSeries800 t800;
        throw std::runtime_error {"Come with me if you want to live."};
    }
    catch (const std::exception& e){
        printf("Caught exception: %s\n", e.what());
    }
}

/* NOTES

First, you declare the CyberdyneSeries800 class, which has a simple constructor
that prints a message ➊ and a thoroughly belligerent destructor that throws an uncaught
exception ➋. Within main, you set up a try block where you initialize a 
CyberdyneSeries800 called t800 ➌ and throw a runtime_error ➍. Under better 
circumstances, the catch block ➎ would handle this exception, print its 
message ➏, and exit gracefully. Because t800 is an automatic variable within 
the try block, it destructs during the normal process of finding a handler for 
the exception you’ve thrown ➍. And because t800 throws an exception in its 
destructor ➋, your program invokes std::terminate and ends abruptly.
As a general rule, treat destructors as if they were noexcept.

*/