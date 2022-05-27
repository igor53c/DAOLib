#include "PostleitzahlenDAO.h"


PostleitzahlenDAO::PostleitzahlenDAO()
{

}

bool PostleitzahlenDAO::insertPostleitzahl(const QString &PLZ, const QString &Ort)
{
    QString SQL = "INSERT INTO POSTLEITZAHLEN ";
    SQL += "(PLZ, ORT) ";
    SQL += "VALUES (";
    SQL += DAOLib::dbString(PLZ) + ", ";
    SQL += DAOLib::dbString(Ort) + ")";

    return DAOLib::executeNonQuery(SQL) > 0;
}

bool PostleitzahlenDAO::postleitzahlExists(const QString &PLZ, const QString &Ort)
{
    QString SQL = "SELECT COUNT(*) FROM POSTLEITZAHLEN ";
    SQL += "WHERE PLZ = " + DAOLib::dbString(PLZ);
    SQL += " AND ORT = " + DAOLib::dbString(Ort);

    bool OK;

    QVariant count = DAOLib::executeScalar(SQL, OK);

    if(!OK)
        return false;

    return count.toInt() > 0;
}

