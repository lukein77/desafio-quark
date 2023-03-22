#ifndef _IVIEW_H_DEFINED_
#define _IVIEW_H_DEFINED_

#include <string>

// Define la interfaz para la vista.
class IView {
    public:
        virtual void print(const std::string &text) = 0;
        virtual void showMainMenu() = 0;
};

#endif  // _IVIEW_H_DEFINED_