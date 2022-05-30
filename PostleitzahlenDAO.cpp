#include "PostleitzahlenDAO.h"


PostleitzahlenDAO::PostleitzahlenDAO(){}

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

int PostleitzahlenDAO::getRowCount()
{
    QString SQL = "SELECT COUNT(*) FROM POSTLEITZAHLEN ";

    bool OK;

    QVariant count = DAOLib::executeScalar(SQL, OK);

    if(!OK)
        return 0;

    return count.toInt();
}

void PostleitzahlenDAO::deleteTable()
{
    // QString SQL = "DELETE FROM POSTLEITZAHLEN";

    QString SQL = "TRUNCATE TABLE POSTLEITZAHLEN";

    DAOLib::executeNonQuery(SQL);
}

QSqlTableModel *PostleitzahlenDAO::readPLZIntoTableModel()
{
    QSqlTableModel* tableModel = new QSqlTableModel(nullptr, DAOLib::getDatabaseConnection());

    tableModel->setTable("POSTLEITZAHLEN");

    tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    tableModel->select();

    return tableModel;
}

