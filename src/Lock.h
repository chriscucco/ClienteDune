#include <iostream>
#include <vector>
#include <thread>
#include <mutex>


//Clase Lock RAII, mediante la cual puedo bloquear y desbloquear el mutex
class Lock {
private:
    std::mutex &m;

public:      
    explicit Lock(std::mutex &m);
    ~Lock();
};
