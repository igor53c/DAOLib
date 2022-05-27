#pragma once

#include "DAOLib.h"

class DAOLIB_EXPORT PostleitzahlenDAO
{
public:
    static bool insertPostleitzahl(const QString &PLZ, const QString &Ort);

    static bool postleitzahlExists(const QString &PLZ, const QString &Ort);

private:
    PostleitzahlenDAO();
};

