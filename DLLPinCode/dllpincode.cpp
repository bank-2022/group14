#include "dllpincode.h"

void DLLPinCode::openDllDialog()
{
    objectDialog=new Dialog;
    objectDialog->exec();
    dllValue=objectDialog->getDialogValue();
    delete objectDialog;
}

QString DLLPinCode::returnFromDll()
{
    return dllValue;
}
