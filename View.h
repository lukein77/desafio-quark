#ifndef _VIEW_H_DEFINED_
#define _VIEW_H_DEFINED_

#include "IView.h"
#include <string>

class Presenter;

class View : public IView {
    private:
        Presenter *_presenter;
        void waitForKey(bool showMessage = false);
        void showHeader();
        void showQuotationMenu();
        void showShirtQuotationMenu();
        void showTrousersQuotationMenu();
    public:
        View();
        ~View() {}
        void print(const std::string &text);
        void showMainMenu();
};

#endif // _VIEW_H_DEFINED_