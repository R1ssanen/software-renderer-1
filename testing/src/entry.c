#include <sr1.h>
#include <string.h>

int main(unused int argc, unused char** argv) {
    LINFO("Starting testing application.");

    CreateApp(NULL);
    RunApp();
    DestroyApp();

    return 0;
}
