#ifndef _VIEW_H_DEFINED_
#define _VIEW_H_DEFINED_

#include "Presenter.h"
#include <string>

class View {
    private:
        Presenter *_presenter;
        void waitForKey(bool showMessage = false);
        void ignoreLine();
        void showHeader();
        void showSellerHistory();
        void showGarmentList();
        void showQuotationMenu();
        void makeQuotation(int garmentCode);
        int getInteger();
        double getDouble();
    public:
        View();
        ~View() { delete _presenter;}
        void print(const std::string &text, bool newline = true) override;
        void showMainMenu();
};

#endif // _VIEW_H_DEFINED_