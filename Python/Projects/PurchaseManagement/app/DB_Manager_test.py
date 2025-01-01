import mysql.connector as mysql
from mysql.connector import errorcode
# from mysql import errorcode

# DataBase configuration
DB_CONFIG = {
    "host": "localhost",
    "user": "oleg",
    "password": "!$Aug1987",
    "database": "Purchasesdb"
}

# DATABASE_NAME = "Purchasesdb"
# TABLE_NAME = "Purchases"

try:
    # mydb = mysql.connector.connect(**DB_CONFIG)
    mydb = mysql.connect(**DB_CONFIG)
    print("Connected Successfully")
except mysql.connector.Error as err:
    if err.errno == errorcode.ER_ACCESS_DENIED_ERROR:
        print("Access denied: Incorrect username or password")
    elif err.errno == errorcode.ER_BAD_DB_ERROR:
        print("Database does not exist")
except Exception as e:
    print(e)
    print("Failed to connect")
finally:
    if 'mydb' in locals() and mydb.is_connected():
        mydb.close()
        print("Connection closed")