#ifndef _VIEW_H_DEFINED_
#define _VIEW_H_DEFINED_

#include "IView.h"
#include <string>

class Presenter;

class View : public IView {
    private:
        Presenter *_presenter;
        void waitForKey();
    public:
        View();
        ~View() {}
        void print(const std::string &text);
        void showHeader();
        void showMainMenu();
};

#endif // _VIEW_H_DEFINED_