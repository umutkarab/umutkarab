//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fibonacci(int n)
{
    int previousFib = 0; /// it was 1, I made it 0
    int currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 0; i <= n-2; i++) // it was i <= n , I  made it n-2
    {
        int newFib = previousFib + currentFib ;
        previousFib = currentFib ; /// it was newFib, I made it currentFib
        currentFib = newFib ; /// it was previousFib, I made it newFib
    }
    return currentFib ;
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    for (int i = 0; i <= 42 ; i ++) /// i was 1, I made it 0
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    return 0;
}
