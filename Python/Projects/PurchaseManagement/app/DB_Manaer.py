import mysql.connector
from mysql.connector import Error
from .models import PurchasesTable, TypeTable
# import pymysql
# from pymysql.connector import Error


class DatabaseManager:
    def __init__(self, host, user, password, database):
        self.host = host
        self.user = user
        self.password = password
        self.database = database
        self.connection = None
        self.__Create_Tables()
        # self.connect()  # Automatically connect when an instance is created

    def __Create_Tables(self):
        if self.connect():
            cursor = self.connection.cursor()
            typeTable_creater = TypeTable.get_create_statement()
            cursor.execute(typeTable_creater)
            
            cursor.execute(f"SELECT COUNT(*) FROM {TypeTable.TABLE_NAME}")
            result = cursor.fetchone()
            
            if result[0] == 0:
                cursor.execute(TypeTable.default_query)
                cursor.execute(f"SELECT Id FROM {TypeTable.TABLE_NAME}")
                defualt_id = cursor.fetchone()
                
                purchasTable_creater = PurchasesTable.get_create_statement()
                purchasTable_creater.replace('type_id INT DEFAULT 0' , 
                                             f"type_id INT DEFAULT {defualt_id[0]}")
                cursor.execute(purchasTable_creater)
            self.close_connection()            
    
    def connect(self):
        try:
            self.connection = mysql.connector.connect(
                host=self.host,
                user=self.user,
                password=self.password,
                database=self.database
            )
            if self.connection.is_connected():
                print("Connected to the database")
                
                return True
        except Error as e:
            print(f"Error during connection: {e}")
        return False

    def execute_query(self, query, params=None):
        cursor = self.connection.cursor()
        try:
            cursor.execute(query, params)
            self.connection.commit()
            print("Query executed successfully")
        except Error as e:
            print(f"Error executing query: {e}")
            self.connection.rollback()
        finally:
            cursor.close()

    def fetch_query(self, query, params=None):
        cursor = self.connection.cursor(dictionary=True)
        try:
            cursor.execute(query, params)
            result = cursor.fetchall()
            return result
        except Error as e:
            print(f"Error fetching query: {e}")
            return None
        finally:
            cursor.close()

    def close_connection(self):
        if self.connection.is_connected():
            self.connection.close()
            print("Connection closed")
    
    def GetAllTable(self, table_name):
        if self.connection.is_connected():
            cursor = self.connection.cursor()
            query = f"SELECT * FROM {table_name}"
            try:
                cursor.execute(query)
                rows = cursor.fetchall()
                cursor.close()
                return  rows
            except Error as e:
                print(f"Error GetAllTable: {e}")
            finally:
                cursor.close()
    
    def DeleteTable(self,table_name):
        if self.connection.is_connected():
            query = f"DROP TABLE {table_name}"
            cursor = self.connection.cursor()
            try:
                cursor.execute(query)
            except Error as e:
                print(f"Error Delete table : {e}")
            finally:
                cursor.close()
    
    def DeleteAllTable(self):
        if self.connection.is_connected():
           
            table_names = self.GetAllTableNames()
           
            cursor = self.connection.cursor()
            
            cursor.execute("SET FOREIGN_KEY_CHECKS = 0;")
            
            for table_name in table_names:
                query = f"DROP TABLE {table_name[0]}"
                cursor.execute(query)
                print(f"Table {table_name[0]} DELETED.")
            
            cursor.execute("SET FOREIGN_KEY_CHECKS = 1;")           
    
    def GetAllTableNames(self):
        if self.connection.is_connected():
            cursor = self.connection.cursor()
            query = "SHOW TABLES"
            try:
                cursor.execute(query)
                names = cursor.fetchall()
                cursor.close()
                return names
            except Error as e:
                print(f"Error Get Table names : {e}")
            finally:
                cursor.close()
# Example usage:
if __name__ == "__main__":
    try:
        db_manager = DatabaseManager(host="localhost", user="root", password="password", database="my_database")
        db_manager.execute_query("CREATE TABLE IF NOT EXISTS users (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(100), age INT)")
        db_manager.execute_query("INSERT INTO users (name, age) VALUES (%s, %s)", ("Alice", 30))
        users = db_manager.fetch_query("SELECT * FROM users")
        print(users)
    finally:
        db_manager.close_connection()
