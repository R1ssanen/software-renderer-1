#include <sr1.h>

int main(unused int argc, unused char** argv) {

    LINFO("Starting testing application.");

    CreateApp((void*)0);
    RunApp();
    DestroyApp();

    return 0;
}
