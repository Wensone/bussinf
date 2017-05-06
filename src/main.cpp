#include "../headers/BDcommunity.h"

int main(int argc, char **argv)
{
    BDcommunity base;
    if (argc < 2) base.menu();
    else base.console(argc, argv);

}