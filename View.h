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
        void showSellerHistory();
        void showQuotationMenu();
        void makeQuotation(int garmentCode);
    public:
        View();
        ~View() {}
        void print(const std::string &text, bool newline = true) override;
        void showMainMenu();
};

#endif // _VIEW_H_DEFINED_