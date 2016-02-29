//
// Created by max on 2/29/2016.
//

#include <crtdbg.h>
#include "ListBox.h"
#include <iostream>
using namespace std;

void ListBox::add(LPARAM element) {
    // Get handle of listbox
    HWND hwndList1 = GetDlgItem(this->parentInstance, this->getId());
    _ASSERTE(hwndList1 != NULL);
    // Get actual text in buffer
    SendMessage(hwndList1, LB_ADDSTRING, (WPARAM) 0, (LPARAM) element );
}

void ListBox::remove() {
    // Get handle of listbox
    HWND hwndList1 = GetDlgItem(this->parentInstance, this->getId());
    _ASSERTE(hwndList1 != NULL);

    // Get current selection index in listbox
    int itemIndex = (int) SendMessage(hwndList1, LB_GETCURSEL, (WPARAM)0, (LPARAM) 0);
    if (itemIndex == LB_ERR)
    {
        // No selection
        return;
    }

    // Get length of text in listbox
    int textLen = (int) SendMessage(hwndList1, LB_GETTEXTLEN, (WPARAM) itemIndex, 0);

    // Allocate buffer to store text (consider +1 for end of string)
    TCHAR * textBuffer = new TCHAR[textLen + 1];

    // Get actual text in buffer
    SendMessage(hwndList1, LB_DELETESTRING, (WPARAM) itemIndex, (LPARAM) textBuffer );

    // Free text
    delete [] textBuffer;

    // Avoid dangling references
    textBuffer = NULL;
}

LPARAM ListBox::get(){
    // Get handle of listbox
    HWND hwndList1 = GetDlgItem(this->parentInstance, this->getId());
    _ASSERTE(hwndList1 != NULL);

    // Get current selection index in listbox
    int itemIndex = (int) SendMessage(hwndList1, LB_GETCURSEL, (WPARAM)0, (LPARAM) 0);
    if (itemIndex == LB_ERR)
    {
        // No selection
        return (LPARAM)"";
    }

    // Get length of text in listbox
    int textLen = (int) SendMessage(hwndList1, LB_GETTEXTLEN, (WPARAM) itemIndex, 0);

    // Allocate buffer to store text (consider +1 for end of string)
    TCHAR * textBuffer = new TCHAR[textLen + 1];

    // Get actual text in buffer
    SendMessage(hwndList1, LB_GETTEXT, (WPARAM) itemIndex, (LPARAM) textBuffer );

    return (LPARAM)textBuffer;
}