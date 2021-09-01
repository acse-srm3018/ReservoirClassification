#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <Windows.h>

#pragma comment (lib, "User32.lib")

#define pressKey(key)    keybd_event(key,0,0,0)
#define releaseKey(key)   keybd_event(key,0,KEYEVENTF_KEYUP,0)
#define doKey(key) \
{ \
    pressKey(key); \
    releaseKey(key); \
}
#define A	    doKey(0x41);
#define B	    doKey(0x42);
#define C	    doKey(0x43);
#define D	    doKey(0x44);
#define E	    doKey(0x45);
#define F	    doKey(0x46);
#define G	    doKey(0x47);
#define H	    doKey(0x48);
#define I	    doKey(0x49);
#define J	    doKey(0x4A);
#define K	    doKey(0x4B);
#define L	    doKey(0x4C);
#define M	    doKey(0x4D);
#define N	    doKey(0x4E);
#define O	    doKey(0x4F);
#define P	    doKey(0x50);
#define Q	    doKey(0x51);
#define R	    doKey(0x52);
#define S	    doKey(0x53);
#define T	    doKey(0x54);
#define U	    doKey(0x55);
#define V	    doKey(0x56);
#define W	    doKey(0x57);
#define X	    doKey(0x58);
#define Y	    doKey(0x59);
#define Z	    doKey(0x5A);

#define F1      doKey(VK_F1);
#define F2      doKey(VK_F2);
#define F3      doKey(VK_F3);
#define F4      doKey(VK_F4);
#define F5      doKey(VK_F5);
#define F6      doKey(VK_F6);
#define F7      doKey(VK_F7);
#define F8      doKey(VK_F8);
#define F9      doKey(VK_F9);
#define F10     doKey(VK_F10);
#define F11     doKey(VK_F11);
#define F12     doKey(VK_F12);

#define TAB     doKey(VK_TAB);
#define ENTER   doKey(VK_RETURN);
#define ALT     doKey(VK_MENU);
#define CTRL    doKey(VK_CONTROL);
#define SHIFT   doKey(VK_SHIFT);
#define ESCAPE  doKey(VK_ESCAPE);

#define UP_Arrow      doKey(VK_UP   );
#define DOWN_Arrow    doKey(VK_DOWN );
#define LEFT_Arrow    doKey(VK_LEFT );
#define RIGHT_Arrow   doKey(VK_RIGHT);

#define ALT_Key(key) {pressKey(VK_MENU);key;releaseKey(VK_MENU);}
#define CTRL_Key(key) {pressKey(VK_CONTROL);key;releaseKey(VK_CONTROL);}
#define SHIFT_Key(key) {pressKey(VK_SHIFT);key;releaseKey(VK_SHIFT);}

//void setNativeClipboard(char * input)
//{
//    const size_t len = strlen(input) + 1;
//    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE, len);
//    memcpy(GlobalLock(hMem), input, len);
//    GlobalUnlock(hMem);
//    OpenClipboard(0);
//    EmptyClipboard();
//    SetClipboardData(CF_TEXT, hMem);
//    CloseClipboard();
//}

#endif // KEYBOARD_H
