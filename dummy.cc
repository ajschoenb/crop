#include <iostream>
#include <cstring>

void magic() {
    char buf[20];

    scanf("%s", buf);

    std::cout << "You said: " << buf << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "Hello, world!" << std::endl;

    magic();

    return 0;
}
