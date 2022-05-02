#include "myurl.h"


MyUrl::MyUrl()
{

}

QString MyUrl::getBase_url()
{
    return base_url;
}

QString MyUrl::base_url{
    "http://localhost:3000"
    //"http://ipv4.fiddler:3000"
};
