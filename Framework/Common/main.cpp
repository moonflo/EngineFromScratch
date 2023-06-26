#include <stdio.h>
#include "IApplication.hpp"

namespace My {
// Global varience, a pointer of an application
extern IApplication* g_pApp;
}  // namespace My

int main(int argc, char** argv) {
    int ret;

    if ((ret = My::g_pApp->Initialize()) != 0) {
        printf("App Initialize failed, will exit now.");
        return ret;
    }

    while (!My::g_pApp->IsQuit()) {
        My::g_pApp->Tick();
    }

    My::g_pApp->Finalize();

    return 0;
}
// In this branch, set floder-common's files as lib by using "add_libraries" in
// cmakelists.txt, and when generate exe in empty, we link this lib file.