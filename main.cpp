#include <SFML/Graphics.hpp>
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main()
{
    LOG(INFO) << "Game start";

    return 0;
}
