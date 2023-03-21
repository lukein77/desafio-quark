#ifndef _VIEW_H_DEFINED_
#define _VIEW_H_DEFINED_

#include <windows.h>

#include <string>

class View {
    private:
        void waitForKey();
    public:
        View();
        ~View() {}
        void print(const std::string &text);
        void showMainMenu();
};

#endif // _VIEW_H_DEFINED_